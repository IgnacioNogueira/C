#ifndef ARBOLIMPLDINAMICA_H
#define ARBOLIMPLDINAMICA_H

#include <stdlib.h>
#include <string.h>

#define TODO_OK 0
#define SIN_MEM 1
#define DUPLICADO 2

typedef enum
{
    FALSO, VERDADERO
} booleano;

typedef struct sNodo
{
    void* elem;
    size_t tamElem;
    struct sNodo* hDer;
    struct sNodo* hIzq;
} Nodo;

typedef Nodo* Arbol;

typedef int (*Cmp)(const void*, const void*);
typedef void (*Mostrar)(const void*, size_t, void*);

void crearArbol(Arbol* pa);
int insertarEnArbol(Arbol* pa, const void* elem, size_t tamElem, Cmp cmp);
int mostrarNodosDeNivel(const Arbol* pa, int n, Mostrar mostrar, void* paramAccion);

#endif // ARBOLIMPLDINAMICA_H
