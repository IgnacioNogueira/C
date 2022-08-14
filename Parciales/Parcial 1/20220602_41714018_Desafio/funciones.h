#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

typedef struct sNodo
{
    void           *info;
    unsigned        tamInfo;
    struct sNodo   *sig;
} tNodo;

typedef tNodo *tLista;

#define MINIMO(X,Y)((X)<=(Y)?(X):(Y))

#endif // FUNCIONES_H_INCLUDED
