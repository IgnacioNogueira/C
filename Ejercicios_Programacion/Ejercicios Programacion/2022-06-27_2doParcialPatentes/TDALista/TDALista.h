#ifndef TDALISTA_H
#define TDALISTA_H

#include "../Comun/Comun.h"


#ifdef TDA_LISTA_IMPL_DINAMICA
    #include "../TDAListaImplDinamica/TDAListaImplDinamica.h"
#endif

#ifdef TDA_LISTA_IMPL_DINAMICA_DOBLE
    #include "../TDAListaImplDinamicaDoble/TDAListaImplDinamicaDoble.h"
#endif


void crearLista(Lista* pl);
int insertarEnListaOrd(Lista* pl, const void* elem, size_t tamElem, Cmp cmp);
int insertarEnListaOrdCDup(Lista* pl, const void* elem, size_t tamElem, Cmp cmp);
int insertarOActualizarEnListaOrd(Lista* pl, const void* elem, size_t tamElem, Cmp cmp, Actualizar actualizar);
int insertarEnListaAlInicio(Lista* pl, const void* elem, size_t tamElem);
int insertarEnListaAlFinal(Lista* pl, const void* elem, size_t tamElem);
int insertarEnListaEnPosicion(Lista* pl, const void* elem, size_t tamElem, unsigned pos);
booleano buscarEnListaOrd(const Lista* pl, void* elem, size_t tamElem, Cmp cmp);
booleano buscarEnListaDesord(const Lista* pl, void* elem, size_t tamElem, Cmp cmp);
booleano verPrimeroDeLista(const Lista* pl, void* elem, size_t tamElem);
void recorrerLista(Lista* pl, Accion accion, void* elemsAccion);
booleano eliminarDeListaOrdPorValor(Lista* pl, void* elem, size_t tamElem, Cmp cmp);
booleano eliminarDeListaDesordPorValor(Lista* pl, void* elem, size_t tamElem, Cmp cmp);
int eliminarDeListaOrdPorCondicion(Lista* pl, Condicion condicion);
booleano eliminarDeListaPrimero(Lista* pl, void* elem, size_t tamElem);
booleano eliminarDeListaUltimo(Lista* pl, void* elem, size_t tamElem);
int eliminarDeListaOrdDuplicados(Lista* pl, Cmp cmp, Actualizar actualizar);
int eliminarDeListaDesordDuplicados(Lista* pl, Cmp cmp, Actualizar actualizar);
void ordenarLista(Lista* pl, Cmp cmp);
booleano listaVacia(const Lista* pl);
booleano listaLlena(const Lista* pl, size_t tamElem);
void vaciarLista(Lista* pl);


#endif // TDALISTA_H
