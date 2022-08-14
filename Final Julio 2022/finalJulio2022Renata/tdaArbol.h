#ifndef TDAARBOL_H_INCLUDED
#define TDAARBOL_H_INCLUDED

#include "main.h"
#include "tdaDefiniciones.h"

#define ARBOL_NIVEL 2

void crearArbolBinBusq(tArbolBinBusq * p);

int insertarEnArbolBinBusqRec(tArbolBinBusq *p,const void *d,unsigned cantBytes,
                              int (*cmp)(const void*,const void*));

int recorrerYMostrarArbolHastaNivel(const tArbolBinBusq *p,
                                    unsigned nivel,
                                    void(*mostrar)(void *,unsigned, void *),
                                    void *paramAccion);

#endif // TDAARBOL_H_INCLUDED
