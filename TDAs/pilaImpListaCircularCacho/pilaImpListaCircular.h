#ifndef LISTACIRCULAR_H_INCLUDED
#define LISTACIRCULAR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MINIMO(X,Y)((X) <=(Y) ? (X) : (Y))

/*
    - Pila:
    El puntero de la lista NOOO se mueve al ingresar los datos
    El primero sabe cuál es el últ ingresado
*/

typedef struct sNodo
{
    void *info;
    unsigned tamInfo;
    struct sNodo *sig;
}tNodo;

typedef tNodo * tPila;

void crearPila(tPila *p);
int pilaVacia(const tPila *p);
int pilaLlena(const tPila *p,unsigned cantBytes);
int ponerEnPilaCircular(tPila *p,const void *d,unsigned cantBytes);
int sacarDePilaCircular(tPila *p,void *d,unsigned cantBytes);
int verTope(tPila *p,void *d,unsigned cantBytes);
void vaciarPila(tPila *p);

//practica
int ponerEnPilaCircular_MIO(tPila *p, const void * d, unsigned cantBytes);
int sacarDePilaCircular_MIO(tPila *p,void * d, unsigned cantBytes);




#endif // LISTACIRCULAR_H_INCLUDED
