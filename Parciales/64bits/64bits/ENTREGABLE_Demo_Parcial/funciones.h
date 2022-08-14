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

typedef struct
{
    int dia,
        mes,
        anio;
}tFecha;

typedef struct
{
    long dni;
    char apyn[36];
    char categoria;
    tFecha fecIngreso;
    float sueldo;
}tEmpleado;

/** funciones de servicio **/
int  crearArchivo(char *nombreArchivo);
void crearPila(tPila *p);
int  pilaLlena(const tPila *p, unsigned cantBytes);
int  ponerEnPila(tPila *p, const void *d, unsigned cantBytes);
int  verTope(const tPila *p, void *d, unsigned cantBytes);
int  pilaVacia(const tPila *p);
int  sacarDePila(tPila *p, void *d, unsigned cantBytes);
void vaciarPila(tPila *p);

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/** para el PUNTO 1 **/
char *pasarAmayuscula(char *s);
char *pasarAmayuscula_MIO(char *s);

/** para el PUNTO 2 **/
int apilarDesdeArchivoYdesapilar(char *nombreArchivo, FILE *fpPantalla);
int apilarDesdeArchivoYdesapilar_MIO(char *nombreArchivo, FILE *fpPantalla);

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* FUNCIONES A DESARROLLAR                                            *//**/

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

#endif

