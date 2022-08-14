#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "tdaLista.h"
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


int ejercicioPedyPag(char *nombreArchPed,char *nombreArchPag,char *nombreArchOK,
                     char *nombreArchNoCubre,char *nombreArchDes);
int StatusClienteLista(FILE *archPed,FILE *archPag, FILE *archPedOk,
                       FILE *archNc,FILE *archClDesc);


int crearArchivoBin(char * nombreBinario);
int abrirArchivo(FILE **fp,const char * nombreArchivo,const char * modoApertura);

int leerYmostrarArchivoBin(FILE * archBin);
void mostrarMaesBin(tPedidos * ped);
int leerYmostrarArchivoBinPagos(FILE * archBin);
void mostrarMaesBinPagos(tPagos * pag);
void mostrarArchivosResult(const char * nombreArchivo);


#endif // LISTA_H_INCLUDED
