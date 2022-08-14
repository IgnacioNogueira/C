#include "Utils.h"

int cmp_ent(const void *v1,const void *v2)
{
    return *((int*)v1)-*((int*)v2);
}

int cmp_ind(const void *v1,const void *v2)
{
    return ((tIndice*)v1)->clave - ((tIndice*)v2)->clave;
}

void imprimirConForma(void *info,unsigned tam,unsigned n, void * params)
{
    int *i = (int *) info;
    printf("%*s-%3d-\n",n*3,"",*i);

}

void imprimir(void *info,unsigned tam,unsigned n,void * params)
{
    int *i = (int *) info;
    printf("-%d-",*i);
}

void imprimirEnArchivo(const void *info,unsigned tamInfo,void *params,unsigned tamArch)
{
    const tProducto *dato = (tProducto *)info;
    FILE *fp = (FILE *)params;

    fprintf(fp,"%ld, %s %d/%d/%d %d %.2f",
                                             dato->idProducto,
                                             dato->descripcion,
                                             dato->fecUltAct.dia,
                                             dato->fecUltAct.mes,
                                             dato->fecUltAct.anio,
                                             dato->cantidad,
                                             dato->precioUnitario);
}

unsigned leerDesdeVectorEnteros(void **d, void *vec,unsigned pos,void *params)
{
    *d = malloc(sizeof(int));
    if(!*d)
        return 0;

    memcpy(*d,vec+(sizeof(int)*pos),sizeof(int));
    return sizeof(int);
}

unsigned leerDesdeArchivoArchivoBin(void **d,void *pf,unsigned pos,void *params)
{
    unsigned tam = *((int*)params);
    *d = malloc(tam);

    if(!*d)
        return 0;

    fseek((FILE*)pf,pos*tam,SEEK_SET);
    return fread(*d,tam,1,(FILE*)pf);
}

int cargarArchivoBinOrdenadoAbiertoBinBusq(tArbolBinBusq *p,FILE *pf, unsigned tamInfo)
{
    int cantReg;

    if(*p || !pf)
        return 0;

    fseek(pf,0L,SEEK_END);
    cantReg = ftell(pf)/tamInfo;

    return cargarDesdeDatosOrdenadosRec(p,pf,leerDesdeArchivoArchivoBin,0,cantReg-1,&tamInfo);
}

int cargarArchivoBinOrdenadoArbolBinBusq(tArbolBinBusq *p,const char * path,unsigned tamInfo)
{
    int cantReg;
    int r;

    FILE *fp = fopen(path,"rb");

    if(*p)
        return SIN_INICIALIZAR;

    if(!fp)
        return ERROR_ARCH;

    fseek(fp,0L,SEEK_END);
    cantReg = ftell(fp)/tamInfo;

    r = cargarDesdeDatosOrdenadosRec(p,fp,leerDesdeArchivoArchivoBin,0,cantReg-1,&tamInfo);

    fclose(fp);
    return r;
}

int cargarDesdeDatosOrdenadosRec(tArbolBinBusq *p,void *ds,
                                 unsigned (*leer)(void **, void *,unsigned, void * params),
                                 int li,int ls,void *params) //la teka está acá, nomás habría que poner lo del índice
{
    int m = (li+ls)/2;
    int r;

    if(li > ls) //esto lo que va a generar es una condición de corte, en el que cuando el li sea mayor que el derecho, es porque no hay que cargar más en el set de datos
        return TODO_BIEN;

    (*p) = (tNodoArbol *) malloc(sizeof(tNodoArbol));

    if(!*p || !((*p)->tamInfo = leer(&(*p)->info,ds,m,params)))
    {
        free(*p);
        return SIN_MEM;
    }

    (*p)->izq = (*p)->der = NULL;

    if( (r = cargarDesdeDatosOrdenadosRec(&(*p)->izq,ds,leer,li,m-1,params)) != TODO_BIEN)
        return r;

    return cargarDesdeDatosOrdenadosRec(&(*p)->der,ds,leer,m+1,ls,params);
}
int cargarDesdeDatOrdenArbolBinRec(tArbolBinBusq * p,void *ds, unsigned cantReg,
                                   unsigned (*leer)(void **,void *,unsigned,void * params),void * params)
{
    if(*p || !ds) //si ya se terminó de cargar, o no hay más datos/datos para cargar, sale
    {
        return 0;
    }

    return cargarDesdeDatosOrdenadosRec(p,ds,leer,0,cantReg-1,params);
}

