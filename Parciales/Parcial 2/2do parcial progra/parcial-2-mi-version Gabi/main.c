/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//*      ACÁ NO DEBE HACER NINGUNA MODIFICACIÓN                    *//**/
/**//**//*      SÓLO PARA SUS PRUEBAS CON LOS DISTINTOS                   *//**/
/**//**//*      LOTES E INVOCAR A SUS FUNCIONES                           *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

#include "main.h"

int main()
{
    FILE   *fpPantalla;
    tArbol indice;
    tLista listaNov;
    tCola colaNov,
          colaPodados;

    crearArchivoCuentas(NOMBRE_ARCHIVO_CUENTAS);
    crearArchivoNovedades(NOMBRE_ARCHIVO_NOVEDADES);
    crearLista(&listaNov);

#ifdef CODIGO_ALUMNO
    fpPantalla = fopen("pantalla.txt", "wt");
#else
    fpPantalla = fopen("pantallaBIEN.txt", "wt");
#endif
    if(fpPantalla == NULL)
        fpPantalla = stdout;

    crearArbol(&indice);
    crearLista(&listaNov);
    crearCola(&colaNov);
    crearCola(&colaPodados);

    punto_1(fpPantalla, &indice);
    punto_2(fpPantalla, &listaNov);
    punto_3(fpPantalla, &listaNov, &colaNov);
    punto_4(fpPantalla, &colaNov, &indice);
    punto_5(fpPantalla, &indice, &colaPodados);
    punto_6(fpPantalla, &colaPodados);

    fclose(fpPantalla);
#ifdef CODIGO_ALUMNO
    system("start Notepad pantalla.txt");
#else
    system("start Notepad pantallaBIEN.txt");
#endif

    vaciarLista(&listaNov);
    eliminarArbol(&indice);
    return 0;
}


/** función: punto_1
 **
 **/
void punto_1(FILE *fpPantalla, tArbol *indice)
{
    fprintf(fpPantalla,
            "************************************************************\n"
            "*    Punto 1: comienza a ejecutarse.                       *\n"
            "************************************************************\n");

    fprintf(fpPantalla, "Contenido del archivo de cuentas: \n\n");
    mostrarArchivoCuentas(NOMBRE_ARCHIVO_CUENTAS, fpPantalla);


#ifdef PUNTO_1
        indexarArchivoCuentas_MIO(NOMBRE_ARCHIVO_CUENTAS, indice);
#else
        indexarArchivoCuentas(NOMBRE_ARCHIVO_CUENTAS, indice);
#endif

    fprintf(fpPantalla, "\nContenido del indice: \n\n");
    mostrarArbolIndice(indice, fpPantalla);

    fprintf(fpPantalla,"\n");
    fprintf(fpPantalla,
            "************************************************************\n"
            "*    Fin ejecución Punto 1.                                *\n"
            "************************************************************\n\n");
}

/** función: punto_2
 **
 **/
void punto_2(FILE *fpPantalla, tLista *lista)
{
    int cantNovedades = 0;

    fprintf(fpPantalla,
            "************************************************************\n"
            "*    Punto 2: comienza a ejecutarse.                       *\n"
            "************************************************************\n");
    fprintf(fpPantalla, "Contenido del archivo de novedades: \n\n");
    mostrarArchivoNovedades(NOMBRE_ARCHIVO_NOVEDADES, fpPantalla);

#ifdef PUNTO_2
    cantNovedades = cargarArchivoNovedadesEnLista_MIO(fpPantalla,
                                                      NOMBRE_ARCHIVO_NOVEDADES,
                                                      lista);
#else
    cantNovedades = cargarArchivoNovedadesEnLista(fpPantalla,
                                                  NOMBRE_ARCHIVO_NOVEDADES,
                                                  lista);
#endif

    fprintf(fpPantalla, "\nContenido de la lista de novedades:\n\n");
    mostrarDeIzqADer(lista, mostrarNovedad, fpPantalla);
    fprintf(fpPantalla, "\nCantidad de novedades: %d\n\n", cantNovedades);


    fprintf(fpPantalla,
            "************************************************************\n"
            "*    Fin ejecución Punto 2.                                *\n"
            "************************************************************\n\n");
}


/** función: punto_3
 **
 **/

