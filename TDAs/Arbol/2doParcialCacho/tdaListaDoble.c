#include "main.h"
#include "tdaListaDoble.h"

void crearListaDoble(tListaD *pl)
{
    *pl = NULL;
}

int listaVaciaDoble(const tListaD *pl)
{
    return *pl == NULL;
}

int sacarPrimeroListaDoble(tListaD *pl,void *d,unsigned cantBytes)
{
    tNodoListaDoble *act = *pl,*aux;

    if(act == NULL)
        return 0;

    while(act->ant)
        act = act->ant;

    memcpy(d,act->info,MINIMO(act->tamBytes,cantBytes));

    aux = act;
    act = aux->sig;

    free(aux->info);
    free(aux);

    if(act)
        act->ant = NULL;

    *pl = act;

    return TODO_BIEN;
}


void vaciarListaDoble(tListaD *pl)
{
    tNodoListaDoble *act = *pl, *aux;

    if(act)
    {
        while(act->ant)
        {
            act = act->ant;
        }

        while(act)
        {
            aux = act;
            act = aux->sig;
            free(aux->info);
            free(aux);
        }

        *pl = NULL;
    }
}

int acumularCantidadNov(void **info,unsigned *tam,
                        const void *info2,unsigned tam2)
{
    tNovedad ** dato1 = (tNovedad **) info;
    tNovedad * dato2 = (tNovedad *)info2;

    if(dato2->tipoMovimiento == 'I')
    {
        (*dato1)->precioUnitario+=dato2->precioUnitario;
    }
    else if(dato2->tipoMovimiento == 'E')
    {
        (*dato1)->precioUnitario-=dato2->precioUnitario;
    }

    return TODO_BIEN;
}

int insertarEnOrdenAcum(tListaD *pl,const void *d,unsigned cantBytes,
                        int (*cmp)(const void *,const void *),
                        int (*acum)(void **,unsigned *,const void *,unsigned))
{

    tNodoListaDoble *act = *pl,
                     *nue,
                     *ant,
                     *sig;

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
            if(acum(&act->info,&act->tamBytes,d,cantBytes) == 0)
                return SIN_MEM; //sin memoria

            return 1;//duplicado a acumular
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

    if((nue = (tNodoListaDoble *)malloc(sizeof(tNodoListaDoble))) == NULL
            || (nue->info = malloc(cantBytes)) == NULL  )
    {
        free(nue);
        return 0;
    }

    memcpy(nue->info,d,cantBytes);
    nue->tamBytes = cantBytes;
    nue->ant = ant;
    nue->sig = sig;

    if(ant)
        ant->sig = nue; //estos valores van a apuntar al valor, para ayudarlo a meterlo en el medio

    if(sig) //si no es el mas chico de la lista - porque yo podría querer insertar un 0
        sig->ant = nue;
    *pl = nue;

    return TODO_BIEN;
}

int mostrarDeIzqADer(const tListaD *pl,void (*mostrar)(const void*))
{
    tNodoListaDoble *act = *pl;

    int cant = 0;

    if(act)
    {
        while(act->ant)
            act = act->ant;

        while(act)
        {
            mostrar(act->info);
            act = act->sig;
            ++cant;
        }
    }

    return cant;
}

