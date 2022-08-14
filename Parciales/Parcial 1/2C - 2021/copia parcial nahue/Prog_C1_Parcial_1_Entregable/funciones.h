/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* CUALQUIER MODIFICACIÓN QUE HAGA NO SERÁ TENIDA EN CUENTA.      *//**/
/**//**//*                                                                *//**/
/**//**//*     ¡No debería hacer ninguna modificación en este archivo!    *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pila.h"
#include "que_hice.h"
#include "tda_definiciones.h"

#define NOMBRE_ARCHIVO_1      "maestro1.dat"
#define NOMBRE_ARCHIVO_2      "maestro2.txt"
#define NOMBRE_ARCHIVO_FUSION "maestro_fusion.dat"
#define NOMBRE_ARCHIVO_NOV    "novedades.bin"

//#define ES_BLANCO(X) ((X) == ' ' || (X) == '\t')
#define aMayusc(X) ((X) >= 'a' && (X) <= 'z' ? (X)-32 : (X))
#define aMinusc(X) ((X) >= 'A' && (X) <= 'Z' ? (X)+32 : (X))
#define MIN(x,y) ((x)<(y)?(x):(y))
typedef struct
{
    int dia,
        mes,
        anio;
}tFecha;

typedef struct
{
    long idProducto;
    char descripcion[26];
    tFecha fecUltAct;
    int cantidad;
    float precioUnitario;
}tProducto;

typedef struct
{
    long idProducto;
    char tipoMovimiento;
    int cantidad;
}tNovedad;

/** funciones de servicio **/
int crearArchivos(char *nombreArchivo1, char *nombreArchivo2);
int crearArchivoNovedades(char *nombreArchivo);
void mostrarProducto(const void *d, FILE *fpPantalla);
void mostrarArchivoMaestro(char *nomnreArchivoMaestro, FILE *fpPantalla);
void mostrarArchivoNovedades(char *nombreArchivoNovedades, FILE *fpPantalla);
void crearLista(tLista *p);
void vaciarLista(tLista *p);
void recorrerLista(const tLista *p,
                   unsigned cantBytes,
                   FILE *fpPantalla,
                   void (*mostrar)(const void *, FILE *));



/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/** para el PUNTO 1 **/
void *mi_memmove(void *str1, const void *str2, size_t n);
void *mi_memmove_MIO(void *str1, const void *str2, size_t n);

/** para el PUNTO 2 **/
void Normalizar2(tProducto *prod);
void unicoEspacio(char* nombre);
void eliminarEspacioPrincipioFin(char *nombre);
void CamelCase(char * nombre);
void trozarCamposLongitudVariable(tProducto *d, char *s);
int fusionarMaestros(char *nombreArchivo1,
                     char *nombreArchivo2,
                     char *nombreArchivoF);

int fusionarMaestros_MIO(char *nombreArchivo1,
                         char *nombreArchivo2,
                         char *nombreArchivoF);

/** para el PUNTO 3 **/
int cargarMaestroEnListaYeliminarDuplicados(char *nombreArchivoMaestro,
                                            tLista *pl,
                                            FILE *fpPantalla);
void eliminarDuplicadosLista(tLista *pl,const void *pd,unsigned tam,int (*cmp)(const void*, const void*));
int cargarMaestroEnListaYeliminarDuplicados_MIO(char *nombreArchivoMaestro,
                                                tLista *pl,
                                                FILE *fpPantalla);

/** para el PUNTO 4 **/
int elimnarUltimosNelementosDeLista(tLista *pl, unsigned int n);

int elimnarUltimosNelementosDeLista_MIO(tLista *pl, unsigned int n);


/** para el PUNTO 5 **/
void mostrarLista(tLista *pl);
void mostrar(void *info);
int listaVacia(const tLista *pl);
int sacarPrimeroLista(tLista *pl,void *pd,unsigned tam);
void ordenarIdProducto(char *nombreArchivoMaestro,tProducto *prod,int (*cmp)(const void*, const void*));
int cmp_ent(const void* d1, const void* d2);
int cmpIDproducto(const void *id1, const void *id2);

int actualizarMaestroDesdeArchivoDeNovedades(char *nombreArchivoMaestro,
                                             char *nombreArchivoNovedades,
                                             FILE *fpPantalla);

int actualizarMaestroDesdeArchivoDeNovedades_MIO(char *nombreArchivoMaestro,
                                                 char *nombreArchivoNovedades,
                                                 FILE *fpPantalla);

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
#endif

