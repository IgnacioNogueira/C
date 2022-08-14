#ifndef LISTADINAMICASIMPLE_H
#define LISTADINAMICASIMPLE_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define TODO_OK 0
#define DUPLICADO 1
#define SIN_MEM 2

#define min(a,b) ((a) <= (b) ? (a) : (b))

typedef enum
{
    FALSO, VERDADERO
} booleano;

typedef struct sNodo
{
    void* elem;
    size_t tamElem;
    struct sNodo* sig;
} Nodo;

typedef Nodo* Lista;

typedef int (*Cmp)(const void*, const void*);
typedef void (*Grabar)(const void*, size_t, FILE*);

void crearLista(Lista* pl);
int insertarEnListaOrd(Lista* pl, const void* elem, size_t tamElem, Cmp cmp);
void vaciarListaYGrabarEnArch(Lista* pl, Grabar grabar, FILE* nomArch);

typedef struct
{
    Nodo* pri;
    Nodo* act;
} Iterador;

booleano crearIterador(Iterador* it, Lista* pl);
booleano primeroDeLista(Iterador* it, void* elem, size_t tamElem);
booleano siguienteDeLista(Iterador* it, void* elem, size_t tamElem);
booleano haySiguienteDeLista(const Iterador* it);
booleano finDeLista(const Iterador* it);

#endif // LISTADINAMICASIMPLE_H
