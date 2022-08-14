#include "tdaLista.h"
#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void crearLista(tLista *pl)
{
    *pl = NULL;
}

int listaVacia(const tLista *pl)
{
    return *pl == NULL;
}

int listaLlena(const tLista *pl,unsigned tam)
{
    tNodo *aux = (tNodo*)malloc(sizeof(tNodo));
    void *info = malloc(tam);

    free(aux);
    free(info);

    return aux == NULL || info == NULL;
}

void vaciarLista(tLista *pl)
{
    tNodo *aux;

    while(*pl)
    {
        aux = *pl;
        *pl = aux->sig;
        free(aux->info);
        free(aux);
    }
}

int ponerAlComienzo(tLista *pl,const void *d,unsigned tam)
{
    tNodo *nue;

    if((nue = (tNodo *)malloc(sizeof(tNodo)))
            || ( (nue->info = malloc(tam)) == NULL))
    {
        free(nue);
    }
    return 0;

    memcpy(nue->info,d,tam);
    nue->tamInfo = tam;
    nue->sig = *pl;
    *pl = nue;

    return 1;

}

int sacarPrimeroLista(tLista *pl,void *d,unsigned tam)
{
    tNodo *aux = *pl;

    if(aux == NULL)
        return 0;

    *pl = aux->sig;
    memcpy(d,aux->info,MINIMO(tam,aux->tamInfo));
    free(aux->info);
    free(aux);

    return 1;
}

int verPrimeroLista(const tLista *pl,void *d,unsigned tam)
{
    tNodo * aux = *pl;

    if(aux == NULL)
        return 0;

    memcpy(d,aux->info,MINIMO(tam,aux->tamInfo));
    return 1;
}

int ponerAlFinal(tLista *pl,const void *d,unsigned tam)
{
    tNodo *nue;

    while(*pl)
        pl = &(*pl)->sig;

    if((nue = (tNodo*)malloc(sizeof(tNodo)))
            ||  ((nue->info = malloc(tam)) == NULL) )
    {
        free(nue);
        return 0;
    }
    memcpy(nue->info,d,tam);
    nue->tamInfo = tam;
    nue->sig = NULL;
    *pl = nue;

    return 1;
}

int sacarUltLista(tLista *pl,void *d,unsigned tam)
{
    if(*pl == NULL)
        return 0;

    while(*pl)
        pl = &(*pl)->sig;

    memcpy(d,(*pl)->info,MINIMO(tam,(*pl)->tamInfo));
    free((*pl)->info);
    free((*pl));
    (*pl) = NULL;

    return 1;
}

int verUltLista(const tLista *pl,void *d,unsigned tam)
{
    if(*pl == NULL)
        return 0;

    while(*pl)
    {
        pl = &(*pl)->sig;
    }

    memcpy(d,(*pl)->info,MINIMO(tam,(*pl)->tamInfo));

    return 1;
}

int ponerPosList(tLista *pl,const void *d,unsigned tam,unsigned pos)
{
    tNodo * nue;

    while(*pl && pos)
    {
        pl = &(*pl)->sig;
        --pos;
    }

    if( ((nue = (tNodo *)malloc(sizeof(tNodo))) == NULL) || ((nue->info = malloc(tam))) == NULL )
    {
        free(nue);
        return 0;
    }

    memcpy(nue->info,d,tam);
    nue->tamInfo = tam;
    nue->sig = *pl;
    *pl = nue;

    return 1;
}

int ponerEnLista(tLista *pl,)



int cmp(const void* d1,const void* d2)
{
    return *(int*)d1 - *(int*)d2;
}

int ponerOrdenLista(tLista *pl,const void *d,unsigned tam,int (*cmp)(const void*, const void*))
{
    tNodo *nue;

    while(*pl && cmp(d,(*pl)->info) > 0) //mientras lo de la derecha siga siendo mayor
    {
        pl = &(*pl)->sig;
    }

    if(*pl && cmp(d,(*pl)->info) == 0)
    {
        return 0; //duplicado
    }

    if( ((nue = (tNodo *)malloc(sizeof(tNodo))) == NULL) || ((nue->info = malloc(tam)) == NULL))
    {
        free(nue);
        return 0;
    }

    memcpy(nue->info,d,sizeof(tam));
    nue->tamInfo = tam;
    nue->sig = *pl;
    *pl = nue;

    return 1;
}


tLista* buscarMenorEntLista(tLista *pl,int (*cmp)(const void*,const void*))
{
    tLista* menor = pl; //mantengo la dirección del primero de la lista
    pl = &(*pl)->sig; //para comparar el sig

    if(*pl == NULL)
        return 0;

    while(*pl)
    {
        if(cmp((*pl)->info,(*menor)->info) < 0)
        {
            menor = pl;
        }

        pl = &(*pl)->sig; //equivalente:++lista;
    }

    return menor;
}

