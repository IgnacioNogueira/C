#include "tdaListaSimple.h"

void crearLista(tLista *pl)
{
    *pl = NULL;
}

int esListaVacia(tLista *pl)
{
    return *pl == NULL;
}

int ponerListaAlFinal(tLista *pl,const void *d,unsigned cantBytes)
{
    tNodoLista * nue;

    while(*pl)
        pl = &(*pl)->sig;


    if( (nue = (tNodoLista *)malloc(sizeof(tNodoLista))) == NULL ||
            (nue->info = malloc(cantBytes)) == NULL)
    {
        free(nue);
        return SIN_MEM;
    }

    memcpy(nue->info,d,cantBytes);
    nue->tamInfo = cantBytes;
    nue->sig = NULL;
    *pl = nue;

    return TODO_BIEN;
}

/*
int eliminarYAcumDupLista(tLista *pl,
                          int (*cmp)(const void *,const void*),
                          int (*acum)(void **,unsigned *,const void *,unsigned))
{
    tNodoLista *act = *pl,*antpComp = *pl,*pComp = *pl, *aux;

    while(act)
    {
        pComp = pComp->sig;

        while(pComp)
        {
            if(cmp(act->info,pComp->info) == 0)
            {
                if(acum)
                    if(!acum(&act->info,&act->tamInfo,pComp->info,pComp->tamInfo))
                        return SIN_MEM;

                antpComp->sig = pComp->sig;
                aux = pComp;
                pComp = aux->sig;
                free(aux->info);
                free(aux);

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

    return TODO_BIEN;
}
*/
int eliminarYAcumDupLista(tLista *pl,
                          int (*cmp)(const void *,const void*),
                          int (*acum)(void **,unsigned *,const void *,unsigned))
{
    tLista *pComp;
    tNodoLista *aux;
    int r;

    while(*pl)
    {
        pComp = &(*pl)->sig;

        while(*pComp)
        {
            if(cmp((*pl)->info,(*pComp)->info) == 0)
            {
                if(acum)
                    if(acum(&(*pl)->info,&(*pl)->tamInfo,(*pComp)->info,(*pComp)->tamInfo) == SIN_MEM)
                        return SIN_MEM;

                aux = *pComp;
                *pComp = (*pComp)->sig;
                free(aux->info);
                free(aux);
                ++cant;
            }
            else
            {
              pComp = &(*pComp)->sig;
            }
        }

        pl = &(*pl)->sig;
    }

    return TODO_BIEN;
}



int sacarDeListaPrimero(tLista *pl,void *d, unsigned cantBytes)
{
    tNodoLista *aux = *pl;

    if(!aux)
        return 0;

    *pl = aux->sig;
    memcpy(d,aux->info,MINIMO(aux->tamInfo,cantBytes));
    free(aux->info);
    free(aux);

    return TODO_BIEN;
}
