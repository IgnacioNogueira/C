#include "colaImpListaCircular.h"

void crearCola(tCola *pc)
{
    *pc = NULL;
}

int colaLLena(tCola *pc,unsigned cantBytes)
{
    tNodo * aux = (tNodo *)malloc(sizeof(tNodo));
    void *info = malloc(cantBytes);

    free(aux);
    free(info);

    return aux == NULL || info == NULL;

}

int colaVacia(tCola *pc)
{
    return *pc == NULL;
}

int ponerEnColaCir(tCola *pc, const void *d,unsigned cantBytes)
{
    tNodo *nue;

    if((nue = (tNodo *)malloc(sizeof(tNodo))) == NULL
            || (nue->info = malloc(cantBytes)) == NULL)
    {
        free(nue);
        return 0;
    }

    memcpy(nue->info,d,cantBytes);
    nue->tamInfo = cantBytes;

    if(*pc == NULL)
    {
        nue->sig = nue;
    }
    else
    {
        nue->sig = (*pc)->sig;
        (*pc)->sig = nue;
    }

    *pc = nue;

    return 1;
}

int sacarEnColaCir(tCola *pc,void *d,unsigned cantBytes)
{
    tNodo *aux;

    if(*pc == NULL)
        return 0;

    aux = (*pc)->sig;
    memcpy(d,aux->info,MINIMO(aux->tamInfo,cantBytes));

    if(aux == *pc)
        *pc = NULL;
    else
        (*pc)->sig = aux->sig;

    free(aux->info);
    free(aux);
    return 1;
}

void vaciarCola(tCola *pc)
{
    while(*pc)
    {
        tNodo *aux = (*pc)->sig;

        if(aux == *pc)
            *pc = NULL;
        else
            (*pc)->sig = aux->sig;

        free(aux->sig);
        free(aux);
    }
}

int verPrimeroCola(tCola *pc,void *d,unsigned cantBytes)
{
    if(*pc == NULL)
        return 0;

    memcpy(d,(*pc)->sig->info,MINIMO((*pc)->sig->tamInfo,cantBytes));
    return 1;
}
