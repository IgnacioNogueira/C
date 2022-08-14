#ifndef TDALISTASIMPLE_H_INCLUDED
#define TDALISTASIMPLE_H_INCLUDED

#include "main.h"
#include "tdaDefiniciones.h"

void crearLista(tLista *pl);
int esListaVacia(tLista *pl);
int ponerListaAlFinal(tLista *pl,const void *d,unsigned cantBytes);
int eliminarYAcumDupLista(tLista *pl,
                          int (*cmp)(const void *,const void*),
                          int (*acum)(void **,unsigned *,const void *,unsigned));
int sacarDeListaPrimero(tLista *pl,void *d, unsigned cantBytes);

#endif // TDALISTASIMPLE_H_INCLUDED
