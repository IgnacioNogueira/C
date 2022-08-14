#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOMBRE_ARCHIVO_PEDIDOS "Pedidos.txt"
#define NOMBRE_ARCHIVO_RESULTADO_COMPRAS "resultadoCompras.bin"

#define TODO_BIEN 1
#define FAIL -1


typedef struct
{
    int nroPedido;
    char codProd[10];
    int cantPedida;
    char codSector;
    char oficina[20];

}tPedidos;

#endif // HEADER_H_INCLUDED
