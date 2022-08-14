/**//*             en los siguientes macroreemplazos indique:             *//**/
/**//*    su(s)         APELLIDO(S)     completo(s)                       *//**/
/**//*    su(s)         Nombre(S)       completo(s)                       *//**/
/**//*    su legajo     NÚMERO DE DNI   con los puntos de millón y de mil *//**/
/**//*    COMISIÓN                                                        *//**/
/**//*              reemplazando los que están como ejemplo               *//**/
#define APELLIDO    "PÉREZ DEL RÍO"
#define NOMBRE      "Juan Manuel"
#define DOCUMENTO   "22.333.444"
#define COMISION    "07(7299)"
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/** aquí insertaremos nuestras observaciones y / o correcciones              **/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
#undef APELLIDO
#undef NOMBRE
#undef DOCUMENTO
#undef COMISION
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, HÁGALO DESDE ACÁ *//**/

#include "string.h"
#include "stdlib.h"

/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, HÁGALO HASTA ACÁ *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
#include "funciones.h"

/** para el PUNTO 1 **/
#define ES_BLANCO(X)((X) == ' ' || (X) == '\t')
#define A_MAYUS(X)((X) >= 'a' && (X) <= 'z' ? (X)-32:(X))
#define A_MINUS(X)((X) >='A' && (X)<='Z' ? (X)+32:(X))
#define ES_LETRA(X)( ((X) >= 'a' && (X) <= 'z') || ((X) >= 'A' && (X) <= 'Z'))

void sacarEspaciosComienzoFin(char *str);
void unSoloEspacioEntrePalabras(char *str);
void MayusYminus(char *str);

void sacarEspaciosComienzoFin(char *str)
{
    char *p1 = str; //empieza en el comienzo de la cadena, pero tiene todo en realidad
    char *p2 = str + (strlen(str)-1);

    while(ES_BLANCO(*p2))
    {
        --p2;
    }

    *(p2+1) = '\0';

    while(ES_BLANCO(*p1))
    {
        ++p1;
    }

    strcpy(str,p1);
}

void unSoloEspacioEntrePalabras(char *str)
{
    char *p1 = str,*p2;

    while((p2 = strstr(p1,"  ")) != NULL) //retorno al p1 el resultado
    {
        memmove(p2,p2+1,strlen(p2));
    }
}

void MayusYminus(char *str)
{
    char *p = str;

    *p = A_MAYUS(*p);
    ++p;

    while(*p)
    {
        if(ES_LETRA(*p))
        {
            *p = A_MINUS(*p);
        }

        if(ES_BLANCO(*p))
        {
            ++p;
            *p = A_MAYUS(*p);
        }

        ++p;
    }
}

char *normalizarCadena_MIO(char *str)
{
    sacarEspaciosComienzoFin(str);
    unSoloEspacioEntrePalabras(str);
    MayusYminus(str);

    return str;
}

/** FIN de PUNTO 1 **/


/** para el PUNTO 2 **/

void obtenerLineaArchivo(tProducto *p,FILE *archALeer);

void obtenerLineaArchivo(tProducto *p,FILE *archALeer)
{
    fread(p,sizeof(tProducto),1,archALeer);
    normalizarCadena_MIO(p->descripcion);
}


