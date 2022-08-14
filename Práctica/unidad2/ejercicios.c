#include "ejercicios.h"
#include "funciones.h"

void EjercicioEliminarLetMasRepetida()
{
    char letra;
    //int cantElem;
    char strLetras[tam] = "aa a bbb cc dddd d e zzzzzzzz";

    letra = letraMasRepetida(strLetras);
    printf("\n- La letra más repetida es: %c\n",letra);
    //cantElem = eliminarLetraMasRepetida(strLetras,letra);

    //printf("\n- Se eliminaron %d letras, quedando el string: %s\n",cantElem,strLetras);
}

void ejercicio8()
{
    char textComp[] = "Hola   ,como  estas, hola!.";
    unSoloEspacio(textComp);

}



/*
    Dado un array de char que contiene un texto compuesto por palabras que termina en '.' (o en su defecto en carácter nulo -'\0'-), escriba un programa en que determine e informe:

    (Lista) a- cuál es la primera palabra y cuántas veces se repite en el texto
    (Hecho en otra oportunidad) b- cuántas palabras tiene el texto
    (Lista) c- longitud de la palabra más larga
*/

void ejercicio12()
{
    printf("\n- Ejercicio 12 - Modificado un toque\n");
    tAlumno alumno;


    if(crearArchivoBin(NOMBRE_ARCHIVO_BIN))
    {
        printf("\n-- Archivo binario --\n");
        printf("\n   Apellido/s, Nombre/s                 P. 1  P. 2  P. 3  P. 4  P. 5  P. 6\n");
        printf("\n   =================================== ===== ===== ===== ===== ===== =====\n");
        leerYmostrarArchivoBinNotas(NOMBRE_ARCHIVO_BIN);
        printf("\n");
        promAlumnos(NOMBRE_ARCHIVO_BIN,&alumno,6);
        //final
        crearArchivoLF(NOMBRE_ARCHIVO_BIN,NOMBRE_ARCHIVO_TXT);
        printf("\n-- Archivo binario2 (Con promedio) --\n");
        printf("\n   Apellido/s, Nombre/s                 P. 1  P. 2  P. 3  P. 4  P. 5  P. 6 - Promedio\n");
        printf("\n   =================================== ===== ===== ===== ===== ===== =====   ========\n");
        leerYmostrarArchivoBinNotas2(NOMBRE_ARCHIVO_BIN);

        printf("\n-- Archivo de texto --\n");
        printf("\n   Apellido/s, Nombre/s                 P. 1  P. 2  P. 3  P. 4  P. 5  P. 6 - Promedio\n");
        printf("\n   =================================== ===== ===== ===== ===== ===== =====   ========\n");
        leerYmostrarArchivoTxt(NOMBRE_ARCHIVO_TXT2);

    }
    else
    {
        printf("\nNo se pudo crear el archivo %s, error",NOMBRE_ARCHIVO_BIN);
    }

}
