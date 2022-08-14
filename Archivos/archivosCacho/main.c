#include "archivo.h"

int main()
{
    FILE *fpMast,*fpNov,*fpErr,*fpSinS;

    crearArchivoMaeDes(NOMBRE_ARCHIVO_MAESTRO);
    //crearArchivoTxt(NOMBRE_ARCHIVO_NOVEDADES);
    //pasarTxtABin(NOMBRE_ARCHIVO_NOVEDADES,NOMBRE_ARCHIVOBIN_LONGVAR,'v');
    //pasarTxtABin(NOMBRE_ARCHIVO_NOVEDADES2,NOMBRE_ARCHIVOBIN_LONGFIJA,'f');
    crearArchivoBin(NOMBRE_ARCHIVO_ERRORES);
    crearArchivoTxt(NOMBRE_ARCHIVO_SIN_STOCK);

    int cantAct;

    printf("\nMaestro original:\n\n");
    leerYmostrarArchivoMast(NOMBRE_ARCHIVO_MAESTRO);
    printf("\n");


    printf("\nNovedades:\n");
    leerYmostrarArchivoNov(NOMBRE_ARCHIVO_NOVEDADES);
    printf("\n");


    if(!abrirArchivo(&fpMast,NOMBRE_ARCHIVO_MAESTRO,"r+b",1)) //el modo está bien porque lo vamos a actualizar
    {
        exit(-7);
    }


    if(!abrirArchivo(&fpNov,NOMBRE_ARCHIVO_NOVEDADES,"rt",1))
    {
        exit(-8);
    }

    if(!abrirArchivo(&fpSinS,NOMBRE_ARCHIVO_SIN_STOCK,"r+t",1))
    {
        exit(-9);

    }

    if(!abrirArchivo(&fpErr,NOMBRE_ARCHIVO_ERRORES,"r+b",1))
    {
        exit(-10);

    }

    //cantAct = actualizarMercaditoArchOrd(fpMast,fpNov,fpSinS,fpErr);
    cantAct = actualizarMercaditoArchDes(fpMast,fpNov,fpSinS,fpErr);

    if(cantAct > 0)
    {
        printf("\n- Maestro actualizado:\n");
        leerYmostrarArchivoMast(NOMBRE_ARCHIVO_MAESTRO); //Ya actualizado
        printf("\n\n-La cantidad de actualizaciones que se hicieron en el archivo: %d\n\n",cantAct);

    }

    fclose(fpMast);
    fclose(fpNov);
    fclose(fpErr);
    fclose(fpSinS);

    return 0;
}
