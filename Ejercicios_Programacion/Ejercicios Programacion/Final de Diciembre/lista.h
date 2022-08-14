#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ERROR 0
#define TODO_OK 1

typedef struct sNodo
{
   void *info;
   unsigned tamInfo;
   struct sNodo *sig;
} tNodo;

typedef tNodo *tLista;

void crearLista(tLista *p);
int listaVacia(const tLista *p);
int sacarPrimeroLista(tLista *p, void *d, unsigned cantBytes);
int ponerEnOrden(tLista *p, const void *d, unsigned cantBytes,
                 int (*comparar)(const void*, const void *),
                 int (*acumular)(void **, unsigned *, const void *, unsigned));

#endif // LISTA_H_INCLUDED
