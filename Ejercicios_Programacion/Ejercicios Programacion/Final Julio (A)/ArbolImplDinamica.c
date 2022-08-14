#include "ArbolImplDinamica.h"

void crearArbol(Arbol* pa)
{
    *pa = NULL;
}

int insertarEnArbol(Arbol* pa, const void* elem, size_t tamElem, Cmp cmp)
{
    if(!*pa)
    {
        Nodo* nue = (Nodo*)malloc(sizeof(Nodo));
        void* elemNodo = malloc(tamElem);

        if(!elemNodo || !nue)
        {
            free(elemNodo);
            free(nue);
            return SIN_MEM;
        }

        memcpy(elemNodo, elem, tamElem);

        nue->elem = elemNodo;
        nue->tamElem = tamElem;
        nue->hIzq = nue->hDer = NULL;

        *pa = nue;

        return TODO_OK;
    }

    int comp = cmp(elem, (*pa)->elem);

    if(comp == 0)
        return DUPLICADO;

    return insertarEnArbol(comp < 0 ? &(*pa)->hIzq : &(*pa)->hDer, elem, tamElem, cmp);
}

int mostrarNodosDeNivel(const Arbol* pa, int n, Mostrar mostrar, void* paramAccion)
{
    if(!*pa || n < 0)
        return FALSO;

    if(n == 0)
    {
        mostrar((*pa)->elem, (*pa)->tamElem, paramAccion);
        return VERDADERO;
    }

    booleano retI = mostrarNodosDeNivel(&(*pa)->hIzq, n-1, mostrar, paramAccion);
    booleano retD = mostrarNodosDeNivel(&(*pa)->hDer, n-1, mostrar, paramAccion);

    return retI || retD;
}
