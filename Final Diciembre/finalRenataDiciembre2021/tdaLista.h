#ifndef TDALISTA_H_INCLUDED
#define TDALISTA_H_INCLUDED

#include "header.h"

#define CLA_DUP 1
#define SIN_MEM 2
#define CLA_DUP_EXC 3
#define ERR_EXC 4

#define MINIMO(X,Y)( (X)<=(Y) ? (X):(Y))

typedef struct sNodo
{
    void *info;
    unsigned tamInfo;
    struct sNodo *ant;
    struct sNodo *sig;

}tNodo;

typedef tNodo *tListaD;


void crearListaDoble(tListaD *p);

int insertarYAcumularListaDoble(tListaD * p,const void *d,unsigned cantBytes,
                                int (*cmp)(const void *,const void *),
                                int (*acum)(void **,unsigned *,const void *,unsigned));

int recorrerListaIzqADer(const tListaD *pl,void (*mostrar)(const void*));
int sacarPrimeroDeListaDoble(tListaD *pl,void *d,unsigned cantBytes);
int eliminarNUltimosListaDoble(tListaD *pl,unsigned n);

#endif // TDALISTA_H_INCLUDED
