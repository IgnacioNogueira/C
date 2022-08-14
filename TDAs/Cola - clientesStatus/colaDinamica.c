#include "colaDinamica.h"

void crearColaDin(tColaD *col)
{
    col->pri=NULL;
    col->ult=NULL;
}

int colaVaciaDin(const tColaD *col)
{
    return col->pri == NULL;
}

void vaciarColaDin(tColaD *col)
{
    while(col->pri)
    {
        tNodo *aux = col->pri;
        col->pri = aux->sig;
        free(aux->info);
        free(aux);
    }

    col->ult= NULL;
}

int colaLlenaDin(const tColaD *col,unsigned cantBytes)
{
    tNodo *aux= (tNodo *) malloc(sizeof(tNodo));
    void  *info = malloc(cantBytes);
    free(aux);
    free(info);

    return aux == NULL || info == NULL;
}

int ponerEnColaDin(tColaD *col,const void *d,unsigned cantBytes)
{
    tNodo * nue = (tNodo*) malloc(sizeof(tNodo));

    if(nue == NULL || (nue->info = malloc(cantBytes))== NULL)
    {
        free(nue);
        return 0;
    }

    memcpy(nue->info,d,cantBytes);
    nue->tamInfo = cantBytes;
    nue->sig = NULL;

    if(col->ult)
        col->ult->sig = nue;
    else
        col->pri = nue;
    col->ult = nue;
    return 1;
}

int sacarColaDin(tColaD *col,void *d,unsigned cantBytes)
{
    tNodo * aux = col->pri;
    if(aux == NULL)
        return 0;

    col->pri = aux->sig;
    memcpy(d,aux->info,MINIMO(aux->tamInfo,cantBytes));
    free(aux->info);
    free(aux);

    if(col->pri == NULL)
        col->ult = NULL;
    return 1;
}

int verPrimeroColaDin(const tColaD *col,void *d,unsigned cantBytes)
{
    if(col->pri == NULL)
        return 0;

    memcpy(d,col->pri->info,MINIMO(col->pri->tamInfo,cantBytes));
    return 1;
}
