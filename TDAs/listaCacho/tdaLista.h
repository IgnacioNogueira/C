#ifndef TDALISTA_H_INCLUDED
#define TDALISTA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MINIMO(X,Y)((X)<(Y) ? (X):(Y))

typedef struct sNodo
{
    void *info;
    unsigned tamInfo;
    struct sNodo *sig;

}tNodo;

typedef tNodo *tLista;

typedef struct
{
    unsigned clave;
    unsigned pos;

}tIndice;

int cmp(const void* d1,const void* d2);
int cmpStr(const void* d1,const void* d2);
void* acum(void**dLista,unsigned *ptInfo,const void *d,unsigned cantBytes);
void acumularCantPed(const void *d1,const void *d2);

void crearLista(tLista *pl);
int listaVacia(const tLista *pl);
int listaLlena(const tLista *pl,unsigned tam);
void vaciarLista(tLista *pl);
int ponerAlComienzo(tLista *pl,const void *d,unsigned tam);
int sacarPrimeroLista(tLista *pl,void *d,unsigned tam);
int verPrimeroLista(const tLista *pl,void *d,unsigned tam);
int ponerAlFinal(tLista *pl,const void *d,unsigned tam);
int sacarUltLista(tLista *pl,void *d,unsigned tam);
int verUltLista(const tLista *pl,void *d,unsigned tam);
int ponerPosList(tLista *pl,const void *d,unsigned tam,unsigned pos);
int ponerOrdenLista(tLista *pl,const void *d,unsigned tam,int (*cmp)(const void*, const void*));
tLista* buscarMenorEntLista(tLista *pl,int (*cmp)(const void*,const void*));
tLista* buscarMayorEntLista(tLista *pl,int (*cmp)(const void*,const void*));
int eliminarPosLista(tLista *pl,void *d,unsigned tam,unsigned pos);
int eliminarDupLista(tLista *pl,int(*cmp)(const void *,const void *));
int eliminaryAcumDupLista(tLista *pl,
                          int(*cmpStr)(const void *,const void *),
                          int(*acum)(void**,unsigned *,const void *,unsigned));
int indicesLista(tLista *pl);


#endif // TDALISTA_H_INCLUDED
