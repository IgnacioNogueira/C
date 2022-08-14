#include "pilaDinamica.h"

void crearPilaDinamica(tPilaD *p)
{
    *p = NULL;
}

int pilaDinLLena(const tPilaD *pil,unsigned cantBytes)
{
    tNodo *aux = (tNodo*) malloc(sizeof(tNodo));
    void * info = malloc(cantBytes);

    free(aux);
    free(info);

    return aux == NULL || info == NULL;

}

int pilaDinVacia(const tPilaD *p)
{
    return *p == NULL;
}

int ponerEnPilaDinamica(tPilaD *p,const void *d,unsigned cantBytes)
{
    tNodo * nue;

    if( (nue = (tNodo *)malloc(sizeof(tNodo))) == NULL || (nue->info = malloc(cantBytes)) == NULL)
    {
        free(nue);
        return 0;
    }

    memcpy(nue->info,d,cantBytes);
    nue->tamInfo = cantBytes;
    nue->sig = *p;
    *p = nue;

    return 1;
}

int verTopePilaDinamica(const tPilaD *p,void *d,unsigned cantBytes)
{
    if(!*p)
        return 0;

    memcpy(d,(*p)->info,MINIMO(cantBytes,(*p)->tamInfo));
    return 1;
}

int sacarPilaDinamica(tPilaD *p,void *d,unsigned cantBytes)
{
    tNodo *aux = *p;

    if(aux == NULL)
        return 0;

    *p = aux->sig;
    memcpy(d,aux->info,MINIMO(cantBytes,aux->tamInfo));

    free(aux->info);
    free(aux);
    return 1;
}



void vaciarPilaDinamica(tPilaD *pil)
{
    while(*pil)
    {
        tNodo *aux = *pil;
        *pil = aux->sig;
        free(aux->info);
        free(aux);
    }
}


//void vaciarPilaDinamica(tPilaD *p)
//{
//    while(*p)
//    {
//        tNodo *aux = *p;
//        *p = aux->sig;
//        free(aux->info);
//        free(aux);
//
//    }
//
//}
