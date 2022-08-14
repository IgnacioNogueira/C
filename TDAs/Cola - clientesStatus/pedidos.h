#ifndef PEDIDOS_H_INCLUDED
#define PEDIDOS_H_INCLUDED

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

void crearArchivoPedyPag(FILE * nombreArchPed,FILE * nombreArchPag);
int crearArchivoBin(char * nombreBinario);
int abrirArchivo(FILE **fp,const char * nombreArchivo,const char * modoApertura);

int leerYmostrarArchivoBin(FILE * archBin);
void mostrarMaesBin(tPedidos * ped);
int leerYmostrarArchivoBinPagos(FILE * archBin);
void mostrarMaesBinPagos(tPagos * pag);
void mostrarArchivosResult(const char * nombreArchivo);

int StatusClienteDin(FILE *archPed,FILE *archPag, FILE *archPedOk, FILE *archNc,FILE *archClDesc);
int estatusEncontrado(FILE *archPag,tPedidos *ped,tPagos * pag);
void escrituraSegunEstado(int enc,float totalValor,tPagos * pag,FILE *archPedOk,FILE *archNc,FILE *archClDesc);
#endif // PEDIDOS_H_INCLUDED
