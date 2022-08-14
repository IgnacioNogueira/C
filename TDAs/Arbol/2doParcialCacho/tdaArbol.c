#include "tdaArbol.h"
#include "tdaColaImpListaCircular.h"

void crearArbolBinBusq(tArbolBinBusq *p)
{
    *p = NULL;
}

int arbolBinVacio(tArbolBinBusq *p)
{
    return *p == NULL;
}

int insertarEnArbBinBusqRec(tArbolBinBusq *p,const void *d, unsigned tam,
                            int (*cmp)(const void *,const void*))
{
    tNodoArbol *nue;
    int rc;

    if(*p)
    {
        if((rc = cmp(d,(*p)->info)) < 0)
            return insertarEnArbBinBusqRec(&(*p)->izq,d,tam,cmp);
        if(rc > 0)
            return insertarEnArbBinBusqRec(&(*p)->der,d,tam,cmp);

        return CLA_DUP;
    }

    if( (nue = (tNodoArbol *)malloc(sizeof(tNodoArbol))) == NULL
            || (nue->info = malloc(tam)) == NULL)
    {
        free(nue);
        return SIN_MEM;
    }

    nue->tamInfo = tam;
    memcpy(nue->info,d,tam);
    nue->der = NULL;
    nue->izq = NULL;
    *p = nue;
    return TODO_BIEN;
}

void recorrerEnOrdenArbolBinBusqRec(const tArbolBinBusq *p, unsigned n, void * params,
                                    void (*accion)(void *,unsigned,unsigned,void *))
{
    if(!*p)
        return;

    recorrerEnOrdenArbolBinBusqRec(&(*p)->izq,n+1,params,accion);
    accion((*p)->info,(*p)->tamInfo,n,params);
    recorrerEnOrdenArbolBinBusqRec(&(*p)->der,n+1,params,accion);
}

void recorrerEnOrdenArbolBinBusq(const tArbolBinBusq *p,void *params,
                                 void(*accion)(void *,unsigned,unsigned,void *))
{
    recorrerEnOrdenArbolBinBusqRec(p,0,params,accion);
}

void recorrerPreOrdenArbolBinBusqRec(const tArbolBinBusq *p, unsigned n, void * params,
                                     void (*accion)(void *,unsigned,unsigned,void *))
{
    if(!*p)
        return;

    accion((*p)->info,(*p)->tamInfo,n,params);
    recorrerPreOrdenArbolBinBusqRec(&(*p)->izq,n+1,params,accion);
    recorrerPreOrdenArbolBinBusqRec(&(*p)->der,n+1,params,accion);
}

void recorrerPreOrdenArbolBinBusq(const tArbolBinBusq *p,void *params,
                                  void(*accion)(void *,unsigned,unsigned,void *))
{
    recorrerPreOrdenArbolBinBusqRec(p,0,params,accion);
}

void recorrerPostOrdenArbolBinBusqRec(const tArbolBinBusq *p, unsigned n, void * params,
                                      void (*accion)(void *,unsigned,unsigned,void *))
{
    if(!*p)
        return;

    recorrerPostOrdenArbolBinBusqRec(&(*p)->izq,n+1,params,accion);
    recorrerPostOrdenArbolBinBusqRec(&(*p)->der,n+1,params,accion);
    accion((*p)->info,(*p)->tamInfo,n,params);
}

void recorrerPostOrdenArbolBinBusq(const tArbolBinBusq *p,void *params,
                                   void(*accion)(void *,unsigned,unsigned,void *))
{
    recorrerPostOrdenArbolBinBusqRec(p,0,params,accion);
}

unsigned alturaArbolBin(const tArbolBinBusq *p)
{
    unsigned hi,hd;

    if(!*p)
        return 0;

    hi = alturaArbolBin(&(*p)->izq) +1;
    hd = alturaArbolBin(&(*p)->der) +1;

    return hi > hd ? hi : hd;
}

int esCompletoHastaNivelArbolBin(const tArbolBinBusq * p,unsigned n)
{
    if(!*p)
        return 0;

    if(n == 0)
    {
        return 1;
    }

    return esCompletoHastaNivelArbolBin(&(*p)->izq,n-1) &&
           esCompletoHastaNivelArbolBin(&(*p)->der,n-1);
}

int esArbolBalanceadoBin(const tArbolBinBusq * p,unsigned n)
{
    return esCompletoHastaNivelArbolBin(p,alturaArbolBin(p)-2);
}

void vaciarArbolBinBusq(tArbolBinBusq *p)
{
    if(!*p)
        return;

    vaciarArbolBinBusq(&(*p)->izq);
    vaciarArbolBinBusq(&(*p)->der);

    free((*p)->info);
    free((*p));
    *p = NULL;
}

tNodoArbol ** buscarNodoArbolBinBusqRec(const tArbolBinBusq *p, const void *d,
                                     int (*cmp)(const void *,const void*))
{
    int rc;

    if(!*p)
        return NULL;

    if(*p && (rc = cmp((*p)->info,d)) != 0)
    {
        if(rc < 0)
            return buscarNodoArbolBinBusqRec(&(*p)->izq,d,cmp);

        return buscarNodoArbolBinBusqRec(&(*p)->der,d,cmp);
    }

    return (tNodoArbol **)p;
}

int buscarIndArbolBinBusq(const tArbolBinBusq *p, tProducto *prod,void *ind,unsigned tam,
                          int (*cmp)(const void *,const void*))
{
    if(!(p = buscarNodoArbolBinBusqRec(p,prod,cmp)))
    {
        return 0;
    }

    memcpy(ind,(*p)->info,MINIMO((*p)->tamInfo,tam));
    return TODO_BIEN;
}

unsigned guardarEnColaYVaciarArbol(tArbolBinBusq *p,tCola *col)
{
    int nodoIzq;
    int nodoDer;

    if(!*p)
        return 0;

    nodoIzq = guardarEnColaYVaciarArbol(&(*p)->izq,col);
    nodoDer = guardarEnColaYVaciarArbol(&(*p)->der,col);

    ponerEnColaCir(col,(*p)->info,sizeof(tArbolBinBusq));
    free((*p)->info);
    free((*p));
    *p = NULL;

    return nodoIzq + nodoDer + 1;
}

unsigned podarArbolyGuardarEnCola(tArbolBinBusq *p, unsigned n,tCola *col)
{
    int izq;
    int der;

    if(!*p)
        return 0;

    if(n == 0)
    {
       return guardarEnColaYVaciarArbol(p,col);
    }
    else
    {
        izq = podarArbolyGuardarEnCola(&(*p)->izq,n-1,col);
        der = podarArbolyGuardarEnCola(&(*p)->der,n-1,col);
    }

    return izq + der;
}

/*
unsigned guardarEnColaYVaciarArbol(tArbolBinBusq *p,tCola *col)
{
    if(!*p)
        return 0;

           guardarEnColaYVaciarArbol(&(*p)->izq,col)
         + guardarEnColaYVaciarArbol(&(*p)->der,col)
         + 1;

    ponerEnColaCir(col,(*p)->info,sizeof(tArbolBinBusq));
    free((*p)->info);
    free(*p);
    *p = NULL;
}

int podarArbolyGuardarEnCola(tArbolBinBusq *p, unsigned n,tCola *col)
{
    int cant;

    if(!*p)
        return 0;

    if(n == 0)
    {
       cant = guardarEnColaYVaciarArbol(p,col);
    }
    else
    {
        return podarArbolyGuardarEnCola(&(*p)->izq,n-1,col);
        return podarArbolyGuardarEnCola(&(*p)->der,n-1,col);
    }

    return cant;
}
*/
