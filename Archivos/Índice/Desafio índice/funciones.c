#include "funciones.h"

int abrirArchivo(FILE **fp,
                 const char *nombreArchivo,
                 const char *modoApertura,
                 int mostrarError)
{
    *fp = fopen(nombreArchivo, modoApertura);

    if(*fp == NULL)
    {
        if(mostrarError == 1)
        {
            fprintf(stderr,
                    "Error abriendo \"%s\" en modo \"%s\".",
                    nombreArchivo,
                    modoApertura);
        }
        return 0;
    }
    return 1;
}

void mostrarProducto (const tProducto *prod)
{

    printf("%01ld %s %02d/%02d/%04d %d %.2f\n", prod->idProducto,
           prod->descripcion,
           prod->fecUltAct.dia,
           prod->fecUltAct.mes,
           prod->fecUltAct.anio,
           prod->cantidad,
           prod->precioUnitario);

}

int leerYMostrarArchivo (const char *nombreArchivo)
{
    FILE *fp;
    tProducto produ;
    abrirArchivo(&fp,nombreArchivo,"rb",1);


    fread(&produ, sizeof(tProducto), 1, fp);
    while(!feof(fp))
    {
        mostrarProducto(&produ);
        fread(&produ, sizeof(tProducto), 1, fp);
    }
    printf("\n");

    fclose(fp);
    return 0;
}

int leerYMostrarArchivoDeTexto(const char *nombreArchivo)
{
    FILE *fp;
    char cad[100];
    abrirArchivo(&fp,nombreArchivo,"rt",1);

    while(fgets(cad, sizeof(cad), fp))
    {
        printf("%s", cad);
    }
    printf("\n");
    fclose(fp);
    return 0;
}

int cmp(const void * v1, const void * v2)
{
    int * e1 = (int *)v1, * e2 = (int *)v2;

    return *e1 - *e2;
}

int comparar(void* d1, const long d2)
{
    tIndice *p1 = (tIndice*)d1;

    return p1->clave - d2;           //modifico el contenido
}

void crearLista(tLista *p)
{
    *p = NULL;
}

int ponerAlFinal(tLista *p, const void *d, unsigned cantBytes)
{
    tNodo *nue;

    while(*p)
        p = &(*p)->sig; //puntero a puntero

    if((nue = (tNodo *)malloc(sizeof(tNodo))) == NULL ||
            (nue->info = malloc(cantBytes)) == NULL)
    {
        free(nue);
        return 0;
    }

    memcpy(nue->info, d, cantBytes);
    nue->tamInfo = cantBytes;
    nue->sig = NULL;
    *p = nue;

    return 1;
}

int verPrimeroLista(tLista *p, void *d, unsigned cantBytes)
{
    if(*p == NULL)
        return 0;
    memcpy(d, (*p)->info, minimo(cantBytes,(*p)->tamInfo));
    return 1;
}



void crearIndice(const char * nombre, tIndice * ind, tLista * lista, FILE * fp)
{
    int i = 0;
    tProducto prod;

    crearLista(lista);

    fp = fopen(nombre, "rb");
    if(!fp)
    {
        printf("\nError al abrir archivo maestro.");
        return;
    }

    fread(&prod, sizeof(tProducto), 1, fp);
    while(!feof(fp))
    {
        ind->clave = prod.idProducto;
        ind->pos = i++;
        ponerAlFinal(lista, ind, sizeof(tIndice));
        fread(&prod, sizeof(tProducto), 1, fp);
    }


    fclose(fp);

    return;
}

void trozarCamposLongitudVariable(tNovedad *d, char *cad)
{
    char *aux = strchr(cad, '\n');
    *aux = '\0';

    /** Cantidad*/
    aux = strrchr(cad, '|');
    sscanf(aux+1, "%d", &d->cantidad);
    *aux = '\0';


    /**Tipo*/
    aux = strrchr(cad, '|');
    sscanf(aux+1, "%c", &d->tipoMovimiento);
    *aux = '\0';


    /**Id*/
    sscanf(cad, "%ld", &d->idProducto);
}

//ta bien, pero no lo uso, porque el ejercicio está hecho para el culo
int buscarEnListaNuevo(tLista *pl,void *d,unsigned cantBytes,
                       int (*cmp)(const void *,const void*))
{
    while(*pl)
    {
        if(cmp((*pl)->info,d) == 0)
        {
            memcpy(d,(*pl)->info,minimo((*pl)->tamInfo,cantBytes));
            return 1;
        }

        pl = &(*pl)->sig;
    }

    return 0;
}

//
int buscarEnListaNuevoSiEstaOrd(tLista *pl,void *d,unsigned cantBytes,
                       int (*cmp)(const void *,const void*))
{
    int r;

    while(*pl)
    {
        if( (r = cmp((*pl)->info,d)) == 0)
        {
            memcpy(d,(*pl)->info,minimo((*pl)->tamInfo,cantBytes));
            return 1;
        }
        else if(r < 0)
        {
            return 0;
        }

        pl = &(*pl)->sig;
    }

    return 0;
}

int buscarEnLista(tLista *p, tNovedad *d1, void* ind, unsigned cantBytes2)
{
    tNodo *aux = *p;
    if(p == NULL)
        return 0;
    while(aux != NULL && comparar(aux->info,d1->idProducto) != 0)
    {
        aux = aux->sig;
    }

    memcpy(ind,aux->info,cantBytes2);

    return 0;

}
int actualizarMaestro(const char * nombreArchivoM, const char * nombreArchivoN, tLista * lista)
{
    int cont = 0;
    FILE *fpM, *fpN;
    tNovedad nov;
    tIndice ind;
    tProducto prod;
    char cad[100];

    abrirArchivo(&fpM,nombreArchivoM,"r+b",1);
    abrirArchivo(&fpN,nombreArchivoN,"rt",1);



    /* while(fgets(cad, sizeof(cad), fpN))
     {
         trozarCamposLongitudVariable(&nov,cad);
         buscarEnLista(lista,&nov, sizeof(tNovedad), &ind, sizeof(tIndice));

         while(prod.idProducto != ind.clave && !feof(fpM))
             fread(&prod,sizeof(tProducto),1,fpM);

         if(nov.tipoMovimiento == 'I')
         {
             prod.cantidad += nov.cantidad;
             cont++;
         }
         if(nov.tipoMovimiento == 'E')
         {
             prod.cantidad -= nov.cantidad;
             cont++;
         }
         fseek(fpM,-1L * (int)sizeof(tProducto),SEEK_CUR);
         fwrite(&prod,sizeof(tProducto),1,fpM);

         rewind(fpM);
     }*/


    while(fgets(cad, sizeof(cad), fpN))
    {
        trozarCamposLongitudVariable(&nov,cad);
        buscarEnLista(lista,&nov, &ind, sizeof(tIndice));

        fseek(fpM, (ind.pos * ((int)sizeof(tProducto))),SEEK_CUR);
        fread(&prod,sizeof(tProducto),1,fpM);

        if(nov.tipoMovimiento == 'I')
        {
            prod.cantidad += nov.cantidad;
            cont++;
        }
        if(nov.tipoMovimiento == 'E')
        {
            prod.cantidad -= nov.cantidad;
            cont++;
        }
        fseek(fpM,-1L * (int)sizeof(tProducto),SEEK_CUR);
        fwrite(&prod,sizeof(tProducto),1,fpM);
        fseek(fpM, 0L,SEEK_CUR);
        rewind(fpM);
    }


    fclose(fpM);
    fclose(fpN);

    return cont;
}
