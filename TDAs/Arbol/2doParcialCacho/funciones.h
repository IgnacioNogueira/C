#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include "main.h"
#include "tdaArbol.h"
#include "tdaListaDoble.h"
#include "tdaColaImpListaCircular.h"

///MOSTRAR
int leerYMostrarArchivo(const char *nombreArchivo);
void mostrarArchivoMaestro(tProducto *prod);
void mostrarIndice (const void * info);
void recorrerArbolInOrderBasico(tArbolBinBusq *p,void (*accion)(const void *));

/// EJERCICIO 1
int cmp_ent(const void *v1,const void *v2);
int cmp_ind(const void *v1,const void *v2);
int cmp_arbol_nov(const void *v1,const void *v2);
void imprimir(void *info,unsigned tam,unsigned n,void * params);


int cargarIndiceArbolArch(const char *nombreArchivo,tArbolBinBusq *p,
                      int(*cmp)(const void *,const void*));
int guardarArbolGeneradoArchTemp(tArbolBinBusq *arb,void (*accion)(const void *dato,void *contexto));
void guardarRegIndiceArchivo(const void *dato, void *contexto);
void inOrderArchivos(tArbolBinBusq *p,void (*accion)(const void *dato, void *contexto),
                     void *param);
int cargarArbolArchivoINDTemp(tArbolBinBusq *p,int (*cmp)(const void *,const void *));
int cargarArbolArchivoINDTemp_Int(tArbolBinBusq *p,int li,int ls,FILE* archivo,
                                  int (*cmp)(const void *,const void *));

/// EJERCICIO 2

void trozarCampoLongitudVariable(char *s,tNovedad *nov);
void mostrarNovedad(const void *dv);


/// EJERCICIO 4

int ejercicio4(const char *archivoEstadosFinan, tCola *col,
               const char *archivoInforme,tArbolBinBusq *p,
               int (*cmp)(const void *,const void*));

/// EJERCICIO 5

int ejercicio5(tArbolBinBusq * p,tCola *col);


#endif // FUNCIONES_H_INCLUDED
