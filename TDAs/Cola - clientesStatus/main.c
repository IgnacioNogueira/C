#include "pedidos.h"
#include "colaDinamica.h"

int main()
{
    int cantAct;
    FILE *fpPed,*fpPag,*fpPedOK,*fpPedNOK,*fpDes;


    //crearArchivoBin(NOMBRE_ARCHIVO_PEDIDOS);
    //crearArchivoBin(NOMBRE_ARCHIVO_PAGOS);
    //crearArchivoBin(NOMBRE_ARCHIVO_MONTO_CUBIERTO);
    //crearArchivoBin(NOMBRE_ARCHIVO_MONTO_CUBIERTO);
    //crearArchivoBin(NOMBRE_ARCHIVO_MONTO_DESCUBIERTO);
    //crearArchivoBin(NOMBRE_ARCHIVO_DESCONOCIDO);

    if(!abrirArchivo(&fpPed,NOMBRE_ARCHIVO_PEDIDOS,"rb")) //el modo está bien porque lo vamos a actualizar
    {
        exit(-4);
    }


    if(!abrirArchivo(&fpPag,NOMBRE_ARCHIVO_PAGOS,"rb"))
    {
        exit(-5);
    }

    printf("\n\nPedidos:\n\n");
    leerYmostrarArchivoBin(fpPed);
    printf("\n");


    printf("\n\nPagos:\n\n");
    leerYmostrarArchivoBinPagos(fpPag);
    printf("\n");


    if(!abrirArchivo(&fpPedOK,NOMBRE_ARCHIVO_MONTO_CUBIERTO,"r+b"))
    {
        exit(-6);
    }

    if(!abrirArchivo(&fpPedNOK,NOMBRE_ARCHIVO_MONTO_DESCUBIERTO,"r+b"))
    {
        exit(-7);
    }

    if(!abrirArchivo(&fpDes,NOMBRE_ARCHIVO_DESCONOCIDO,"r+b"))
    {
        exit(-8);
    }

    cantAct = StatusClienteDin(fpPed,fpPag,fpPedOK,fpPedNOK,fpDes);

    fclose(fpPed);
    fclose(fpPag);
    fclose(fpPedOK);
    fclose(fpPedNOK);
    fclose(fpDes);

    if(cantAct)
    {
        printf("\n\nPedidos cubiertos:\n\n");
        mostrarArchivosResult(NOMBRE_ARCHIVO_MONTO_CUBIERTO); //Ya actualizado
        printf("\n\nPedidos no cubiertos:\n\n");
        mostrarArchivosResult(NOMBRE_ARCHIVO_MONTO_DESCUBIERTO);
        printf("\n\nPedidos desconocidos:\n\n");
        mostrarArchivosResult(NOMBRE_ARCHIVO_DESCONOCIDO);
        printf("\n\nLa cantidad de pedidos encontrados es de: %d\n\n",cantAct);
    }

    return 0;
}
