#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "main.h"
#include "string.h"

#define A_MAYUS(X)((X) >='a' && (X)<='z' ? (X)-32:(X))
#define A_MINUS(X)((X) >='A' && (X)<='Z' ? (X)+32:(X))

void crearLista(tLista *pl)
{
    *pl = NULL;
}

int listaVacia(const tLista *pl)
{
    return *pl == NULL;
}

int listaLlena(const tLista *pl,unsigned tam)
{
    tNodo *aux = (tNodo*)malloc(sizeof(tNodo));
    void *info = malloc(tam);

    free(aux);
    free(info);

    return aux == NULL || info == NULL;
}

void vaciarLista(tLista *pl)
{
    tNodo *aux;

    while(*pl)
    {
        aux = *pl;
        *pl = aux->sig;
        free(aux->info);
        free(aux);
    }
}

int sacarPrimeroLista(tLista *pl,void *d,unsigned tam)
{
    tNodo *aux = *pl;

    if(aux == NULL)
        return 0;

    *pl = aux->sig;
    memcpy(d,aux->info,MINIMO(tam,aux->tamInfo));
    free(aux->info);
    free(aux);

    return 1;
}

int verPrimeroLista(const tLista *pl,void *d,unsigned tam)
{
    tNodo * aux = *pl;

    if(aux == NULL)
        return 0;

    memcpy(d,aux->info,MINIMO(tam,aux->tamInfo));
    return 1;
}


void trozarCampoVariable(tNovedad *nov, char *cad)
{
    char *aux = strchr(cad,'\n');
    *aux = '\0';

    aux = strrchr(cad,'|');
    sscanf(aux+1,"%d",&nov->cantidad);
    *aux = '\0';

    aux = strrchr(cad,'|');
    sscanf(aux+1,"%c",&nov->tipoMovimiento);
    *aux = '\0';

    sscanf(cad,"%li",&nov->idProducto);
}

int leerYmostrarArchivoMast(const char * nombreArchivoMaes)
{
    tProducto prod;

    FILE *fpm = fopen(nombreArchivoMaes,"rb");

    if(!fpm)
    {
        printf("\nNo se puede abrir el archivo %s",nombreArchivoMaes);
        return -5;
    }

    fread(&prod,sizeof(tProducto),1,fpm);

    while(!feof(fpm))
    {
        mostrarMaesBin(&prod);
        fread(&prod,sizeof(tProducto),1,fpm);
    }

    fclose(fpm);
    return 1;
}

