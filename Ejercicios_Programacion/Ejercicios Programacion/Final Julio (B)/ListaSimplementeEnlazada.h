#ifndef LISTASIMPLEMENTEENLAZADA_H
#define LISTASIMPLEMENTEENLAZADA_H

#include <stdlib.h>
#include <string.h>
#include "Comun.h"

typedef struct sNodo
{
    void* elem;
    size_t tamElem;
    struct sNodo* sig;
} Nodo;

typedef Nodo* Lista;

void crearLista(Lista* pl);
int insertarAlFinalDeLista(Lista* pl, const void* elem, size_t tamElem);
int eliminarDuplicadosDeListaDesord(Lista* pl, Cmp cmp, Acumular acumular);
void vaciarListaConAccion(Lista* pl, Accion accion, void* paramAccion);

#endif // LISTASIMPLEMENTEENLAZADA_H
