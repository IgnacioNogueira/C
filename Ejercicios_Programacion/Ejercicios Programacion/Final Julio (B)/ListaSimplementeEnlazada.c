#include "ListaSimplementeEnlazada.h"

void crearLista(Lista* pl)
{
    *pl = NULL;
}

int insertarAlFinalDeLista(Lista* pl, const void* elem, size_t tamElem)
{
    while(*pl)
        pl = &(*pl)->sig;

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

int eliminarDuplicadosDeListaDesord(Lista* pl, Cmp cmp, Acumular acumular)
{
    Lista* plLect;
    Nodo* nae;

    while(*pl)
    {
        plLect = &(*pl)->sig;

        while(*plLect)
        {
            if(cmp((*pl)->elem, (*plLect)->elem) == 0)
            {
                int ret = acumular(&(*pl)->elem, &(*pl)->tamElem, (*plLect)->elem, (*plLect)->tamElem);

                if(ret != TODO_OK)
                    return ret;

                nae = *plLect;
                *plLect = (*plLect)->sig;

                free(nae->elem);
                free(nae);
            }
            else
                plLect = &(*plLect)->sig;
        }

        pl = &(*pl)->sig;
    }

    return TODO_OK;
}

void vaciarListaConAccion(Lista* pl, Accion accion, void* paramAccion)
{
    Nodo* nae;

    while(*pl)
    {
        nae = *pl;
        *pl = nae->sig;

        accion(nae->elem, nae->tamElem, paramAccion);

        free(nae->elem);
        free(nae);
    }
}