void mostrarMaesBin(tProducto * prod)
{
    if(!prod)
    {
        printf("\nNo hay productos que mostrar");
        return;
    }

    printf("%li %-*.*s %d/%d/%d %d %8.2f\n",
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

int leerYmostrarArchivoNov(char * nombreArchNov)
{
    tNovedad nov;
    char linea[100];

    FILE * fpn = fopen(nombreArchNov,"rt");

    if(!fpn)
    {
        printf("\nNo se encuentra el archivo %s\n",nombreArchNov);
        return -6;
    }

    while(fgets(linea,sizeof(linea),fpn))
    {
        trozarCampoVariable(&nov,linea);
        mostrarNovTxt(&nov);

    }
    fclose(fpn);
    return 1;
}

void mostrarNovTxt(tNovedad * nov)
{
    if(!nov)
    {
        printf("\nNo hay novedades que mostrar");
        return;
    }

    printf("%li    %c   %d\n",nov->idProducto,
           nov->tipoMovimiento,
           nov->cantidad
          );
}

int cmpNro(const void * d1, const void * d2)
{
    long * n1 = (long *)d1;
    long * n2 = (long *)d2;

    return *n1-*n2;
}

int cmpNroProd(const void * d1, const void * d2)
{
    tProducto * n1 = (tProducto *)d1;
    tProducto * n2 = (tProducto *)d2;

    return n1-n2;
}

int ponerOrdenLista(tLista *pl,const void *d,unsigned tam,int (*cmp)(const void*, const void*))
{
    tNodo *nue;

    int rc;

    while(*pl && (rc=cmp(d,(*pl)->info)) > 0)
        pl = &(*pl)->sig;

    if(*pl && !rc)
        return 0;

    nue = (tNodo*)malloc(sizeof(tNodo));

    if(!nue)
    {
        return 0;
    }


    nue->info = malloc(tam);

    if(!nue->info)
    {
        free(nue);
        return 0;
    }

    nue->tamInfo = tam;
    memcpy(nue->info,d,tam);
    nue->sig = *pl;

    *pl = nue;

    return 1;

}

void mostrarInd(void *info)
{
    tIndice *ind = (tIndice *)info;
    printf("\n-ID: %d\n",ind->id);
    printf("\n-Posicion: %d\n",ind->pos);

}

void mostrarIndice(tLista *pl)
{
    while(*pl)
    {
        mostrarInd((*pl)->info);
        pl = &(*pl)->sig;
    }
}

void crearIndice(const char * nombreArchivo, tIndice * ind, tLista pl)
{
    int i = 0;
    tProducto prod;
    FILE *fpm;

    fpm = fopen(nombreArchivo,"rb");

    if(!fpm)
    {
        return;
    }

    fread(&prod,sizeof(tProducto),1,fpm);

    while(!feof(fpm))
    {
        ind->id = prod.idProducto;
        ind->pos = i++;
        ponerOrdenLista(&pl,ind,sizeof(tIndice),cmpNro);
        fread(&prod,sizeof(tProducto),1,fpm);
    }

    //mostrarIndice(&pl);
    fclose(fpm);
    return;
}



int cmpIndices(unsigned idNoved,void *idInd)
{
    tIndice *indice = (tIndice *)idInd;

    return idNoved == indice->id;
}

int posIndice(void *pos)
{
    tIndice *indice = (tIndice *)pos;
    return indice->pos;
}

int buscarEnLista(tLista * pl, void * d, int(*cmp)(const void *, const void *))
{
    tNodo * aux;
    int r;

    r = cmp((*pl)->info,d);

    while(*pl && r!=0)
    {
        pl = &(*pl)->sig;
        r = cmp((*pl)->info,d);
    }

    if(r)
    {
        return 0;
    }

    aux = *pl;
    memcpy(d,aux->info,sizeof(aux->tamInfo));
    *pl = aux->sig;
    return 1;
}



int actualizarMaestroProd(char *nombreArchivoMaestro,char *nombreArchivoNovedades,tLista pl)
{
    FILE *fpm,*fpn;
    tProducto prod;
    tNovedad nov;
    char linea[100];
    int cantAct = 0,r;
    fpm = fopen(nombreArchivoMaestro,"r+b");

    if(!fpm)
    {
        return -1;
    }

    fpn = fopen(nombreArchivoNovedades,"rt");

    if(!fpn)
    {
        fclose(fpm);
        return -2;
    }

    long posOrigMaes = ftell(fpm);

    fread(&prod,sizeof(tProducto),1,fpm);

    while(!feof(fpm))
    {
        while(fgets(linea,sizeof(linea),fpn))
        {
            trozarCampoVariable(&nov,linea);
            r = buscarEnLista(&pl,&nov,cmpNroProd);

            if(r)
            {
                if(A_MAYUS(nov.tipoMovimiento) == 'I')
                {
                    fseek(fpm,-1L*(long)sizeof(tProducto),SEEK_CUR);
                    prod.cantidad+=nov.cantidad;
                    fwrite(&prod,sizeof(tProducto),1,fpm);
                    fseek(fpm,0L,SEEK_CUR);
                    ++cantAct;
                }
                else if(A_MAYUS(nov.tipoMovimiento) == 'E')
                {
                    fseek(fpm,-1L*(long)sizeof(tProducto),SEEK_CUR);
                    prod.cantidad-=nov.cantidad;
                    fwrite(&prod,sizeof(tProducto),1,fpm);
                    fseek(fpm,0L,SEEK_CUR);
                    ++cantAct;
                }
            }
        }

        rewind(fpn);
        fread(&prod,sizeof(tProducto),1,fpm);
    }

    fseek(fpm,posOrigMaes,SEEK_SET);
    fclose(fpm);
    fclose(fpn);


    return 1;
}
