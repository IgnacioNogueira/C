#ifndef COLAIMPLISTACIRCULAR_H_INCLUDED
#define COLAIMPLISTACIRCULAR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MINIMO(X,Y)((X)<=(Y) ? (X):(Y))

/*
    El puntero de la lista
    pasa a apuntar al nuevo nodo

    el último sabe cuál es el primero ingresado

*/
typedef struct sNodo
{
    void *info;
    unsigned tamInfo;
    struct sNodo *sig;


}tNodo;

typedef tNodo * tCola;

void crearCola(tCola *pc);
int colaLLena(tCola *pc,unsigned cantBytes);
int colaVacia(tCola *pc);
int ponerEnColaCir(tCola *pc, const void *d,unsigned cantBytes);
int sacarEnColaCir(tCola *pc,void *d,unsigned cantBytes);
void vaciarCola(tCola *pc);
int verPrimeroCola(tCola *pc,void *d,unsigned cantBytes);

#endif // COLAIMPLISTACIRCULAR_H_INCLUDED
