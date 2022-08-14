#include "pilaDinamica.h"

void crearPila(tPila *p)
{
    *p = NULL;
}

int insertarEnPila(tPila *p,const void *d,unsigned tam)
{
    tNodoPila * nue;

    if( (nue = (tNodoPila *)malloc(sizeof(tNodoPila))) == NULL ||
        (nue->info = malloc(tam)) == NULL)
    {
        free(nue);
        return SIN_MEM;
    }

    memcpy(nue->info,d,tam);
    nue->tamInfo = tam;
    nue->sig = *p;
    *p = nue;

    return TODO_BIEN;
}

int sacarDePila(tPila *p,void *d,unsigned tam)
{
    tNodoPila *aux = *p;

    if(aux == NULL)
        return 0;

    *p = aux->sig;
    memcpy(d,aux->info,MINIMO(aux->tamInfo,tam));
    free(aux->info);
    free(aux);

    return TODO_BIEN;
}

void vaciarPila(tPila *p)
{
    while(*p)
    {
        tNodoPila *aux = *p;
        *p = aux->sig;
        free(aux->info);
        free(aux);
    }
}

int verTopePila(const tPila *p,void *d,unsigned tam)
{
    tNodoPila *aux = *p;

    if(aux == NULL)
        return 0;

    memcpy(d,aux->info,MINIMO(aux->tamInfo,tam));
    return TODO_BIEN;
}
