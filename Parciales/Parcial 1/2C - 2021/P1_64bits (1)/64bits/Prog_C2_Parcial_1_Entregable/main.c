/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//*      ACÁ NO DEBE HACER NINGUNA MODIFICACIÓN                    *//**/
/**//**//*      SÓLO PARA SUS PRUEBAS CON LOS DISTINTOS                   *//**/
/**//**//*      LOTES E INVOCAR A SUS FUNCIONES                           *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

#include "main.h"

int main()
{
    FILE   *fpPantalla;
    tLista listaA;
    tLista listaB;
    tLista listaF;

    crearArchivos(NOMBRE_ARCHIVO_MBIN,
                  NOMBRE_ARCHIVO_MTXT);
    crearArchivoNovedades(NOMBRE_ARCHIVO_NOV);

    crearLista(&listaA);
    crearLista(&listaB);
    crearLista(&listaF);

#ifdef CODIGO_ALUMNO
    fpPantalla = fopen("pantalla.txt", "wt");
#else
    fpPantalla = fopen("pantallaBIEN.txt", "wt");
#endif
    if(fpPantalla == NULL)
        fpPantalla = stdout;

    fprintf(fpPantalla,
            "************************************************************\n"
            "*    Inicia la ejecucion del programa.                     *\n"
            "************************************************************\n");

    fprintf(fpPantalla, "\nArchivo Maestro 1:\n\n");
    mostrarArchivoMaestroBin(NOMBRE_ARCHIVO_MBIN, fpPantalla);
    fprintf(fpPantalla, "\nArchivo Maestro 2:\n\n");
    mostrarArchivoMaestroTxt(NOMBRE_ARCHIVO_MTXT, fpPantalla);
    fprintf(fpPantalla, "\nArchivo de Novedades:\n\n");
    mostrarArchivoNovedades(NOMBRE_ARCHIVO_NOV, fpPantalla),
    fprintf(fpPantalla, "\n");

    punto_1(fpPantalla, &listaA, &listaB);
    punto_2(fpPantalla, &listaA, &listaB, &listaF);
    punto_3(fpPantalla, &listaF);
    punto_4(fpPantalla);
    punto_5(fpPantalla);

    fprintf(fpPantalla, "\nComprobar que las listas hayan quedado vacías:\n");
    fprintf(fpPantalla, "\nLista A:\n");
    recorrerLista(&listaA, fpPantalla, mostrarProducto);
    fprintf(fpPantalla, "\nLista B:\n");
    recorrerLista(&listaB, fpPantalla, mostrarProducto);
    fprintf(fpPantalla, "\nLista F:\n");
    recorrerLista(&listaF, fpPantalla, mostrarProducto);

    fclose(fpPantalla);
#ifdef CODIGO_ALUMNO
    system("start Notepad pantalla.txt");
#else
    system("start Notepad pantallaBIEN.txt");
#endif
    return 0;
}


/** función: punto_1
 **
 **/
void punto_1(FILE *fpPantalla, tLista *listaA, tLista *listaB)
{
    fprintf(fpPantalla,
            "************************************************************\n"
            "*    Punto 1: comienza a ejecutarse.                       *\n"
            "************************************************************\n");

#ifdef PUNTO_1
    punto_uno_MIO(fpPantalla,
                  NOMBRE_ARCHIVO_MBIN,
                  NOMBRE_ARCHIVO_MTXT,
                  listaA,
                  listaB);
#else
    punto_uno(fpPantalla,
              NOMBRE_ARCHIVO_MBIN,
              NOMBRE_ARCHIVO_MTXT,
              listaA,
              listaB);
#endif

    fprintf(fpPantalla, "\nLista A:\n\n");
    recorrerLista(listaA, fpPantalla, mostrarProducto);

    fprintf(fpPantalla, "\nLista B:\n\n");
    recorrerLista(listaB, fpPantalla, mostrarProducto);

    fprintf(fpPantalla,
            "\n************************************************************\n"
            "*    Fin ejecución Punto 1.                                *\n"
            "************************************************************\n\n");
}


/** función: punto_2
 **
 **/
