#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include "arbol.h"
#define NOMBRE_ARCHIVO_FUSION "maestro_fusion.dat"


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

typedef struct
{
   unsigned clave;
   unsigned pos;

}tIndice;

int cmp_ent(const void *v1,const void *v2);
int cmp_ind(const void *v1,const void *v2);
int cmpNodosPares(const void *v1, unsigned tamNodoInfo);

void imprimirConForma(void *info,unsigned tam,unsigned n, void * params);
void imprimir(void *info,unsigned tam,unsigned n,void * params);
void imprimirEnArchivo(const void *info,unsigned tamInfo,void *params,unsigned tamArch);
unsigned leerDesdeVectorEnteros(void **d, void *vec,unsigned pos,void *params);
unsigned leerDesdeArchivoArchivoBin(void **d,void *pf,unsigned pos,void *params);
int cargarArchivoBinOrdenadoAbiertoBinBusq(tArbolBinBusq *p,FILE *pf, unsigned tamInfo);
int cargarArchivoBinOrdenadoArbolBinBusq(tArbolBinBusq *p,const char * path,unsigned tamInfo);



int cargarIndiceArbolArch(const char *nombreArchivo,tArbolBinBusq *p,
                      int(*cmp)(const void *,const void*));
int guardarArbolGeneradoArchTemp(tArbolBinBusq *arb,void (*accion)(const void *dato,void *contexto));
void guardarRegIndiceArchivo(const void *dato, void *contexto);
void inOrderArchivos(tArbolBinBusq *p,void (*accion)(const void *dato, void *contexto),void *param);
int cargarArbolArchivoINDTemp(tArbolBinBusq *p,int (*cmp)(const void *,const void *));
int cargarArbolArchivoINDTemp_Int(tArbolBinBusq *p,int li,int ls,FILE* archivo,
                                  int (*cmp)(const void *,const void *));



///MOSTRAR
int leerYMostrarArchivo(const char *nombreArchivo);
void mostrarArchivoMaestro(tProducto *prod);
void mostrarIndice (void * info);




#endif // UTILS_H_INCLUDED