/// 1 - Esta función es para cargarlo como venga del archivo, probablemente desordenado
int cargarIndiceArbolArch(const char *nombreArchivo,tArbolBinBusq *p,
                      int(*cmp)(const void *,const void*))
{
    int i = 0;
    tProducto prod;
    tIndice ind;
    FILE *fp;

    fp = fopen(nombreArchivo,"rb");

    if(!fp)
    {
        printf("\nNo se pudo abrir el archivo %s",nombreArchivo);
        return -1;
    }

    fread(&prod,sizeof(tProducto),1,fp);

    while(!feof(fp))
    {
        ind.clave = prod.idProducto;
        ind.pos = ++i;
        insertarEnArbBinBusqRec(p,&ind,sizeof(tIndice),cmp);
        fread(&prod,sizeof(tProducto),1,fp);
    }

    fclose(fp);
    return TODO_BIEN;
} //arbol queda desbalanceado


///2 - guarda el arbol que tiene los registros del archivo, en un nuevo archivo temporal en modo inorder. D
///Despues se prepara un arbol balanceado

int guardarArbolGeneradoArchTemp(tArbolBinBusq *p,void (*accion)(const void *dato,void *contexto))
{
    FILE *temp = fopen("temp.idx","wb");

    if(!temp)
        return -3;

    inOrderArchivos(p,accion,temp);
    fclose(temp);
    return TODO_BIEN;
}

void guardarRegIndiceArchivo(const void *dato, void *contexto)
{
    fwrite(dato,sizeof(tIndice),1,(FILE*)contexto);
}

void inOrderArchivos(tArbolBinBusq *p,void (*accion)(const void *dato, void *contexto),void *param)
{

    if(!*p)
        return;

    inOrderArchivos(&(*p)->izq,accion,param);
    accion((*p)->info,param); //va a guardar el reg indice en el archivo
    inOrderArchivos(&(*p)->der,accion,param);

}

///3 - Despues de esta funcion queda SOLO EL ARBOL, el archivo temporal se borra

int cargarArbolArchivoINDTemp(tArbolBinBusq *p,int (*cmp)(const void *,const void *))
{
    int cantReng;

    FILE *fp = fopen("temp.idx","rb");

    if(!fp)
        return 0;

    fseek(fp,0L,SEEK_END);
    cantReng = ftell(fp)/sizeof(tIndice);
    cantReng = cargarArbolArchivoINDTemp_Int(p,0,cantReng-1,fp,cmp);

    fclose(fp);
    unlink("temp.idx");
    return cantReng;
}

int cargarArbolArchivoINDTemp_Int(tArbolBinBusq *p,int li,int ls,FILE* archivo,
                                  int (*cmp)(const void *,const void *))
{
    int m = (li + ls)/2;
    tIndice ind;

    if(li > ls)
        return TODO_BIEN;

    fseek(archivo,m*sizeof(tIndice),SEEK_SET);
    fread(&ind,sizeof(tIndice),1,archivo);

    if(!insertarEnArbBinBusqRec(p,&ind,sizeof(tIndice),cmp))
        return SIN_MEM;

    return cargarArbolArchivoINDTemp_Int(&(*p)->izq,li,m-1,archivo,cmp)
        +  cargarArbolArchivoINDTemp_Int(&(*p)->der,m+1,ls,archivo,cmp);

}

int leerYMostrarArchivo(const char *nombreArchivo)
{
    FILE *fp;
    tProducto prod;

    fp = fopen(nombreArchivo,"rb");

    if(!fp)
    {
        return -2;
        printf("\nNo se pudo mostrar el archivo maestro");
    }

    fread(&prod,sizeof(tProducto),1,fp);

    while(!feof(fp))
    {
        mostrarArchivoMaestro(&prod);
        fread(&prod,sizeof(tProducto),1,fp);
    }

    printf("\n\n");
    fclose(fp);
    return TODO_BIEN;
}

void mostrarArchivoMaestro(tProducto *prod)
{
    printf("%2ld %-*.*s %02d/%02d/%04d %3d %8.2f\n",
                                            prod->idProducto,
                                            (int)sizeof(prod->descripcion)-1,
                                            (int)sizeof(prod->descripcion)-1,
                                            prod->descripcion,
                                            prod->fecUltAct.dia,
                                            prod->fecUltAct.mes,
                                            prod->fecUltAct.anio,
                                            prod->cantidad,
                                            prod->precioUnitario
                                            );
}


void mostrarIndice (void * info)
{
    tIndice *ind = (tIndice *)info;
    printf("\n-ID: %d\n",ind->clave);
    printf("\n-ID: %d\n",ind->pos);
}
