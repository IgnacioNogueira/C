#ifndef PILADINAMICA_H_INCLUDED
#define PILADINAMICA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIN_MEM 0
#define TODO_BIEN 1

#define MINIMO(X,Y)( (X) <= (Y) ? (X) : (Y))

typedef struct sNodoPila
{
    void *info;
    unsigned tamInfo;
    struct sNodoPila *sig;

}tNodoPila;

typedef tNodoPila * tPila;

void crearPila(tPila *p);
int insertarEnPila(tPila *p,const void *d,unsigned tam);
int sacarDePila(tPila *p,void *d,unsigned tam);
void vaciarPila(tPila *p);
int verTopePila(const tPila *p,void *d,unsigned tam);

#endif // PILADINAMICA_H_INCLUDED
