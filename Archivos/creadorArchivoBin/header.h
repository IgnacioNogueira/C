#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    char idCliente[8];
    long idProd;
    int cantPed;
    float precUnitario;

}tPedidos;


typedef struct
{
    char tipoPago;
    char idCliente[8];
    float montoPago;

}tPagos;

#define NOMBRE_ARCHIVO_PEDIDOS "pedidos.bin"
#define NOMBRE_ARCHIVO_PAGOS "pagos.bin"
#define NOMBRE_ARCHIVO_MONTO_CUBIERTO "pedidos_ok.bin"
#define NOMBRE_ARCHIVO_MONTO_DESCUBIERTO "pedidos_blk.bin"
#define NOMBRE_ARCHIVO_DESCONOCIDO "pedidos_unk.bin"

int crearArchivoPed(char * nombreArchPed);
int crearArchivoPag(char * nombreArchPag);
int crearArchivoBin(char * nombreBinario);
int nogueira_strcmp(const char *cad1,const char *cad2);

#endif // HEADER_H_INCLUDED
