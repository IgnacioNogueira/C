#include "tdaLista.h"

void crearListaDoble(tListaD *p)
{
    *p = NULL;
}

int insertarYAcumularListaDoble(tListaD * pl,const void *d,unsigned cantBytes,
                                int (*cmp)(const void *,const void *),
                                int (*acum)(void **,unsigned *,const void *,unsigned))
{

    tNodo *nue,
          *ant,
          *sig,
          *act = *pl;

    if(act == NULL)
    {
        ant = NULL;
        sig = NULL;
    }
    else
    {
        int aux;

        while(act->sig && cmp(act->info,d) < 0)
            act = act->sig;

        while(act->ant && cmp(act->info,d) > 0)
            act = act->ant;

        aux = cmp(act->info,d);

        if(aux == 0)
        {
            *pl = act;

            if(acum)
            {
                *pl = act;

                if(!acum(&act->info,&act->tamInfo,d,cantBytes))
                    return SIN_MEM;
            }

            return CLA_DUP;

        }
        else if(aux < 0)
        {
            ant = act;
            sig = act->sig;
        }
        else
        {
            ant = act->ant;
            sig = act;
        }
    }


    if( ( nue = (tNodo *)malloc(sizeof(tNodo)) ) == NULL ||
            (nue->info = malloc(cantBytes)) == NULL)
    {
        free(nue);
        return SIN_MEM;
    }

    memcpy(nue->info,d,cantBytes);
    nue->tamInfo = cantBytes;
    nue->ant = ant;
    nue->sig = sig;

    if(ant)
        ant->sig = nue;

    if(sig)
        sig->ant = nue;

    *pl = nue;
    return TODO_BIEN;
}

int recorrerListaIzqADer(const tListaD *pl,void (*mostrar)(const void*))
{
    tNodo *act = *pl;
    int cant = 0;

    if(act == NULL)
        return 0;

    while(act->ant)
        act = act->ant;

    while(act)
    {
        mostrar(act->info);
        act = act->sig;
        ++cant;
    }

    return cant;
}

int sacarPrimeroDeListaDoble(tListaD *pl,void *d,unsigned cantBytes)
{
    tNodo *aux,*act = *pl;

    if(act == NULL)
        return 0;

    while(act->ant)
        act = act->ant;

    memcpy(d,act->info,MINIMO(act->tamInfo,cantBytes));

    aux = act;
    act = aux->sig;

    free(aux->info);
    free(aux);

    if(act)
    {
        act->ant = NULL;
    }

    *pl = act;
    return TODO_BIEN;
}

int eliminarNUltimosListaDoble(tListaD *pl,unsigned n)
{
    tNodo *act = *pl,*aux;
    int cantElem = 1; //Se tiene que contar aunque sea uno por si existe un solo nodo

    if(act == NULL)
        return 0;

    while(act->ant)
        act = act->ant; //voy hasta atrás de todo por las dudas, no sabemos donde dejamos el puntero

    while(act->sig)
    {
        act = act->sig;
        ++cantElem;
    }

    if(n > cantElem)
        return ERR_EXC;

    while(act && n!=0)
    {
        aux = act;
        act = aux->ant;
        free(aux->info);
        free(aux);
        --n;
    }

    if(act)
    {
        act->sig = NULL;
    }

    *pl = act;

    return TODO_BIEN;
}

