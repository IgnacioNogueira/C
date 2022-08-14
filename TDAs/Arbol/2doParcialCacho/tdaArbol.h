#ifndef TDAARBOL_H_INCLUDED
#define TDAARBOL_H_INCLUDED

#include "main.h"
#include "tdaColaImpListaCircular.h"
#define reservarMemoriaNodo(X,Y,Z,W) (   \
                                     ( (X) = (typeof(X))malloc((Y)) ) == NULL || \
                                     ( (Z) = malloc(W) ) == NULL ? \
                                      free(X),0:1)


typedef struct sNodoArbol
{
    void *info;
    unsigned tamInfo;
    struct sNodoArbol *izq;
    struct sNodoArbol *der;

} tNodoArbol;

typedef tNodoArbol * tArbolBinBusq;

void crearArbolBinBusq(tArbolBinBusq *p);
int arbolBinVacio(tArbolBinBusq *p);
int insertarEnArbBinBusqRec(tArbolBinBusq *p,const void *d, unsigned tam,
                            int (*cmp)(const void *,const void*));

void recorrerEnOrdenArbolBinBusqRec(const tArbolBinBusq *p, unsigned n, void * params,
                                    void (*accion)(void *,unsigned,unsigned,void *));
void recorrerEnOrdenArbolBinBusq(const tArbolBinBusq *p,void *params,
                                 void(*accion)(void *,unsigned,unsigned,void *));
void recorrerPreOrdenArbolBinBusqRec(const tArbolBinBusq *p, unsigned n, void * params,
                                     void (*accion)(void *,unsigned,unsigned,void *));
void recorrerPreOrdenArbolBinBusq(const tArbolBinBusq *p,void *params,
                                  void(*accion)(void *,unsigned,unsigned,void *));
void recorrerPostOrdenArbolBinBusqRec(const tArbolBinBusq *p, unsigned n, void * params,
                                      void (*accion)(void *,unsigned,unsigned,void *));
void recorrerPostOrdenArbolBinBusq(const tArbolBinBusq *p,void *params,
                                   void(*accion)(void *,unsigned,unsigned,void *));

unsigned alturaArbolBin(const tArbolBinBusq *p);
int esCompletoHastaNivelArbolBin(const tArbolBinBusq * p,unsigned n);
int esArbolBalanceadoBin(const tArbolBinBusq * p,unsigned n);

void vaciarArbolBinBusq(tArbolBinBusq *p);

tNodoArbol ** buscarNodoArbolBinBusqRec(const tArbolBinBusq *p, const void *d,
                                     int (*cmp)(const void *,const void*));
int buscarIndArbolBinBusq(const tArbolBinBusq *p, tProducto *prod,void *ind,unsigned tam,
                          int (*cmp)(const void *,const void*));

//int podarArbolyGuardarEnCola(tArbolBinBusq *p, unsigned n,tCola *col);
//unsigned guardarEnColaYVaciarArbol(tArbolBinBusq *p,tCola *col);
unsigned guardarEnColaYVaciarArbol(tArbolBinBusq *p,tCola *col);
unsigned podarArbolyGuardarEnCola(tArbolBinBusq *p, unsigned n,tCola *col);


#endif // TDAARBOL_H_INCLUDED
