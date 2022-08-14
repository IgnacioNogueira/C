/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* CUALQUIER MODIFICACIÓN QUE HAGA NO SERÁ TENIDA EN CUENTA.      *//**/
/**//**//*                                                                *//**/
/**//**//*     ¡No debería hacer ninguna modificación en este archivo!    *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <stdio.h>

#include "que_hice.h"
#include "tda_definiciones.h"

#define NOMBRE_ARCHIVO_MBIN     "maestro.dat"
#define NOMBRE_ARCHIVO_MTXT     "maestro.txt"
#define NOMBRE_ARCHIVO_MCONS    "maestro_consolidado.dat"
#define NOMBRE_ARCHIVO_NOV      "novedades.bin"

#define TAM_MAT 5

typedef struct
{
    int dia,
        mes,
        anio;
}tFecha;

typedef struct
{
    unsigned int idProducto;
    char descripcion[21];
    tFecha fechaPrecio;
    int cantidad;
    float precioUnitario;
}tProducto;

typedef struct
{
    unsigned int idProducto;
    char tipoMovimiento;
    int cantidad;
}tNovedad;

/** funciones de servicio para el contexto del progama**/
int crearArchivos(char *nombreArchivo1, char *nombreArchivo2);
int crearArchivoNovedades(char *nombreArchivo);
void mostrarProducto(const void *d, FILE *fpPantalla);
void mostrarArchivoMaestroBin(char *nomnreArchivoMaestro, FILE *fpPantalla);
void mostrarArchivoMaestroTxt(char *nomnreArchivoMaestro, FILE *fpPantalla);
void mostrarArchivoNovedades(char *nombreArchivoNovedades, FILE *fpPantalla);

/** funciones que pueden ser utilizadas or Usted **/
void mostrarProducto(const void *d, FILE *fpPantalla);
void mostrarNovedad(const void *d, FILE *fpPantalla);
void crearLista(tLista *p);
void vaciarLista(tLista *p);
int  listaVacia(const tLista *p);
void recorrerLista(const tLista *p,
                   FILE *fpPantalla,
                   void (*mostrar)(const void *, FILE *));

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/** para el PUNTO 1 **/
int punto_uno(FILE *fpPantalla,
              const char *nombreArchMaestro1,
              const char *nombreArchMaestro2,
              tLista *listaA,
              tLista *listaB);

int punto_uno_MIO(FILE *fpPantalla,
              const char *nombreArchMaestro1,
              const char *nombreArchMaestro2,
              tLista *listaA,
              tLista *listaB);

/** para el PUNTO 2 **/
int punto_dos(FILE *fpPantalla,
              tLista *listaA,
              tLista *listaB,
              tLista *listaF);

int punto_dos_MIO(FILE *fpPantalla,
                  tLista *listaA,
                  tLista *listaB,
                  tLista *listaF);

/** para el PUNTO 3 **/
int punto_tres(FILE *fpPantalla,
               tLista *listaF,
               const char *nombreArchMaestroCons);

int punto_tres_MIO(FILE *fpPantalla,
                   tLista *listaF,
                   const char *nombreArchMaestroCons);

/** para el PUNTO 4 **/
int punto_cuatro(FILE *fpPantalla,
                 const char *nombreArchivoMaestro,
                 const char *nombreArchivoNovedades);

int punto_cuatro_MIO(FILE *fpPantalla,
                     const char *nombreArchivoMaestro,
                     const char *nombreArchivoNovedades);

/** para el PUNTO 5 **/
int punto_cinco(FILE *fpPantalla, int mat[][TAM_MAT]);
int punto_cinco_MIO(FILE *fpPantalla, int mat[][TAM_MAT]);

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
#endif

