#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "pilaDinamica.h"

#define MIN_PILA 1
#define MAX_PILA 500
#define MAX_ELEM 100

#define ERROR_ARCH -1
#define ERROR_PILA -2
#define VAL_ANORMAL -3

int crearSetDeDatos(const char *nombreArchivo);
int verificarPila(FILE *fpDatos);
void crearCantidadPilas(tPila *vPilas,int cantPilas);
int interaccionPilas(FILE *fpd, tPila *vPilas);
int sacarYGrabarArchivoNuevo(tPila *vPilas,int posElem);
int procesarArchivoPilas(const char *nombreArchivoDatos);

#endif // FUNCIONES_H_INCLUDED
