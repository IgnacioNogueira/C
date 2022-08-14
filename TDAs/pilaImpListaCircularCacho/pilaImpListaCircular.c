#include "pilaImpListaCircular.h"

void crearPila(tPila *p)
{
    *p = NULL;
}

int pilaVacia(const tPila *p)
{
    return *p == NULL;
}

int pilaLlena(const tPila *p,unsigned cantBytes)
{
    tNodo * aux = (tNodo *)malloc(sizeof(tNodo));
    void * info = malloc(cantBytes);

    free(aux);
    free(info);

    return aux == NULL || info == NULL;
}

int ponerEnPilaCircular(tPila *p,const void *d,unsigned cantBytes)
{
    tNodo *nue;

    if( (nue = (tNodo *)malloc(sizeof(tNodo))) == NULL
            || (nue->info = malloc(cantBytes)) == NULL)
    {
        free(nue);
        return 0;
    }

    memcpy(nue->info,d,cantBytes);
    nue->tamInfo = cantBytes;

    //nue es el tope y *p es el dibujito de jordi
    /*El primero tiene que apuntar al último*/

    if(*p == NULL) //Si hay que ingresar el primero
    {
        nue->sig = nue;
        *p = nue;
    }
    else
    {
        nue->sig = (*p)->sig; //(*p)->sig es el nodo nuevo que se acumula, va a apuntar al primer elemento
        (*p)->sig = nue; // el primero apunta arriba de todo
    }

    return 1;
}

int sacarDePilaCircular(tPila *p,void *d,unsigned cantBytes)
{
    tNodo *aux;

    if(*p == NULL)
        return 0;

    aux = (*p)->sig;

    memcpy(d,aux->info,MINIMO(aux->tamInfo,cantBytes));

    if(aux == *p) //si queda un solo nodo
        *p = NULL;
    else
        (*p)->sig = aux->sig; //basicamente como está unido todo de antes, va a ir a su sig, que es el 2

    free(aux->info);
    free(aux);

    return 1;
}

int verTope(tPila *p,void *d,unsigned cantBytes)
{
    if(*p == NULL)
        return 0;

    memcpy(d,(*p)->sig->info,MINIMO((*p)->sig->tamInfo,cantBytes));
    return 1;

}

void vaciarPila(tPila *p)
{
    while(*p)
    {
        tNodo *aux = (*p)->sig;

        if(aux == *p)
            *p = NULL;
        else
            (*p)->sig = aux->sig;

        free(aux->info);
        free(aux);
    }
}




int ponerEnPilaCircular_MIO(tPila *p, const void * d, unsigned cantBytes)
{
    tNodo *nue;

    if((nue = (tNodo *)malloc(sizeof(tNodo))) == NULL
            || (nue->info = malloc(cantBytes)) == NULL)
    {

        free(nue);
        return -1;
    }

    memcpy(nue->info,d,cantBytes);
    nue->tamInfo = cantBytes;

    if(*p == NULL) //primer instancia
    {
        nue->sig = nue;
        *p = nue;
    }
    else //ya tiene cosas
    {
        nue->sig = (*p)->sig;
        (*p)->sig = nue;
    }

    return 1;
}


int sacarDePilaCircular_MIO(tPila *p,void * d, unsigned cantBytes)
{
    tNodo * aux;

    if(*p == NULL)
        return 0;

    aux = (*p)->sig;
    memcpy(d,aux->info,MINIMO(aux->tamInfo,cantBytes));

    if(aux == *p)
    {
        free(aux->info);
        free(aux);
        *p = NULL;
    }
    else
    {
        (*p)->sig = aux->sig;
        free(aux->info);
        free(aux);
    }

    return 1;
}














