tLista* buscarMayorEntLista(tLista *pl,int (*cmp)(const void*,const void*))
{
    tLista* mayor = pl; //mantengo la dirección del primero de la lista
    pl = &(*pl)->sig; //para comparar el sig

    if(*pl == NULL)
        return 0;

    while(*pl)
    {
        if(cmp((*pl)->info,(*mayor)->info) > 0)
        {
            mayor = pl;
        }

        pl = &(*pl)->sig; //equivalente:++lista;
    }

    return mayor;
}

void mostrar(void *info)
{
    tPedidos* ped = (tPedidos*)info;
    printf("\n-Id de cliente:%*.*s\n-Id producto:%li\n-Cantidad pedida:%d\nPrecio unitario:%.2f\n\n",
           (int)sizeof(ped->idCliente)-1,
           (int)sizeof(ped->idCliente)-1,
           ped->idCliente,
           ped->idProd,
           ped->cantPed,
           ped->precUnitario
          );
}

void mostrarLista(tLista *pl)
{
    while(*pl)
    {
        mostrar((*pl)->info);
        pl = &(*pl)->sig;
    }
}

/*
int ponerEnOrdenyAcum(tLista *pl,const void *d,unsigned cantBytes,
                 int(*cmpStr)(const void *,const void *),
                 int (*acum)(void**,unsigned *,const void *,unsigned))
{
    tNodo * nue;

    while(*pl && cmpStr((*p)->info,d) < 0)





}

*/ //si ya hay una lista previa


int eliminarPosLista(tLista *pl,void *d,unsigned tam,unsigned pos)
{
    tNodo *elim = *pl;

    if(*pl == NULL)
        return 0;

    while(*pl && pos)
    {
        pl = &(*pl)->sig;
    }

    *pl = elim->sig;
    memcpy(d,elim->info,MINIMO(tam,elim->tamInfo));
    free(elim->info);
    free(elim);

    return 1;
}

int eliminarDupLista(tLista *pl,int(*cmp)(const void *,const void *))
{
    tNodo *actual,*elim;

    if(*pl == NULL)
        return 0;

    while((*pl)->sig)
    {
        actual = *pl;
        while(actual->sig)
        {
            if(actual->sig && cmp((*pl)->info,(actual->sig)->info) == 0)
            {
                elim = actual->sig;
                actual->sig = elim->sig;
                free(elim->info);
                free(elim);
            }
            else
            {
                actual = actual->sig;
            }
        }
        if((*pl)->sig)
        {
            pl = &(*pl)->sig;
        }
    }

    return 1;
}



int eliminarAcumulando(tLista *pl,
                       int (*cmp)(const void*,const void*),
                       int (*acum)(void **,unsigned *,const void *,unsigned));

int eliminarAcumulando(tLista *pl,
                       int (*cmp)(const void*,const void*),
                       int (*acum)(void **,unsigned *,const void *,unsigned))
{
    tLista *pComp;
    tNodo *aux;

    int cant = 0;

    while(*pl)
    {
        pComp = &(*pl)->sig;

        while(*pComp)
        {
            if(cmp((*pl)->info,(*pComp)->info) == 0)
            {
                if(acum)
                    if(acum(&(*pl)->info,&(*pl)->tamInfo,(*pComp)->info,(*pComp)->tamInfo) != 1)
                        return 0; //sin mem

                aux = *pComp;
                *pComp = aux->sig;

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



    return cant;
}




/* está mal el acum, faltan cosas -> mirar ejemplos de parciales que hice */
//void acumularCantPed(const void *d1,const void *d2)
//{
//    const tPedidos *p1 = (tPedidos *)d1;
//    tPedidos *p2 = (tPedidos *)d2;
//
//    p1->cantPed+=p2->cantPed;
//}


/*
void* acum(void**dLista,unsigned *ptInfo,const void *d,unsigned cantBytes)
{
    char *pri = (char*)dLista;
    tPedidos * sig = (tPedidos*)d;

    *pri += sig->idCliente;
    return pri;
}
*/

int cmpStr(const void* d1,const void* d2)
{

    //tPedidos id1 = (tPedidos*)d1->idCliente;
    //tPedidos id2 = (tPedidos*)d2->idCliente;

//    if(strcmp(id1,id2) == 0)
//        return 1;

    return 0;
}


int eliminaryAcumDupLista(tLista *pl,
                          int(*cmpStr)(const void *,const void *),
                          int(*acum)(void**,unsigned *,const void *,unsigned))
{
    //tNodo *actual;

    if(*pl == NULL)
        return 0;

    while((*pl)->sig)
    {
        //actual = (*pl)->sig;

        /*
        while(actual && cmpStr(actual->info,(*pl)->info == 0))
        {
            //acum(&(*pl)->info,(*pl)->tamInfo);
            (*pl)->sig = actual->sig;
            free(actual->info);
            free(actual);
            actual = (*pl)->sig;
        }*/
        if((*pl)->sig)
            pl = &(*pl)->sig;
    }

    return 1;
}

/*
int indicesLista(tLista *pl)
{
    int cont = 1;
    tIndice ind;

    if()

    while(*pl)
    {
        ind->clave = ;
        ind->pos = cont;
        ++cont;
    }
    return 1;
}

*/
