#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#define NOMBRE_ARCHIVO_MAESTRO  "maestroProductos.dat"
#define NOMBRE_ARCHIVO_NOV      "novedades.txt"


typedef struct
{
    int dia,
        mes,
        anio;
} tFecha;

typedef struct
{
    long idProducto;
    char descripcion[26];
    tFecha fecUltAct;
    int cantidad;
    float precioUnitario;
} tProducto;

typedef struct
{
    long idProducto;
    char tipoMovimiento;
    int cantidad;

}tNovedad;


typedef struct
{
    unsigned id;
    unsigned pos;

}tIndice;


void crearLista(tLista *pl);
void crearLista(tLista *pl);
int listaLlena(const tLista *pl,unsigned tam);
void vaciarLista(tLista *pl);
int ponerOrdenLista(tLista *pl,const void *d,unsigned tam,int (*cmp)(const void*, const void*));
int sacarPrimeroLista(tLista *pl,void *d,unsigned tam);
void trozarCampoVariable(tNovedad *nov, char *cad);
int buscarEnLista(tLista * pl, void * d, int(*cmp)(const void *, const void *));

void mostrarMaesBin(tProducto * prod);
int leerYmostrarArchivoMast(const char * nombreArchivoMaes);
int leerYmostrarArchivoNov(char * nombreArchNov);
void mostrarNovTxt(tNovedad * nov);

int cmpNro(const void * d1, const void * d2);
int cmpNroProd(const void * d1, const void * d2);
int cmpIndices(unsigned idNov,void *idInd);
int posIndice(void *pos);

void mostrarInd(void *info);
void mostrarIndice(tLista *pl);
void crearIndice(const char * nombreArchivo, tIndice * ind, tLista pl);
int cmpIndices(unsigned idProd,void *idInd);
int posIndice(void *pos);

int actualizarMaestroProd(char *nombreArchivoMaestro,char *nombreArchivoNovedades,tLista pl);
#endif // MAIN_H_INCLUDED