int fusionarMaestros_MIO(char *nombreArchivo1,
                         char *nombreArchivo2,
                         char *nombreArchivoF)
{
    FILE *fp1,*fp2,*fpf;
    tProducto prod1,prod2;

    fp1 = fopen(nombreArchivo1,"rb");

    if(!fp1)
        return FAIL;

    fp2 = fopen(nombreArchivo2,"rb");

    if(!fp2)
    {
        fclose(fp1);
        return FAIL;
    }

    fpf = fopen(nombreArchivoF,"wb");

    if(!fpf)
    {
        fclose(fp1);
        fclose(fp2);
        return FAIL;
    }

    //como se crea un nuevo archivo y no se actualiza sobre el mismo, no hace falta ftell
    obtenerLineaArchivo(&prod1,fp1);
    obtenerLineaArchivo(&prod2,fp2);

    while(!feof(fp1) && !feof(fp2))
    {
        if(prod1.idProducto < prod2.idProducto)
        {
            fwrite(&prod1,sizeof(tProducto),1,fpf);
            obtenerLineaArchivo(&prod1,fp1);
        }
        else if(prod1.idProducto > prod2.idProducto)
        {
            fwrite(&prod2,sizeof(tProducto),1,fpf);
            obtenerLineaArchivo(&prod2,fp2);
        }
        else
        {
            fwrite(&prod1,sizeof(tProducto),1,fpf);
            fwrite(&prod2,sizeof(tProducto),1,fpf);
            obtenerLineaArchivo(&prod1,fp1);
            obtenerLineaArchivo(&prod2,fp2);
        }
    }

    while(!feof(fp1))
    {
        obtenerLineaArchivo(&prod1,fp1);
        fwrite(&prod1,sizeof(tProducto),1,fpf);
    }

    while(!feof(fp2))
    {
        obtenerLineaArchivo(&prod2,fp2);
        fwrite(&prod2,sizeof(tProducto),1,fpf);
    }

    fclose(fp1);
    fclose(fp2);
    fclose(fpf);
    return TODO_BIEN;
}
/** FIN de PUNTO 2 **/


/** para el PUNTO 3 **/

int ponerEnListaAlFinal(tLista *pl,const void *d,unsigned cantBytes);


int ponerEnListaAlFinal(tLista *pl,const void *d,unsigned cantBytes)
{
    tNodo *nue;

    while(*pl)
    {
        pl = &(*pl)->sig;
    }

    if( (nue = (tNodo *)malloc(sizeof(cantBytes))) == NULL
            || (nue->info = malloc(cantBytes)) == NULL)
    {
        free(nue);
        return SIN_MEMORIA;
    }

    memcpy(nue->info,d,cantBytes);
    nue->tamInfo = cantBytes;
    nue->sig = NULL;
    *pl = nue;

    return TODO_BIEN;
}

int cargarMaestroEnLista_MIO(char *nombreArchivoMaestro,
                             tLista *pl,
                             FILE *fpPantalla)
{

    tProducto prod;
    FILE *fp = fopen(nombreArchivoMaestro,"rb");

    if(!fp)
        return FAIL;

    fread(&prod,sizeof(tProducto),1,fp);
    while(!feof(fp))
    {
        ponerEnListaAlFinal(pl,&prod,sizeof(tProducto));
        fread(&prod,sizeof(tProducto),1,fp);
    }

    return TODO_BIEN;

}
/** FIN de PUNTO 3 **/


/** para el PUNTO 4 **/

#define MINIMO(X,Y)( (X) <= (Y) ? (X) : (Y) )

int acumularCantidadProductos(void **info1,
                              unsigned *tamInfo1,
                              const void *info2,
                              unsigned tamInfo2);

int cmpIdProd(const void * v1,const void *v2);

int eliminarDupListaSimple(tLista *pl,
                           int(*cmp)(const void*,const void*),
                           int(*acum)(void **,unsigned *,const void*,unsigned));

int sacarPrimeroDeLista(tLista *pl,void *d,unsigned cantBytes);

int acumularCantidadProductos(void **info1,
                              unsigned *tamInfo1,
                              const void *info2,
                              unsigned tamInfo2)
{
    tProducto ** d1 = (tProducto **)info1;
    const tProducto *d2 = (tProducto *)info2;

    (*d1)->cantidad+=d2->cantidad;
    (*d1)->fecUltAct.dia = d2->fecUltAct.dia;
    (*d1)->fecUltAct.mes = d2->fecUltAct.mes;
    (*d1)->fecUltAct.anio = d2->fecUltAct.anio;
    return TODO_BIEN;
}


