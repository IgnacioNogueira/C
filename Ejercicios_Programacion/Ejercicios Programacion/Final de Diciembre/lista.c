#include "lista.h"

void crearLista(tLista *p)
{
    *p = NULL;
}

int listaVacia(const tLista *p)
{
    return *p == NULL;
}

int sacarPrimeroLista(tLista *p, void *d, unsigned cantBytes)
{
    tNodo *aux = *p;
    if(aux == NULL)
        return ERROR;
    *p = aux->sig;
    memcpy(d, aux->info, cantBytes);
    free(aux->info);
    free(aux);
    return TODO_OK;
}

int ponerEnOrden(tLista *p, const void *d, unsigned cantBytes,
                 int (*comparar)(const void*, const void *),
                 int (*acumular)(void **, unsigned *, const void *, unsigned))
{
    tNodo *nue;
    while(*p && comparar((*p)->info, d) < 0)
        p = &(*p)->sig;
    if(*p && comparar((*p)->info, d) == 0)
    {
        if(acumular)
        {
            if(!acumular(&(*p)->info, &(*p)->tamInfo, d, cantBytes))
                return ERROR;
        }
        else
            return ERROR;
    }
    else
    {
        if((nue = (tNodo *)malloc(sizeof(tNodo))) == NULL || (nue->info = malloc(cantBytes)) == NULL)
        {
            free(nue);
            return ERROR;
        }
        memcpy(nue->info, d, cantBytes);
        nue->tamInfo = cantBytes;
        nue->sig = *p;
        *p = nue;
    }
    return TODO_OK;
}
