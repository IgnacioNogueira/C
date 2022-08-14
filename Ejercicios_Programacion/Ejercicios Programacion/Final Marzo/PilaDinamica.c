#include "PilaDinamica.h"

void crearPila(Pila* pp)
{
    *pp = NULL;
}

booleano ponerEnPila(Pila* pp, const void* elem, size_t tamElem)
{
    Nodo* nue = (Nodo*)malloc(sizeof(Nodo));
    void* elemNodo = malloc(tamElem);

    if(!nue || !elemNodo)
    {
        free(elemNodo);
        free(nue);
        return FALSO;
    }

    memcpy(elemNodo, elem, tamElem);

    nue->elem = elemNodo;
    nue->tamElem = tamElem;
    nue->sig = *pp;

    *pp = nue;

    return VERDADERO;
}

booleano sacarDePila(Pila* pp, void* elem, size_t tamElem)
{
    if(!*pp)
        return FALSO;

    Nodo* nae = *pp;

    memcpy(elem, nae->elem, min(tamElem, nae->tamElem));

    *pp = nae->sig;

    free(nae->elem);
    free(nae);

    return VERDADERO;
}

booleano verTopeDePila(Pila* pp, void* elem, size_t tamElem)
{
    if(!*pp)
        return FALSO;

    Nodo* tope = *pp;

    memcpy(elem, tope->elem, min(tamElem, tope->tamElem));

    return VERDADERO;
}

booleano pilaVacia(const Pila* pp)
{
    return *pp == NULL;
}

booleano pilaLlena(const Pila* pp, size_t tamElem)
{
    void* nue = malloc(sizeof(Nodo));
    void* elemNodo = malloc(tamElem);

    free(elemNodo);
    free(nue);

    return !nue || !elemNodo;
}

void vaciarPila(Pila* pp)
{
    Nodo* nae = *pp;

    while(nae)
    {
        *pp = nae->sig;

        free(nae->elem);
        free(nae);

        nae = *pp;
    }
}