/*
int acumularCantidadProductos(void **info1,
                              unsigned *tamInfo1,
                              const void *info2,
                              unsigned tamInfo2)
{
    tProducto ** d1 = (tProducto **)info1;
    const tProducto *d2 = (tProducto *)info2;

    (*d1)->cantidad+=d2->cantidad;
    (*d1)->fecUltAct.dia = d2->fecUltAct.dia;
    (*d1)->fecUltAct.mes = d2->fecUltAct.mes;
    (*d1)->fecUltAct.anio = d2->fecUltAct.anio;
    return TODO_BIEN;
}
*/

int cmpIdProd(const void * v1,const void *v2)
{
    const tProducto *p1 = (tProducto *)v1;
    const tProducto *p2 = (tProducto *)v2;

    return p1->idProducto - p2->idProducto;
}


int eliminarDupListaSimple(tLista *pl,
                          int (*cmp)(const void *,const void*),
                          int (*acum)(void **,unsigned *,const void *,unsigned))
{
    tLista *pComp;
    tNodo *aux;
    int r;
    int cantElem = 0;

    while(*pl)
    {
        pComp = &(*pl)->sig;

        while(*pComp)
        {
            if(cmp((*pl)->info,(*pComp)->info) == 0)
            {
                if(acum)
                    if( (r = acum(&(*pl)->info,&(*pl)->tamInfo,(*pComp)->info,(*pComp)->tamInfo) ) != TODO_BIEN)
                        return r;

                aux = *pComp;
                *pComp = (*pComp)->sig;
                free(aux->info);
                free(aux);
                ++cantElem;
            }
            else
            {
              pComp = &(*pComp)->sig;
            }
        }

        pl = &(*pl)->sig;
    }

    return cantElem;
}

/*
int eliminarDupListaSimple(tLista *pl,
                           int (*cmp)(const void*,const void*),
                           int (*acum)(void **,unsigned *,const void*,unsigned))
{
    tNodo *act = *pl,*antpComp = *pl,*pComp = *pl, *aux;
    int cantElim = 0;

    while(act)
    {
        pComp = pComp->sig;

        while(pComp)
        {
            if(cmp(act->info,pComp->info) == 0)
            {
                if(acum)
                    if(!acum(&act->info,&act->tamInfo,pComp->info,pComp->tamInfo))
                        return SIN_MEMORIA;

                antpComp->sig = pComp->sig;
                aux = pComp;
                pComp = aux->sig;
                free(aux->info);
                free(aux);
                ++cantElim;
            }
            else
            {
                pComp = pComp->sig;
                antpComp = antpComp->sig;
            }
        }

        act = act->sig;
        antpComp = act;
        pComp = act;
    }

    return cantElim;
}
*/


int sacarPrimeroDeLista(tLista *pl,void *d,unsigned cantBytes)
{
    tNodo *aux;

    if(*pl == NULL)
        return 0;

    aux = *pl;
    memcpy(d,aux->info,MINIMO(aux->tamInfo,cantBytes));
    *pl = aux->sig;

    free(aux->info);
    free(aux);

    return TODO_BIEN;
}

void actualizarArchivoPunto4(const void * infoLista,unsigned tamInfoLista,void *setDeDatos,unsigned tamReg);

void actualizarArchivoPunto4(const void * infoLista,unsigned tamInfoLista,void *setDeDatos,unsigned tamReg)
{
    FILE * arch = (FILE *)setDeDatos;
    tProducto * prod = (tProducto *)infoLista;
    fwrite(prod,tamInfoLista,1,arch);
}


int recorrerLista_MIO(const tLista *pl, void * setDeDatos, unsigned tamReg, void (*act)(const void *,unsigned,void *,unsigned));

int recorrerLista_MIO(const tLista *pl, void * setDeDatos, unsigned tamReg, void (*act)(const void *,unsigned,void *,unsigned))
{
    tNodo *aux = *pl;

    while(aux)
    {
        act(aux->info,aux->tamInfo,setDeDatos,tamReg);
        aux = aux->sig;
    }

    return TODO_BIEN;
}

