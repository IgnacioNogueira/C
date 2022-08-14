#include "ListaDinamicaSimple.h"

void crearLista(Lista* pl)
{
    *pl = NULL;
}

int insertarEnListaOrd(Lista* pl, const void* elem, size_t tamElem, Cmp cmp)
{
    while(*pl && cmp(elem, (*pl)->elem) > 0)
        pl = &(*pl)->sig;

    if(*pl && cmp(elem, (*pl)->elem) == 0)
        return DUPLICADO;

    Nodo* nue = (Nodo*)malloc(sizeof(Nodo));
    void* elemNodo = malloc(tamElem);

    if(!nue || !elemNodo)
    {
        free(elemNodo);
        free(nue);
        return SIN_MEM;
    }

    memcpy(elemNodo, elem, tamElem);

    nue->elem = elemNodo;
    nue->tamElem = tamElem;
    nue->sig = *pl;

    *pl = nue;

    return TODO_OK;
}

void vaciarListaYGrabarEnArch(Lista* pl, Grabar grabar, FILE* nomArch)
{
    Nodo* nae = *pl;
    while(nae)
    {
        grabar(nae->elem, nae->tamElem, nomArch);

        *pl = nae->sig;

        free(nae->elem);
        free(nae);

        nae = *pl;
    }
}

booleano crearIterador(Iterador* it, Lista* pl)
{
    if(!*pl)
        return FALSO;

    it->pri = *pl;
    it->act = NULL;

    return VERDADERO;
}

booleano primeroDeLista(Iterador* it, void* elem, size_t tamElem)
{
    if(!it->pri)
        return FALSO;

    it->act = it->pri;

    memcpy(elem, it->act->elem, min(tamElem, it->act->tamElem));

    return VERDADERO;
}

booleano siguienteDeLista(Iterador* it, void* elem, size_t tamElem)
{
    if(!it->act || !it->act->sig) // Lazy comparison
    {
        it->act = NULL;
        return FALSO;
    }

    it->act = it->act->sig;
    memcpy(elem, it->act->elem, min(tamElem, it->act->tamElem));

    return VERDADERO;
}

booleano haySiguienteDeLista(const Iterador* it)
{
    if(!it->act)
        return FALSO;

    return it->act->sig != NULL;
}

booleano finDeLista(const Iterador* it)
{
    return it->act == NULL;
}