void punto_2(FILE *fpPantalla, tLista *listaA, tLista *listaB, tLista *listaF)
{
    fprintf(fpPantalla,
            "************************************************************\n"
            "*    Punto 2: comienza a ejecutarse.                       *\n"
            "************************************************************\n");

#ifdef PUNTO_2
    punto_dos_MIO(fpPantalla,
                  listaA,
                  listaB,
                  listaF);
#else
    punto_dos(fpPantalla,
                  listaA,
                  listaB,
                  listaF);
#endif

    fprintf(fpPantalla, "\nLista F:\n\n");
    recorrerLista(listaF, fpPantalla, mostrarProducto);

    fprintf(fpPantalla,
            "\n************************************************************\n"
            "*    Fin ejecución Punto 2.                                *\n"
            "************************************************************\n\n");
}


/** función: punto_3
 **
 **/
void punto_3(FILE *fpPantalla, tLista *listaF)
{
    int cantEliminados;
    fprintf(fpPantalla,
            "************************************************************\n"
            "*    Punto 3: comienza a ejecutarse.                       *\n"
            "************************************************************\n");

#ifdef PUNTO_3
    cantEliminados = punto_tres_MIO(fpPantalla, listaF, NOMBRE_ARCHIVO_MCONS);
#else
    cantEliminados = punto_tres(fpPantalla, listaF, NOMBRE_ARCHIVO_MCONS);
#endif

    fprintf(fpPantalla,
            "\nSe eliminaron %d registros de la lista.\n",
            cantEliminados);

    fprintf(fpPantalla, "\nArchivo maestro consolidado:\n\n");
    mostrarArchivoMaestroBin(NOMBRE_ARCHIVO_MCONS, fpPantalla);

    fprintf(fpPantalla,
            "\n************************************************************\n"
            "*    Fin ejecución Punto 3.                                *\n"
            "************************************************************\n\n");
}


/** función: punto_4
 **
 **/
void punto_4(FILE *fpPantalla)
{
    int cantActualizaciones;
    fprintf(fpPantalla,
            "************************************************************\n"
            "*    Punto 4: comienza a ejecutarse.                       *\n"
            "************************************************************\n");

#ifdef PUNTO_4
    cantActualizaciones = punto_cuatro_MIO(fpPantalla,
                                           NOMBRE_ARCHIVO_MCONS,
                                           NOMBRE_ARCHIVO_NOV);
#else
    cantActualizaciones = punto_cuatro(fpPantalla,
                                       NOMBRE_ARCHIVO_MCONS,
                                       NOMBRE_ARCHIVO_NOV);
#endif

    fprintf(fpPantalla, "\nArchivo maestro actualizado:\n\n");
    mostrarArchivoMaestroBin(NOMBRE_ARCHIVO_MCONS, fpPantalla);
    fprintf(fpPantalla,
            "\nSe realizaron %d actualizaciones\n\n",
            cantActualizaciones);

    fprintf(fpPantalla,
            "************************************************************\n"
            "*    Fin ejecución Punto 4.                                *\n"
            "************************************************************\n\n");
}


/** función: punto_5
 **
 **/
void punto_5(FILE *fpPantalla)
{
    int matriz[][TAM_MAT] = {
                             {1, 0, 0, 0, 0},
                             {0, 1, 0, 0, 0},
                             {0, 0, 1, 0, 0},
                             {0, 0, 0, 1, 0},
                             {0, 0, 0, 0, 1}
                            };
    int resultado = 0;

    fprintf(fpPantalla,
            "************************************************************\n"
            "*    Punto 5: comienza a ejecutarse.                       *\n"
            "************************************************************\n");

#ifdef PUNTO_5
    resultado = punto_cinco_MIO(fpPantalla, matriz);
#else
    resultado = punto_cinco(fpPantalla, matriz);
#endif

    if(resultado)
    {
        fprintf(fpPantalla, "\nEs matriz identidad\n\n");
    }
    else
    {
        fprintf(fpPantalla, "\nNo es matriz identidad\n\n");
    }

    fprintf(fpPantalla,
            "************************************************************\n"
            "*    Fin ejecución Punto 5.                                *\n"
            "************************************************************\n\n");
}
