#ifndef UTILITARIAS_H_INCLUDED
#define UTILITARIAS_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista.h"

#define ERROR 0
#define TODO_OK 1

typedef struct
{
    int nroPedido;
    char codPro[10];
    int cantPedida;
    char codSector;
    char oficina[20];
}tPedido;

typedef struct
{
    char codPro[10];
    int cantPedida;
}tCompra;

typedef struct
{
    char codPro[10];
    char codSector;
    int cantPedida;
}tSector;

int cargarCompras(FILE *archivo, tLista *compras);
int cargarSectores(FILE *archivo, tLista *sectores);
int compararCompras(const void *d1,const void *d2);
int acumularCompras(void **destino, unsigned *tamDestino, const void *origen, unsigned tamOrigen);
int compararSectores(const void *d1, const void *d2);
int acumularSectores(void **destino, unsigned *tamDestino, const void *origen, unsigned tamOrigen);
int leerRegistro(FILE *archivo, tPedido *pedido);

#endif // UTILITARIAS_H_INCLUDED
