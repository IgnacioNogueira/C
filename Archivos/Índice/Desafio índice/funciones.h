#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOM_ARCH_MAESTRO "maestroProductos.dat"
#define NOM_ARCH_NOVEDAD "novedades.txt"


#define minimo( X , Y ) ( ( X ) <= ( Y ) ? ( X ) : ( Y ) )



typedef struct
{
    int dia,
        mes,
        anio;
} tFecha;


typedef struct
{
    long idProducto;
    char descripcion[26];
    tFecha fecUltAct;
    int cantidad;
    float precioUnitario;
} tProducto;

typedef struct
{
    long idProducto;
    char tipoMovimiento;
    int cantidad;
} tNovedad;

typedef struct
{
    long clave;
    int pos;
}tIndice;

typedef struct sNodo
{
    void *info;
    unsigned tamInfo;
    struct sNodo *sig;
}tNodo;

typedef tNodo* tLista;

int abrirArchivo(FILE **fp,
                 const char *nombreArchivo,
                 const char *modoApertura,
                 int mostrarError);
void mostrarProducto (const tProducto *prod);
int leerYMostrarArchivo (const char *nombreArchivo);
int leerYMostrarArchivoDeTexto(const char *nombreArchivo);
int cmp(const void * v1, const void * v2);
int ponerAlFinal(tLista *p, const void *d, unsigned cantBytes);
void crearIndice(const char * nombre, tIndice * ind, tLista * lista, FILE * pf);
void trozarCamposLongitudVariable(tNovedad *d, char *cad);
int actualizarMaestro(const char * nombreArchivoM, const char * nombreArchivoN, tLista * lista);

int buscarEnListaNuevo(tLista *pl,void *d,unsigned cantBytes,
                       int (*cmp)(const void *,const void*));



#endif // FUNCIONES_H_INCLUDED
