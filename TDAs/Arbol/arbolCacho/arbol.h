#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define CLA_DUP 1
#define ERROR_ACUM -1
#define SIN_MEM 1
#define SIN_INICIALIZAR 1
#define ERROR_ARCH 1
#define TODO_BIEN 0
#define MINIMO(X,Y)( (X)<=(Y)?(X):(Y) )

#include "funciones.h"

typedef struct sNodoArbol
{
    void *info;
    unsigned tamInfo;
    struct sNodoArbol *izq,
                      *der;

}tNodoArbol;

typedef tNodoArbol * tArbolBinBusq;


void crearArbolBinBusq(tArbolBinBusq *p);
int insertarAcumulandoArbolBinBusq(tArbolBinBusq *p,const void *d,unsigned tam,
                                   int (*cmp)(const void *,const void*),
                                   int (*acum)(void **,unsigned *,const void *,unsigned));
int insertarArbolBinBusq(tArbolBinBusq *p,const void *d, unsigned tam,
                         int (*cmp)(const void *,const void *));

int insertarEnArbBinBusqRec(tArbolBinBusq *p,const void *d, unsigned tam,
                            int (*cmp)(const void *,const void*));

//Recursivas:

int cargarDesdeDatosOrdenadosRec(tArbolBinBusq *p,void *ds,
                                 unsigned (*leer)(void **, void *,unsigned, void * params),
                                 int li,int ls,void *params);

int cargarDesdeDatOrdenArbolBinRec(tArbolBinBusq * p,void *ds, unsigned cantReg,
                                   unsigned (*leer)(void **,void *,unsigned,void * params),void * params);

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

void recorrerOrdenInversoArbolBinBusqRec(const tArbolBinBusq *p, unsigned n, void * params,
                                      void (*accion)(void *,unsigned,unsigned,void *));

void recorrerOrdenInversoArbolBinBusq(const tArbolBinBusq *p,void *params,
                                 void(*accion)(void *,unsigned,unsigned,void *));

unsigned alturaArbolBin(const tArbolBinBusq *p);
tNodoArbol ** menorNodoArbolArbolBinBusqRec(const tArbolBinBusq *p);
tNodoArbol ** mayorNodoArbolArbolBinBusqRec(const tArbolBinBusq *p);
tNodoArbol ** buscarNodoArbolBinBusqRec(const tArbolBinBusq *p,const void *d,
                              int (*cmp)(const void *, const void *));
int buscarElemArbolBinBusq(const tArbolBinBusq *p,void *d,unsigned tam,
                              int (*cmp)(const void *,const void *));
int eliminarRaizArbolBinBusq(tArbolBinBusq *p);
int eliminarElemArbolBinBusq(tArbolBinBusq *p,void *d,unsigned tam,
                             int (*cmp)(const void *,const void *));

void vaciarArbolBinBusq(tArbolBinBusq *p);
void podarArbol(tArbolBinBusq *p, unsigned nivel);
void podarArbolXNivel(tArbolBinBusq *p,unsigned nivel,unsigned nivelActual);
void podarArbolXNivelMain(tArbolBinBusq *p,unsigned nivel);
void podarHojas(tArbolBinBusq *p);

int accionContarPares(const void *info,unsigned tam);
unsigned cantNodosArbolBinPares(const tArbolBinBusq *p,
                                int(*accion)(const void *,unsigned));
unsigned cantNodosArbolBinHastaNivel(const tArbolBinBusq *p,unsigned n,
                                     int(*accion)(const void *,unsigned));
unsigned cantNodosArbolBinParesLadoIzq(const tArbolBinBusq *p,int(*accion)(const void *,unsigned));
unsigned cantNodosArbolBinParesLadoIzqHastaNivelN(const tArbolBinBusq *p, unsigned n);

int esCompletoHastaNivelArbolBin(const tArbolBinBusq * p,unsigned n);
int esArbolCompletoBin(const tArbolBinBusq *p);
int esCompletoArbolBin2(const tArbolBinBusq *p);
int esArbolBalanceadoBin(const tArbolBinBusq * p,unsigned n);

int contarNodosCondicion(const tArbolBinBusq *p,
                         int (*cmp)(const void *,unsigned));
int contarNodosCondicionPorLadoIzq(const tArbolBinBusq *p,
                                   int (*cmp)(const void *,unsigned));



#endif // ARBOL_H_INCLUDED
