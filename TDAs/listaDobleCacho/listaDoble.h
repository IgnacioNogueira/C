#ifndef LISTADOBLE_H_INCLUDED
#define LISTADOBLE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    long idProducto;
    char descripcion[26];
    int cantidad;
    float precioUnitario;
} tProducto;

typedef struct
{
    long idProducto;
    char tipoMovimiento;
    int cantidad;
} tNovedad;

typedef struct sNodo
{
    void *info;
    unsigned tamBytes;
    struct sNodo * ant;
    struct sNodo * sig;

} tNodo;

typedef tNodo * tListaD;

#define MINIMO(X,Y)((X)<=(Y) ? (X):(Y))

void crearListaDoble(tListaD *pl);
int listaDobleVacia(tListaD *pl);
int listaDobleLlena(tListaD *pl,unsigned cantBytes);
int insertarAlComienzoLD(tListaD *pl,const void *d,unsigned cantBytes);
int insertarAlFinalLD(tListaD *pl,const void *d,unsigned cantBytes);
int sacarPrimeroLD(tListaD *pl,void *d,unsigned cantBytes);
int sacarUltimoLD(tListaD *pl,void *d,unsigned cantBytes);
void vaciarListaDoble(tListaD *pl);


int compararProd(const void *d1,const void *d2);
int acumularCantidadProd(void **info,unsigned *tam,
                         const void *info2,unsigned tam2);
int insertarEnOrden(tListaD *pl,const void *d,unsigned cantBytes,
                    int (*cmp)(const void *,const void *));
int insertarEnOrdenAcum(tListaD *pl,const void *d,unsigned cantBytes,
                        int (*cmp)(const void *,const void *),
                        int (*acum)(void **,unsigned *,const void *,unsigned));

void mostrarProd(const void *dv);
int mostrarDeIzqADer(const tListaD *pl,void(*mostrar)(const void *));
int mostrarDeDerAIzq(const tListaD *pl,void(*mostrar)(const void *));

int eliminarPorClave(tListaD *pl,void *d,unsigned cantBytes,
                     int (*cmp)(const void *,const void*));
tNodo * buscarNodo(tListaD *pl,void *d,int (*cmp)(const void *, const void *));
int eliminaryAcumDuplicadosLD(tListaD *pl,
                              int (*cmp)(const void *,const void *),
                              int (*acum)(void **,unsigned *,const void *, unsigned));
void ordenarLista(tListaD *pl, int (*cmp)(const void *, const void*));




int insertarAlFinalLD_MIO(tListaD * p,const void *d, unsigned cantBytes);
int sacarPrimeroLD_MIO(tListaD *pl,void * d, unsigned cantBytes);


int eliminaryAcumDuplicadosLD_MIO(tListaD *pl,
                                  int (*cmp)(const void*, const void *),
                                  int (*acum)(void **,unsigned *,const void *,unsigned));


int insertarAlComienzoLD_mioasdasidasd(tListaD *pl,const void *d,unsigned cantBytes);

int insertarAlFinalLD_mioasdasidasd(tListaD *pl,const void *d,unsigned cantBytes);

#endif // LISTADOBLE_H_INCLUDED