void punto_3(FILE *fpPantalla, tLista *pl, tCola *pc)
{
    int elementosEncolados;
    fprintf(fpPantalla,
            "************************************************************\n"
            "*    Punto 3: comienza a ejecutarse.                       *\n"
            "************************************************************\n");

#ifdef PUNTO_3
    elementosEncolados = cargarNovedadesEnColaDesdeLista_MIO(pl,
                                                             pc,
                                                             fpPantalla);
#else
    elementosEncolados = cargarNovedadesEnColaDesdeLista(pl,
                                                         pc,
                                                         fpPantalla);
#endif

    fprintf(fpPantalla,
            "\nSe encolaron %d elementos\n\n", elementosEncolados);

    fprintf(fpPantalla,
            "************************************************************\n"
            "*    Fin ejecución Punto 3.                                *\n"
            "************************************************************\n\n");
}


/** función: punto_4
 **
 **/

void punto_4(FILE *fpPantalla, tCola *cola, tArbol *indice)
{
    int act;

    fprintf(fpPantalla,
            "************************************************************\n"
            "*    Punto 4: comienza a ejecutarse.                       *\n"
            "************************************************************\n");

    fprintf(fpPantalla,
            "Contenido del archivo de cuentas antes de ser actualizado: \n\n");
    mostrarArchivoCuentas(NOMBRE_ARCHIVO_CUENTAS, fpPantalla);
    fprintf(fpPantalla,
           "\nNovedades sin cuentas correspondidas:\n\n");
#ifdef PUNTO_4
    act = actualizarArchivoDeCuentasDesdeColaDeNovedades_MIO(fpPantalla,
                                                   NOMBRE_ARCHIVO_CUENTAS,
                                                   cola,
                                                   indice);
#else
    act = actualizarArchivoDeCuentasDesdeColaDeNovedades(fpPantalla,
                                                   NOMBRE_ARCHIVO_CUENTAS,
                                                   cola,
                                                   indice);
#endif

    fprintf(fpPantalla,
           "\nContenido del archivo de cuentas luego de ser actualizado: \n\n");
    mostrarArchivoCuentas(NOMBRE_ARCHIVO_CUENTAS, fpPantalla);

    fprintf(fpPantalla,
           "\nCantidad de cuentas actualizadas: %d\n\n", act);

    fprintf(fpPantalla,
            "************************************************************\n"
            "*    Fin ejecución Punto 4.                                *\n"
            "************************************************************\n\n");
}


/** función: punto_5
 **
 **/

void punto_5(FILE *fpPantalla, tArbol *indice, tCola *cola)
{
    int cantPodados;
    fprintf(fpPantalla,
            "************************************************************\n"
            "*    Punto 5: comienza a ejecutarse.                       *\n"
            "************************************************************\n");

#ifdef PUNTO_5
    cantPodados = podarIndiceYEncolarPodados_MIO(fpPantalla,
                                                 indice,
                                                 cola,
                                                 ALTURA_PODA);
#else
    cantPodados = podarIndiceYEncolarPodados(fpPantalla,
                                             indice,
                                             cola,
                                             ALTURA_PODA);
#endif
    fprintf(fpPantalla,
            "\nSe podaron %d nodos.\n\n", cantPodados);

    fprintf(fpPantalla,
            "************************************************************\n"
            "*    Fin ejecución Punto 5.                                *\n"
            "************************************************************\n\n");
}

void punto_6(FILE *fpPantalla, tCola *cola)
{
    int cantBajas;
    fprintf(fpPantalla,
            "************************************************************\n"
            "*    Punto 6: comienza a ejecutarse.                       *\n"
            "************************************************************\n");

    fprintf(fpPantalla, "Contenido del archivo de cuentas: \n\n");
    mostrarArchivoCuentas(NOMBRE_ARCHIVO_CUENTAS, fpPantalla);

#ifdef PUNTO_6
    cantBajas =
            actualizarEstadosArchivoCuentasDesdeCola_MIO(fpPantalla,
                                                         NOMBRE_ARCHIVO_CUENTAS,
                                                         cola);
#else
    cantBajas = actualizarEstadosArchivoCuentasDesdeCola(fpPantalla,
                                                         NOMBRE_ARCHIVO_CUENTAS,
                                                         cola);
#endif

    fprintf(fpPantalla, "\nContenido del archivo de cuentas con bajas: \n\n");
    mostrarArchivoCuentas(NOMBRE_ARCHIVO_CUENTAS, fpPantalla);

    fprintf(fpPantalla,
            "\nSe se dieron de baja %d registros.\n\n", cantBajas);

    fprintf(fpPantalla,
            "************************************************************\n"
            "*    Fin ejecución Punto 6.                                *\n"
            "************************************************************\n\n");
}