int eliminarDupYsobrescibirMaestro_MIO(tLista *pl,
                                       int *cantDupEliminados,
                                       const char *nombreArchivoMaestro)
{
    FILE *fp = fopen(nombreArchivoMaestro,"wb");

    if(!fp)
        return FAIL;

    *cantDupEliminados = eliminarDupListaSimple(pl,
                         cmpIdProd,
                         acumularCantidadProductos);

    recorrerLista_MIO(pl,fp,sizeof(tProducto),actualizarArchivoPunto4);

    fclose(fp);
    return TODO_BIEN;
}
/** FIN de PUNTO 4 **/


/** para el PUNTO 5 **/

#define SIGUE_LEYENDO_NOV 10

void trozarLongitudFija(tNovedad *nov, char *s);

void trozarLongitudFija(tNovedad *nov, char *s)
{
    char *aux = strchr(s,'\n');
    *aux = '\0';

    aux = strrchr(s,'|');
    sscanf(aux+1,"%d",&nov->cantidad);
    *aux = '\0';

    aux = strrchr(s,'|');
    sscanf(aux+1,"%c",&nov->tipoMovimiento);
    *aux = '\0';

    sscanf(s,"%ld",&nov->idProducto);
}

int actualizarNovedadTipo(tProducto *prod,const tNovedad *nov);

int actualizarNovedadTipo(tProducto *prod,const tNovedad *nov)
{
    if(prod->idProducto == nov->idProducto)
    {
        if(A_MAYUS(nov->tipoMovimiento) == 'I')
        {
            prod->cantidad+=nov->cantidad;
        }
        else if(A_MAYUS(nov->tipoMovimiento) == 'E')
        {
            prod->cantidad-=nov->cantidad;
        }
        else
        {
            return FAIL;
        }

        return TODO_BIEN;
    }

    return SIGUE_LEYENDO_NOV;
}

void flujoArchivoActualizacion(FILE *nombreArchivoMaestro,tProducto *prod);

void flujoArchivoActualizacion(FILE *nombreArchivoMaestro,tProducto *prod)
{
    fseek(nombreArchivoMaestro,-1L*(long)(sizeof(tProducto)),SEEK_CUR);
    fwrite(prod,sizeof(tProducto),1,nombreArchivoMaestro);
    fseek(nombreArchivoMaestro,0L,SEEK_CUR);
}

int actualizarMaestroDesdeArchivoDeNovedades_MIO(char *nombreArchivoMaestro,
        char *nombreArchivoNovedades,
        FILE *fpPantalla)
{
    int cantAct = 0;
    int r,vuelta = 0;
    char linea[100];
    tProducto prod;
    tNovedad nov;
    FILE *fpm,*fpn;

    fpm = fopen(nombreArchivoMaestro,"r+b");

    if(!fpm)
        return FAIL;

    fpn = fopen(nombreArchivoNovedades,"rt");

    if(!fpn)
    {
        fclose(fpm);
        return FAIL;
    }

    long posOrigArch = ftell(fpm);

    fread(&prod,sizeof(tProducto),1,fpm);

    while(!feof(fpm))
    {
        while(fgets(linea,sizeof(linea),fpn))
        {
            trozarLongitudFija(&nov,linea);
            ++vuelta;

            if( (r = actualizarNovedadTipo(&prod,&nov)) == TODO_BIEN)
            {
                flujoArchivoActualizacion(fpm,&prod);
                ++cantAct;
            }
            else if(r == FAIL)
            {
                fprintf(fpPantalla,"\nEl archivo tiene un error en la linea %d. Tipo de movimiento pasado: %c\n",vuelta,nov.tipoMovimiento);
                return FAIL;
            }
        }

        rewind(fpn);
        vuelta = 0;
        fread(&prod,sizeof(tProducto),1,fpm);
    }

    fseek(fpm,posOrigArch,SEEK_SET);
    fclose(fpm);
    fclose(fpn);

    return cantAct;
}

/** FIN de PUNTO 5 **/

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

