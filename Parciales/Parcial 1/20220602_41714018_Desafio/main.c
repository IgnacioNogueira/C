#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "main.h"

int main()
{
    int cantAct;
    tLista lista;
    crearLista(&lista);
    tIndice ind;

    crearIndice(NOMBRE_ARCHIVO_MAESTRO,&ind,lista);
    printf("\n-> Contenido del archivo maestro <-\n");
    leerYmostrarArchivoMast(NOMBRE_ARCHIVO_MAESTRO);
    printf("\n-> Contenido del archivo novedades <-\n");
    leerYmostrarArchivoNov(NOMBRE_ARCHIVO_NOV);

    cantAct = actualizarMaestroProd(NOMBRE_ARCHIVO_MAESTRO,NOMBRE_ARCHIVO_NOV,lista);

    printf("\n-> Contenido del archivo maestro actualizado <-\n");
    leerYmostrarArchivoNov(NOMBRE_ARCHIVO_NOV);
    printf("\n-> Se realizaron %d actualizaciones <-\n",cantAct);

    return 0;
}
