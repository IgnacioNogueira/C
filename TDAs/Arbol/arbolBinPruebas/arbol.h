#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#include <string.h>
#include <stdlib.h>
#include "estructuras.h"

typedef struct sNodo
{
    void *info;
    unsigned tamInfo;
    struct sNodo *der;
    struct sNodo *izq;
}tNodo;

typedef tNodo* tArbol;

void crearArbol(tArbol *p);
int arbolVacio(const tArbol *p);

int insertarAcumulandoEnArbol(tArbol *p,const void *d,unsigned cantBytes,
                              int (*cmp)(const void *,const void *),
                              int (*acum)(void **,unsigned *,const void *,unsigned));
int ponerEnOrden(tArbol *p, const void *d, unsigned tam,
                    int (*comp)(const void *, const void *));
void recorrerEnOrden(const tArbol *p, void (*mostrar)(const void *));
void recorrerPreOrden(const tArbol *p, void (*mostrar)(const void *));
void recorrerPosOrden(const tArbol *p, void (*mostrar)(const void *));
unsigned contarNodosPorCritCorrecto(const tArbol *p, unsigned (*crit)(const void *, unsigned));
unsigned contarNodosPorCrit(const tArbol *p, int (*crit)(const void *));
unsigned recuperarDeArbol(const tArbol *p, void *bus, unsigned tamBus,
                          int (*comp)(const void *, const void *));
int ponerEnOrdenAcum(tArbol *p, const void *d, unsigned tam,
                    int (*comp)(const void *, const void *),
                    int (*acum)(void **, unsigned *, const void *, unsigned));

void vaciarArbol(tArbol *p);
void podarHastaAltura(tArbol *p, int h);

int cmpNodosPares(const void *v1, unsigned tamNodoInfo);

int contarNodosCondicion(const tArbol *p,
                         int (*cmp)(const void *,unsigned));
int contarNodosCondicionPorLadoIzq(const tArbol *p,
                                   int (*cmp)(const void *,unsigned));

#endif // ARBOL_H_INCLUDED
