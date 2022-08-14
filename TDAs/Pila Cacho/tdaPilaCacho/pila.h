#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_PILA 320
#define MINIMO(X,Y) (X)>(Y) ? (Y):(X)


typedef struct
{
    unsigned int idProducto;
    char descripcion[21];
    int cantidad;
    float precioUnitario;
}tProducto;

void ProbarPilaEstatica();
void ProbarPilaDinamica();
void ejercicioPilaSumaNrosGrandes();

#endif // PILA_H_INCLUDED
