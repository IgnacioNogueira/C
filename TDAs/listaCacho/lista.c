#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tdaLista.h"
#include "lista.h"

//int ejercicioPedyPag(char *nombreArchPed,char *nombreArchPag,char *nombreArchOK,
//                     char *nombreArchNoCubre,char *nombreArchDes)
//{
//    FILE * fPed, *fPag,*fOk,*fNc,*fdes;
//    int cantAct;
//
//    fPed = fopen(nombreArchPed,"rb");
//
//    if(!fPed)
//    {
//        exit(-1);
//    }
//
//    fPag = fopen(nombreArchPag,"rb");
//
//    if(!fPag)
//    {
//        fclose(fPed);
//        exit(-2);
//    }
//
//    fOk = fopen(nombreArchOK,"rb");
//
//    if(!fOk)
//    {
//        fclose(fPed);
//        fclose(fPag);
//        exit(-3);
//    }
//
//    fNc = fopen(nombreArchNoCubre,"r+b");
//
//    if(!fNc)
//    {
//        fclose(fPed);
//        fclose(fPag);
//        fclose(fOk);
//        exit(-3);
//    }
//
//    fdes = fopen(nombreArchDes,"r+b");
//
//    if(!fdes)
//    {
//        fclose(fPed);
//        fclose(fPag);
//        fclose(fOk);
//        fclose(fNc);
//        exit(-4);
//    }
//
//    cantAct = StatusClienteLista(fPed,fPag,fOk,fNc,fdes);
//
//    fclose(fPed);
//    fclose(fPag);
//    fclose(fOk);
//    fclose(fNc);
//    fclose(fdes);
//
//    if(cantAct)
//    {
//        printf("\n\nPedidos cubiertos:\n\n");
//        mostrarArchivosResult(NOMBRE_ARCHIVO_MONTO_CUBIERTO); //Ya actualizado
//        printf("\n\nPedidos no cubiertos:\n\n");
//        mostrarArchivosResult(NOMBRE_ARCHIVO_MONTO_DESCUBIERTO);
//        printf("\n\nPedidos desconocidos:\n\n");
//        mostrarArchivosResult(NOMBRE_ARCHIVO_DESCONOCIDO);
//        printf("\n\nLa cantidad de pedidos encontrados es de: %d\n\n",cantAct);
//    }
//
//    return 1;
//}



//int StatusClienteLista(FILE *archPed,FILE *archPag, FILE *archPedOk,
//                       FILE *archNc,FILE *archClDesc)
//{
//    tPedidos ped;
//    tPagos pag;
//
//    tLista lis;
//
//    crearLista(&lis);
//
//    fread(&ped,sizeof(tPedidos),1,archPed);
//    fread(&pag,sizeof(tPagos),1,archPag);
//
//    printf("\n-Se insertan los siguientes elementos en la lista:\n");
//    while(!feof(archPed))
//    {
//        ponerOrdenLista(&lis,&ped,sizeof(tPedidos),cmp)
//        fread(&ped,sizeof(tPedidos),1,archPed);
//
//    }
//
//
//
//
//
//}



int crearArchivoBin(char * nombreBinario)
{
    FILE * fpb = fopen(nombreBinario,"wb");

    if(fpb)
    {
        fclose(fpb);
        return 1;
    }

    printf("\nNO SE PUDO CREAR EL NOMBRE DEL ARCHIVO %s",nombreBinario);
    return -3;
}

int abrirArchivo(FILE **fp,const char * nombreArchivo,const char * modoApertura)
{
    *fp = fopen(nombreArchivo,modoApertura);

    if(*fp == NULL)
    {
        return 0;
    }

    return 1;
}


int leerYmostrarArchivoBin(FILE * archBin)
{
    tPedidos ped;

    fread(&ped,sizeof(tPedidos),1,archBin);

    while(!feof(archBin))
    {
        mostrarMaesBin(&ped);
        fread(&ped,sizeof(tPedidos),1,archBin);
    }

    return 1;
}

void mostrarMaesBin(tPedidos * ped)
{
    if(!ped)
    {
        //printf("\nNo hay pedidos que mostrar"); -> en realidad lo usa para mostrar la cabecera (Estaría mal)
        return;
    }

    printf("-%*.*s  %li %d  %.2f\n",
           (int)sizeof(ped->idCliente)-1,
           (int)sizeof(ped->idCliente)-1,
           ped->idCliente,
           ped->idProd,
           ped->cantPed,
           ped->precUnitario
          );
}


int leerYmostrarArchivoBinPagos(FILE * archBin)
{
    tPagos pag;

    fread(&pag,sizeof(tPagos),1,archBin);

    while(!feof(archBin))
    {
        mostrarMaesBinPagos(&pag);
        fread(&pag,sizeof(tPagos),1,archBin);
    }

    return 1;
}

void mostrarMaesBinPagos(tPagos * pag)
{
    if(!pag)
    {
        printf("\nNo hay pagos que mostrar");
        return;
    }

    printf("-%c  %*.*s  %.2f\n",
           pag->tipoPago,
           (int)sizeof(pag->idCliente)-1,
           (int)sizeof(pag->idCliente)-1,
           pag->idCliente,
           pag->montoPago
          );
}

void mostrarArchivosResult(const char * nombreArchivo)
{
    tPedidos ped;
    FILE * fp = fopen(nombreArchivo,"rb");

    if(!fp)
    {
        exit(-1);
    }

    fread(&ped,sizeof(tPedidos),1,fp);

    while(!feof(fp))
    {
        printf("-%*.*s  %li %d  %.2f\n",
               (int)sizeof(ped.idCliente)-1,
               (int)sizeof(ped.idCliente)-1,
               ped.idCliente,
               ped.idProd,
               ped.cantPed,
               ped.precUnitario
              );

        fread(&ped,sizeof(tPedidos),1,fp);
    }

    fclose(fp);
}
