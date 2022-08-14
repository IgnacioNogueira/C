#ifndef PILADINAMICA_H
#define PILADINAMICA_H

#include <stdlib.h>
#include <string.h>

#define min(a,b) ((a) <= (b) ? (a) : (b))

typedef enum
{
    FALSO, VERDADERO
}booleano;

typedef struct sNodo
{
    void* elem;
    size_t tamElem;
    struct sNodo* sig;
}Nodo;

typedef Nodo* Pila;

void crearPila(Pila* pp);
booleano ponerEnPila(Pila* pp, const void* elem, size_t tamElem);
booleano sacarDePila(Pila* pp, void* elem, size_t tamElem);
booleano verTopeDePila(Pila* pp, void* elem, size_t tamElem);
booleano pilaVacia(const Pila* pp);
booleano pilaLlena(const Pila* pp, size_t tamElem);
void vaciarPila(Pila* pp);

#endif // PILADINAMICA_H
