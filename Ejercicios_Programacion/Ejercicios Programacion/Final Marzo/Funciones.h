#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "PilaDinamica.h"

#define CANT_REGISTROS 15
#define MIN_PILA 1
#define MAX_PILA 500
#define MAX_ELEMENTO 100

void crearArchivoDePrueba(const char* nomArchivo);
booleano procesamientoPilas(FILE* archEntrada, int cantPilas);

#endif // FUNCIONES_H
