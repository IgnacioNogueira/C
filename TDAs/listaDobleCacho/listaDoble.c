#include "listaDoble.h"

void crearListaDoble(tListaD *pl)
{
    *pl = NULL;
}

int listaDobleVacia(tListaD *pl)
{
    return *pl == NULL;
}

int listaDobleLlena(tListaD *pl,unsigned cantBytes)
{
    tNodo * aux = (tNodo *)malloc(sizeof(tNodo));
    void * info = malloc(cantBytes);

    free(aux);
    free(info);

    return aux == NULL || info == NULL;
}

int insertarAlComienzoLD(tListaD *pl,const void *d,unsigned cantBytes)
{
    tNodo * nue,*act = *pl;

    if(act)
        while(act->ant)
            act = act->ant;

    if((nue = (tNodo *)malloc(sizeof(tNodo))) == NULL ||
       (nue->info = malloc(cantBytes)) == NULL)
    {
        free(nue);
        return 0;
    }

    memcpy(nue->info,d,cantBytes);
    nue->tamBytes = cantBytes;

    ///realiza los enlaces
    nue->sig = act; //apunta al que tiene atras en las otros movimientos -
    nue->ant = NULL;

    if(act) //no entra la primera vez, sino que los siguientes
        act->ant = nue;

    *pl = nue; //avanzo y apunto el últ insertado

    return 1;
}

int insertarAlFinalLD(tListaD *pl,const void *d,unsigned cantBytes)
{
    tNodo * nue,*act = *pl;

    if(act)
        while(act->sig)
            act = act->sig;

    if((nue = (tNodo *)malloc(sizeof(tNodo))) == NULL
            || (nue->info = malloc(cantBytes)) == NULL)
    {
        free(nue);
        return 0;
    }

    memcpy(nue->info,d,cantBytes);
    nue->tamBytes = cantBytes;
    ///realiza los enlaces
    nue->ant = act;
    nue->sig = NULL;

    if(act) //no entra la primera vez, sino que los siguientes
        act->sig = nue;

    *pl = nue; //avanzo y apunto el últ insertado

    return 1;
}

int sacarPrimeroLD(tListaD *pl,void *d,unsigned cantBytes)
{
    tNodo *act = *pl, *aux;

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
    {
        act->ant = NULL;
    } // si pl es NULL no puedo sacar su anterior

    *pl = act;
    return 1;
}

int sacarUltimoLD(tListaD *pl,void *d,unsigned cantBytes)
{
    tNodo *act = *pl,*aux;

    if(act == NULL)
        return 0;

    while(act->sig)
        act = act->sig;

    memcpy(d,act->info,MINIMO(act->tamBytes,cantBytes));

    aux = act;
    act = aux->ant;

    free(aux->info);
    free(aux);

    if(act)
    {
        act->sig = NULL;
    } // si pl es NULL no puedo sacar su sig

    *pl = act;
    return 1;
}

