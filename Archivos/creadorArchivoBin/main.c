#include "header.h"

int main()
{

    crearArchivoPed(NOMBRE_ARCHIVO_PEDIDOS);
    crearArchivoPag(NOMBRE_ARCHIVO_PAGOS);

    FILE * fpPed = fopen(NOMBRE_ARCHIVO_PEDIDOS,"rb");

    if(!fpPed)
    {
        exit(-1);
    }

    FILE * fpPag = fopen(NOMBRE_ARCHIVO_PAGOS,"rb");

    if(!fpPag)
    {
        fclose(fpPed);
        exit(-2);
    }

    crearArchivoBin(NOMBRE_ARCHIVO_MONTO_CUBIERTO);
    crearArchivoBin(NOMBRE_ARCHIVO_MONTO_DESCUBIERTO);
    crearArchivoBin(NOMBRE_ARCHIVO_DESCONOCIDO);


    return 0;
}
