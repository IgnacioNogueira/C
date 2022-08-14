/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//*      ACÁ NO DEBE HACER NINGUNA MODIFICACIÓN                    *//**/
/**//**//*      SÓLO PARA SUS PRUEBAS CON LOS DISTINTOS                   *//**/
/**//**//*      LOTES E INVOCAR A SUS FUNCIONES                           *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

#include "main.h"

int main()
{
    FILE   *fpPantalla;

    crearArchivo(NOMBRE_ARCHIVO);

#ifdef CODIGO_ALUMNO
    fpPantalla = fopen("pantalla.txt", "wt");
#else
    fpPantalla = fopen("pantallaBIEN.txt", "wt");
#endif
    if(fpPantalla == NULL)
        fpPantalla = stdout;

    punto_1(fpPantalla);
    punto_2(fpPantalla);

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
void punto_1(FILE *fpPantalla)
{
    char cadena[] = {"hoLa Mundo !!! - Hay 0 problemas. "};

    fprintf(fpPantalla,
            "************************************************************\n"
            "*    Punto 1: comienza a ejecutarse.                       *\n"
            "************************************************************\n");
    fprintf(fpPantalla, "- La función recibió:  %s\n", cadena);

#ifdef PUNTO_1
        pasarAmayuscula_MIO(cadena);
#else
        pasarAmayuscula(cadena);
#endif
        fprintf(fpPantalla, "- La función devolvió: %s\n", cadena);

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
    int procesados;
    fprintf(fpPantalla,
            "************************************************************\n"
            "*    Punto 2: comienza a ejecutarse.                       *\n"
            "************************************************************\n");

#ifdef PUNTO_2
        procesados = apilarDesdeArchivoYdesapilar_MIO(NOMBRE_ARCHIVO,
                                                      fpPantalla);
#else
        procesados = apilarDesdeArchivoYdesapilar(NOMBRE_ARCHIVO,
                                                  fpPantalla);
#endif
        fprintf(fpPantalla, "\n- Se procesaron: %d registro(s)\n", procesados);

    fprintf(fpPantalla,
            "************************************************************\n"
            "*    Fin ejecución Punto 2.                                *\n"
            "************************************************************\n\n");
}
