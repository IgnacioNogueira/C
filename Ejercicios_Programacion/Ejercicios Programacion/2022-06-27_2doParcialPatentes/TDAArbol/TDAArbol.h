#ifndef TDAARBOL_H
#define TDAARBOL_H

#include "../Comun/Comun.h"

#ifdef TDA_ARBOL_IMPL_DINAMICA
#include "../TDAArbolImplDinamica/TDAArbolImplDinamica.h"
#endif


typedef void (*ImprimirElemArbol)(const void* elem, void* datosImprimir, int nivel);


void crearArbol(Arbol* pa);
booleano buscarEnArbol(const Arbol* pa, void* dato, size_t tamElem, Cmp cmp);
int insertarEnArbol(Arbol* pa, void* dato, size_t tamElem, Cmp cmp);
int insertarOActualizarEnArbol(Arbol* pa, void* dato, size_t tamElem, Cmp cmp, Actualizar actualizar);
booleano eliminarDeArbol(Arbol* pa, void* dato, size_t tamElem, Cmp cmp);
int alturaArbol(const Arbol* pa);
int cantElementosArbol(const Arbol* pa);
booleano grabarArbol(const Arbol* pa, const char* nomArch);
booleano cargarArbolDeArchivoOrdenado(Arbol* pa, size_t tamElem, const char* nomArch);
booleano cargarArbolDeArchivoPreorden(Arbol* pa, size_t tamElem, const char* nomArch, Cmp cmp);
void recorrerArbolPreOrden(Arbol* pa, Accion accion, void* datosAccion);
void recorrerArbolEnOrden(Arbol* pa, Accion accion, void* datosAccion);
void recorrerArbolPosOrden(Arbol* pa, Accion accion, void* datosAccion);
booleano arbolCompleto(const Arbol* pa);
booleano arbolBalanceado(const Arbol* pa);
booleano arbolAVL(const Arbol* pa);
int podarArbol(Arbol* pa, int nivel);
int eliminarNivelDeArbol(Arbol* pa, int nivel);
int vaciarArbol(Arbol* pa);
void imprimirArbol(const Arbol* pa, ImprimirElemArbol imprimir, void* datosImprimir);


#endif // TDAARBOL_H
