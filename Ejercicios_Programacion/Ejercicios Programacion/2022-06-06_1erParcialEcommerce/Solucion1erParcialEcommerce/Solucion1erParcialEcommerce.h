#ifndef SOLUCION_1ER_PARCIAL_ECOMMERCE_H
#define SOLUCION_1ER_PARCIAL_ECOMMERCE_H

#include "../Comun/Comun.h"


typedef struct
{
    char usuario[21];
    char nombre[51];
    char apellido[51];
    int nivel;
}
Cliente;


typedef struct
{
    char codigo[16];
    char descripcion[51];
    float precio;
}
Producto;


typedef struct
{
    int nivel;
    float porcDescuento;
    float topeDescuento;
    float minimoParaEnvioGratis;
}
Regla;


typedef struct
{
    char usuario[21];
    char producto[16];
    float precio;
    booleano envioGratis;
}
Oferta;


int generarArchivoOfertas(const char* nombreArchClientes, const char* nombreArchProductos, const char* nombreArchReglas, const char* nombreArchOfertas);
int generarArchivoOfertasTxt(const char* nombreArchivoOfertas, const char* nombreArchivoOfertasTxt);
int generarArchivoOfertas_ALU(const char* nombreArchClientes, const char* nombreArchProductos, const char* nombreArchReglas, const char* nombreArchOfertas);
int generarArchivoOfertasTxt_ALU(const char* nombreArchivoOfertas, const char* nombreArchivoOfertasTxt);
void generarArchivoClientes(const char* nombreArchClientes);
void generarArchivoProductos(const char* nombreArchProductos);
void generarArchivoReglas(const char* nombreArchReglas);
int mostrarArchivoOfertas(const char* nombreArchOfertas);
int mostrarArchivoOfertasTxt(const char* nombreArchivoOfertasTxt);
void cambiarExtension(const char* nombreArchivoOrig, char* nombreArchivoConExtension, const char* extension);


#endif //SOLUCION_1ER_PARCIAL_ECOMMERCE_H
