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
void mostrarNodoIndice(const tIndice *p, FILE *fpPantalla);

/** Lista doblemente enlazada */
void crearLista(tLista *p);
int  vaciarLista(tLista *p);
int  listaVacia(const tLista *p);
int  mostrarDeIzqADer(const tLista *p,
                      void(*mostrar)(const void *, FILE *), FILE *fp);


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
int actualizarArchivoDeCuentasDesdeListaDeNovedades(FILE *fpPantalla,
                                                   char *nombreArchivoCuentas,
                                                   tLista *lista,
                                                   tArbol *idx);
int actualizarArchivoDeCuentasDesdeListaDeNovedades_MIO(FILE *fpPantalla,
                                                   char *nombreArchivoCuentas,
                                                   tLista *lista,
                                                   tArbol *idx);

/** para el PUNTO 4 **/
void mostrarArbolEnPreorden_MIO(const tArbol *p,
                                FILE *fpPantalla);

void mostrarArbolEnPreorden(const tArbol *p,
                            FILE *fpPantalla);


/** para el PUNTO 5 **/
int contarNodosIndiceRegistroPar(const tArbol *p);
int contarNodosIndiceRegistroPar_MIO(const tArbol *p);

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
#endif

