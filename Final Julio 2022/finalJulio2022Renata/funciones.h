#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include "main.h"
#include "tdaListaSimple.h"
#include "Utils.h"

int crearLotePrueba(const char *nombreArchivo);
int registrosPedidos(const char *nombreArchivoLote,
                     const char *nombreArchivoFinal);
int cargarArchivoALista(const char *nombreArchivo,tLista *lista);
int listaAArchivo(const char *nombreArchivoFinal,tLista *lista);

#endif // FUNCIONES_H_INCLUDED
