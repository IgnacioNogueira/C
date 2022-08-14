#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define CLA_DUP 0
#define SIN_MEM 0
#define SIN_INICIALIZAR 0
#define ERROR_ARCH 0
#define TODO_BIEN 1
#define MINIMO(X,Y)( (X)<=(Y)?(X):(Y) )

#define NOMBRE_ARCHIVO_MAESTRO_PRODUCTOS "maestroProductos.dat"
#define NOMBRE_ARCHIVO_NOVEDADES "novedades.txt"
#define NOMBRE_ARCHIVO_CUENTAS_NO_EXISTENTES "Cuentas no existentes.dat"

#define ALTURA_PODA 2

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
    float precioUnitario;
}tNovedad;

typedef struct
{
   unsigned clave;
   unsigned pos;

}tIndice;


#endif // MAIN_H_INCLUDED
