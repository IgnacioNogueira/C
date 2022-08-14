#include "tdaColaImpListaCircular.h"

void crearCola(tCola *pc)
{
    *pc = NULL;
}

int colaVacia(tCola *pc)
{
    return *pc == NULL;
}

int ponerEnColaCir(tCola *pc,const void *d,unsigned cantBytes)
{
    tNodoColaImpListaCircular *nue;

    if( (nue = (tNodoColaImpListaCircular *)malloc(sizeof(tNodoColaImpListaCircular))) == NULL ||
        (nue->info = malloc(cantBytes)) == NULL)
    {
        free(nue);
        return SIN_MEM;
    }

    memcpy(nue->info,d,cantBytes);
    nue->tamInfo = cantBytes;

    if(*pc == NULL)
    {
        nue->sig = nue;
        *pc = nue;
    }
    else
    {
        nue->sig = (*pc)->sig;
        (*pc)->sig = nue;
        *pc = nue;
    }

    return TODO_BIEN;
}

int verPrimeroCola(tCola *pc,void *d,unsigned cantBytes)
{
    if(*pc == NULL)
        return 0;

    memcpy(d,(*pc)->sig->info,MINIMO((*pc)->sig->tamInfo,cantBytes));
    return TODO_BIEN;
}

int sacarEnColaCir(tCola *pc,void *d,unsigned cantBytes)
{
    tNodoColaImpListaCircular *aux;

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
    return TODO_BIEN;
}
