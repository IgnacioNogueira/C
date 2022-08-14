#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIN_MEM     1
#define CLA_DUP     2
#define TODO_BIEN   0

typedef struct sNodo {
    struct sNodo *sig;
    unsigned tamInfo;
    void *info;
} tNodo;
typedef tNodo *tLista;

void crearLista(tLista *p);
int listaVacia(const tLista *p);
int listaLlena(const tLista *p, unsigned cantBytes);
//void vaciarLista(tLista* p);
int ponerAlComienzo(tLista *p, const void *d, unsigned cantBytes);
int sacarPrimeroLista(tLista *p, void *d, unsigned cantBytes);
int verPrimeroLista(const tLista *p, void *d, unsigned cantBytes);
int ponerAlFinal(tLista *p, const void *d, unsigned cantBytes);
int sacarUltimoDeLista(tLista *p, void *d, unsigned cantBytes);
int verUltimoLista(const tLista *p, void *d, unsigned cantBytes);
int vaciarLista(tLista *p);
int vaciarListaYMostrar(tLista *p, void (*mostrar)(const void *, FILE *), FILE *fp);
int ponerEnOrden(tLista *p, const void *d, unsigned cantBytes,
                 int (*comparar)(const void *, const void *),
                 int (*acumular)(void **, unsigned *, const void *, unsigned));
void ordenar(tLista *p, int(*comparar)(const void *, const void *));
int recorrerLista(tLista *p, void *params,
                  void (*accion)(void *dato, unsigned tam, void
                  *params));
int sacarPorClave(tLista *p, const void *d, unsigned cantBytes,
                  int (*comparar)(const void*, const void*));


#endif // LISTA_H_INCLUDED
