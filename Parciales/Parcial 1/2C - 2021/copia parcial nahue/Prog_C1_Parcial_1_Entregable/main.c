/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//*      ACÁ NO DEBE HACER NINGUNA MODIFICACIÓN                    *//**/
/**//**//*      SÓLO PARA SUS PRUEBAS CON LOS DISTINTOS                   *//**/
/**//**//*      LOTES E INVOCAR A SUS FUNCIONES                           *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

#include "main.h"

int main()
{
    FILE   *fpPantalla;
    tLista lista;

    crearArchivos(NOMBRE_ARCHIVO_1,
                  NOMBRE_ARCHIVO_2);
    crearArchivoNovedades(NOMBRE_ARCHIVO_NOV);
    crearLista(&lista);

#ifdef CODIGO_ALUMNO
    fpPantalla = fopen("pantalla.txt", "wt");
#else
    fpPantalla = fopen("pantallaBIEN.txt", "wt");
#endif
    if(fpPantalla == NULL)
        fpPantalla = stdout;

    punto_1(fpPantalla);
    punto_2(fpPantalla);
    punto_3(fpPantalla, &lista);
    punto_4(fpPantalla, &lista);
    punto_5(fpPantalla);

    fclose(fpPantalla);
#ifdef CODIGO_ALUMNO
    system("start Notepad pantalla.txt");
#else
    system("start Notepad pantallaBIEN.txt");
#endif

    vaciarLista(&lista);
    return 0;
}


/** función: punto_1
 **
 **/
void punto_1(FILE *fpPantalla)
{
    char cadena1[] = {"Bloque antes   del movimiento"},
         cadena2[] = {"Bloque despues"};

    fprintf(fpPantalla,
            "************************************************************\n"
            "*    Punto 1: comienza a ejecutarse.                       *\n"
            "************************************************************\n");
    fprintf(fpPantalla, "- Cadena al inicio: %s\n", cadena1);
#ifdef PUNTO_1
        mi_memmove_MIO(cadena1, cadena2, 14);
#else
        mi_memmove(cadena1, cadena2, 14);
#endif

    fprintf(fpPantalla, "- Cadena al final:  %s\n", cadena1);
    fprintf(fpPantalla,
            "************************************************************\n"
            "*    Fin ejecución Punto 1.                                 *\n"
            "************************************************************\n\n");
}

/** función: punto_2
 **
 **/
void punto_2(FILE *fpPantalla)
{
    fprintf(fpPantalla,
            "************************************************************\n"
            "*    Punto 2: comienza a ejecutarse.                       *\n"
            "************************************************************\n");

#ifdef PUNTO_2
        fusionarMaestros_MIO(NOMBRE_ARCHIVO_1,
                                          NOMBRE_ARCHIVO_2,
                                          NOMBRE_ARCHIVO_FUSION);
#else
        fusionarMaestros(NOMBRE_ARCHIVO_1,
                         NOMBRE_ARCHIVO_2,
                         NOMBRE_ARCHIVO_FUSION);
#endif

    fprintf(fpPantalla, "- Contenido del archivo maestro fusionado:\n");
    mostrarArchivoMaestro(NOMBRE_ARCHIVO_FUSION, fpPantalla);
    fprintf(fpPantalla,
            "************************************************************\n"
            "*    Fin ejecución Punto 2.                                *\n"
            "************************************************************\n\n");
}


/** función: punto_3
 **
 **/
void punto_3(FILE *fpPantalla, tLista *pl)
{
    fprintf(fpPantalla,
            "************************************************************\n"
            "*    Punto 3: comienza a ejecutarse.                       *\n"
            "************************************************************\n");

#ifdef PUNTO_3
        cargarMaestroEnListaYeliminarDuplicados_MIO(NOMBRE_ARCHIVO_FUSION,
                                                    pl,
                                                    fpPantalla);
#else
        cargarMaestroEnListaYeliminarDuplicados(NOMBRE_ARCHIVO_FUSION,
                                                pl,
                                                fpPantalla);
#endif

    fprintf(fpPantalla, "\n- Nuevo contenido del archivo maestro:\n\n");
    mostrarArchivoMaestro(NOMBRE_ARCHIVO_FUSION, fpPantalla);
    fprintf(fpPantalla,
            "************************************************************\n"
            "*    Fin ejecución Punto 3.                                *\n"
            "************************************************************\n\n");
}


/** función: punto_4
 **
 **/
void punto_4(FILE *fpPantalla, tLista *pl)
{
    unsigned int n = 3;
    int eliminados;

    fprintf(fpPantalla,
            "************************************************************\n"
            "*    Punto 4: comienza a ejecutarse.                       *\n"
            "************************************************************\n");
    fprintf(fpPantalla,
            "- Lista antes de la eliminacion de los ultimos %d nodos:\n\n",
            n);

    recorrerLista(pl,  sizeof(tProducto), fpPantalla, mostrarProducto);

#ifdef PUNTO_4
        eliminados = elimnarUltimosNelementosDeLista_MIO(pl, n);
#else
        eliminados = elimnarUltimosNelementosDeLista(pl, n);
#endif

    fprintf(fpPantalla,
            "\n- Lista luego de la eliminacion de los ultimos %d nodos:\n\n",
            n);

    recorrerLista(pl,  sizeof(tProducto), fpPantalla, mostrarProducto);

    fprintf(fpPantalla,
            "\n- Se eliminaron %d nodos\n\n", eliminados);

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
    int cantActualizaciones;
    fprintf(fpPantalla,
            "************************************************************\n"
            "*    Punto 5: comienza a ejecutarse.                       *\n"
            "************************************************************\n");

    fprintf(fpPantalla, "- Contenido del archivo maestro:\n");
    mostrarArchivoMaestro(NOMBRE_ARCHIVO_FUSION, fpPantalla);
    fprintf(fpPantalla, "\n- Contenido del archivo novedades:\n");
    mostrarArchivoNovedades(NOMBRE_ARCHIVO_NOV, fpPantalla);

#ifdef PUNTO_5
    cantActualizaciones =
        actualizarMaestroDesdeArchivoDeNovedades_MIO(NOMBRE_ARCHIVO_FUSION,
                                                     NOMBRE_ARCHIVO_NOV,
                                                     fpPantalla);
#else
    cantActualizaciones =
        actualizarMaestroDesdeArchivoDeNovedades(NOMBRE_ARCHIVO_FUSION,
                                                 NOMBRE_ARCHIVO_NOV,
                                                 fpPantalla);
#endif

    fprintf(fpPantalla, "\n- Contenido del archivo maestro actualizado:\n");
    mostrarArchivoMaestro(NOMBRE_ARCHIVO_FUSION, fpPantalla);
    fprintf(fpPantalla,
            "\n- Se realizaron %d actualizaciones.\n",
            cantActualizaciones);

    fprintf(fpPantalla,
            "************************************************************\n"
            "*    Fin ejecución Punto 5.                                *\n"
            "************************************************************\n\n");
}