void vaciarListaDoble(tListaD *pl)
{
    tNodo *act = *pl, *aux;

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


int compararProd(const void *d1,const void *d2)
{
    const tProducto *p1 = (tProducto *)d1;
    const tProducto *p2 = (tProducto *)d2;

    return p1->idProducto - p2->idProducto;
}

int insertarEnOrden(tListaD *pl,const void *d,unsigned cantBytes,
                    int (*cmp)(const void *,const void *))
{
    tNodo *act = *pl,
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
            return 0; //duplicado
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

    if((nue = (tNodo *)malloc(sizeof(tNodo)))== NULL
            || (nue->info = malloc(cantBytes)) == NULL)
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

    return 1;
}

int acumularCantidadProd(void **info,unsigned *tam,
                         const void *info2,unsigned tam2)
{
    tProducto ** dato1 = (tProducto **) info;
    const tProducto * dato2 = (tProducto *)info2;

    (*dato1)->cantidad+=dato2->cantidad;

    return 1;
}

int insertarEnOrdenAcum(tListaD *pl,const void *d,unsigned cantBytes,
                        int (*cmp)(const void *,const void *),
                        int (*acum)(void **,unsigned *,const void *,unsigned))
{

    tNodo *act = *pl,
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
            if(acumularCantidadProd(&act->info,&act->tamBytes,d,cantBytes) != 1)
                return 0; //sin memoria

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

    if((nue = (tNodo *)malloc(sizeof(tNodo))) == NULL
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

    return 1;
}

void mostrarProd(const void *dv)
{
    const tProducto *d = (tProducto *) dv;

    printf("-%05li %-*.*s  %04d  %.2f\n",
           d->idProducto,
           (int)sizeof(d->descripcion)-1,
           (int)sizeof(d->descripcion)-1,
           d->descripcion,
           d->cantidad,
           d->precioUnitario);
}

int mostrarDeDerAIzq_MIOOOO(const tListaD *pl,void (*mostrar)(const void *))
{
    tNodo *act = *pl;

    if(act == NULL)
        return 0;

    int cant = 0;

    while(act->ant)
        act = act->ant;

    while(act)
    {
        mostrar(act->info);
        act = act->ant;
        ++cant;
    }

    return cant;
}

int mostrarDeIzqADer(const tListaD *pl,void(*mostrar)(const void *))
{
    tNodo *act = *pl;

    int cant = 0;

    if(act)
    {
        while(act->ant)
            act = act->ant;

        while(act)
        {
            mostrarProd(act->info);
            act = act->sig;
            ++cant;
        }

    }

    return cant;
}
int mostrarDeDerAIzq(const tListaD *pl,void(*mostrar)(const void *))
{
    tNodo *act = *pl;

    int cant = 0;

    if(act)
    {
        while(act->sig)
            act = act->sig;

        while(act)
        {
            mostrarProd(act->info);
            act = act->ant;
            ++cant;
        }
    }

    return cant;
}

int eliminarPorClave(tListaD *pl,void *d,unsigned cantBytes,int (*cmp)(const void *,const void*))
{
    tNodo *act = *pl;
    int aux;

    if(act == NULL)
        return 0; //no hay elementos

    while(act->sig && cmp(act->info,d) < 0)
        act = act->sig;

    while(act->ant && cmp(act->info,d) > 0)
        act = act->ant;

    aux = cmp(act->info,d);

    if(aux == 0)
    {
        tNodo *ant = act->ant;
        tNodo *sig = act->sig;

        if(ant)
            ant->sig = sig;
        if(sig)
        {
            sig->ant = ant;
            *pl = sig;
        }
        else
            *pl = ant;

        memcpy(d,act->info,cantBytes);
        free(act->info);
        free(act);
        return 1;
    }

    return 0;
}

tNodo * buscarNodo(tListaD *pl,void *d,int (*cmp)(const void *, const void *))
{
    int comp;

    comp = cmp((*pl)->info,d);

    while((*pl)->sig && (comp = cmp((*pl)->info,d)) != 0)
    {
        pl = &(*pl)->sig;
        comp = cmp((*pl)->sig,d);
    }

    if(comp == 0)
        return *pl;

    return NULL;
}




int eliminaryAcumDuplicadosLD_MIO(tListaD *pl,
                                  int (*cmp)(const void*, const void *),
                                  int (*acum)(void **,unsigned *,const void *,unsigned))
{
    tNodo *aux, *dup,*act = *pl;
    int cant = 0;

    if(act == NULL)
        return -1;

    while(act->ant)
        act = act->ant;

    while(act->sig)
    {
        if(cmp(act->info,act->sig->info) == 0)
        {
            dup = act->sig;

            do
            {
                if(acum)
                {
                    if(!acum(&act->info,&act->tamBytes,dup->info,dup->tamBytes))
                        return -1; //sin memoria
                }

                aux = dup;
                dup = aux->sig;
                free(aux->info);
                free(aux);
                ++cant;

            }
            while(dup && cmp(act->info,dup->info) == 0);

            if(dup)
            {
                dup->ant = act;
                act->sig = dup;
                act = act->sig;
            }
            else
            {
                act->sig = NULL;
            }
        }
        else
        {
            act = act->sig;
        }
    }

    *pl = act;
    return cant;
}

void ordenarLista(tListaD *pl, int (*cmp)(const void *, const void*))
{
    tNodo *act = *pl,
           *sup = NULL,
            *inf = NULL;

    int marca = 1;

    if(act == NULL)
        return;

    while(act->ant)
        act = act->ant;

    while(marca)
    {
        marca = 0;

        while(act->sig != sup)
        {
            if(cmp(act->info,act->sig->info) > 0) //el segundo es más grande
            {
                void *inf = act->info;
                unsigned tam = act->tamBytes;

                marca = 1;
                act->info = act->sig->info;
                act->sig->info = inf; //muevo a la derecha todo
                act->tamBytes = act->sig->tamBytes;
                act->sig->tamBytes = tam;
            }

            act = act->sig;
        }

        sup = act;

        while(act->ant != inf)
        {
            if(cmp(act->info,act->ant->info) < 0)
            {
                void *inf = act->info;
                unsigned tam = act->tamBytes;

                marca = 1;
                act->info = act->ant->info;
                act->ant->info = inf;
                act->tamBytes = act->ant->tamBytes;
                act->ant->tamBytes = tam;
            }

            act = act->ant;
        }
        inf = act;
    }
}
