#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include "header.h"
#include "tdaLista.h"
#include "utils.h"

int PuntoALista(const char *nombreArchivo,
                tListaD * lista,
                int (*cmp)(const void *,const void*),
                int (*acum)(void **,unsigned *,const void *,unsigned));

int puntoBNodos(tListaD *lista, unsigned cantNodosElim);

int PuntoCArchivo(const char *nombreArchivoFinal,
                  tListaD *lista);


#endif // FUNCIONES_H_INCLUDED
