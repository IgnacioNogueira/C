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

#define NOMBRE_ARCHIVO_CUENTAS      "cuentas.dat"
#define NOMBRE_ARCHIVO_NOVEDADES    "novedades.dat"

#define ALTURA_PODA 2

#define minimo( X , Y )     ( ( X ) <= ( Y ) ? ( X ) : ( Y ) )

typedef struct
{
    int nro;
    char tipo;
    int secuencia;
    char titular[26];
    float saldo;
    char estado;
}tCuenta;

typedef struct
{
    int nro;
    char tipo;
    int secuencia;
    float monto;
}tNovedad;

/**
    Indice
*/

typedef struct
{
    int nro;
    char tipo;
    int secuencia;
} tClave;

typedef struct
{
    tClave clave;
    unsigned indiceRegistro;
} tIndice;


/** funciones de servicio **/
int crearArchivoCuentas(char *nombreArchivoCuentas);
int crearArchivoNovedades(char *nombreArchivoNovedades);

void mostrarCuenta(const void *d, FILE *fpPantalla);
void mostrarArchivoCuentas(char *nombreArchivoMaestro, FILE *fpPantalla);
void mostrarNovedad(const void *d, FILE *fpPantalla);
void mostrarArchivoNovedades(char *nombreArchivoNovedades, FILE *fpPantalla);

/** Arbol */
void crearArbol(tArbol *p);
void mostrarArbolIndice(const tArbol *p, FILE *fpPantalla);
void eliminarArbol(tArbol *p);


/** Lista doblemente enlazada */
void crearLista(tLista *p);
int  vaciarLista(tLista *p);
int  mostrarDeIzqADer(const tLista *p,
                      void(*mostrar)(const void *, FILE *), FILE *fp);
int  insertarEnOrden(tLista *p, const void *d, unsigned cantBytes,
                     int (*comparar)(const void *, const void *),
                     int (*acumular)(void **, unsigned *,
                                     const void *, unsigned));

/** Cola en lista circular */
void crearCola(tCola *p);


/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

/** para el PUNTO 1 **/
int indexarArchivoCuentas(char *nombreArchivoCuentas, tArbol *p);
int indexarArchivoCuentas_MIO(char *nombreArchivoCuentas, tArbol *p);

/** para el PUNTO 2 **/
int cargarArchivoNovedadesEnLista(FILE *fpPantalla,
                                  char *nombreArchivoNovedades,
                                  tLista *p);
int cargarArchivoNovedadesEnLista_MIO(FILE *fpPantalla,
                                  char *nombreArchivoNovedades,
                                  tLista *p);

/** para el PUNTO 3 **/
int cargarNovedadesEnColaDesdeLista(tLista *pl,
                                    tCola *pc,
                                    FILE *fpPantalla);
int cargarNovedadesEnColaDesdeLista_MIO(tLista *pl,
                                        tCola *pc,
                                        FILE *fpPantalla);

/** para el PUNTO 4 **/
int actualizarArchivoDeCuentasDesdeColaDeNovedades(FILE *fpPantalla,
                                                   char *nombreArchivoCuentas,
                                                   tCola *cola,
                                                   tArbol *idx);
int actualizarArchivoDeCuentasDesdeColaDeNovedades_MIO(FILE *fpPantalla,
                                                   char *nombreArchivoCuentas,
                                                   tCola *cola,
                                                   tArbol *idx);

/** para el PUNTO 5 **/
int podarIndiceYEncolarPodados(FILE *fpPantalla,
                               tArbol *indice,
                               tCola *cola,
                               int alturaPoda);
int podarIndiceYEncolarPodados_MIO(FILE *fpPantalla,
                                   tArbol *indice,
                                   tCola *cola,
                                   int alturaPoda);

 /** para el PUNTO 6 **/
int actualizarEstadosArchivoCuentasDesdeCola(FILE *fpPantalla,
                                             char *nombreArchivoCuentas,
                                             tCola *cola);
int actualizarEstadosArchivoCuentasDesdeCola_MIO(FILE *fpPantalla,
                                                 char *nombreArchivoCuentas,
                                                 tCola *cola);

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
#endif

