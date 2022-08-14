#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "ListaDinamicaSimple.h"

typedef struct
{
    int cantFilas;
    int cantColumnas;
    Lista listaValNoNulos;
} Matriz;

typedef struct
{
    int fila;
    int columna;
    int valor;
} ValorNoNuloMat;

// Esta función verifica si es posible alcanzar el objetivo propuesto. Esta función
// debe invocarse antes de cargar las matrices en memoria.
booleano verificar_mat(const char* nomArch1, const char* nomArch2, const char* nomArch3);

// Función para cargar una matriz en memoria.
// Carga en memoria una matriz dispersa de forma tal de poder realizar la suma de matrices. Usted
// debe seleccionar la estructura de datos más conveniente. Debe optimizar el uso de memoria.
booleano cargar_mat(Matriz* mat, const char* nomArch);

// Función que realiza la suma de dos matrices. Optimizar el uso de memoria.
booleano sumar_mat(Matriz* mat1, Matriz* mat2, Matriz* mat3);

// recibe una matriz dispersa y la muestra completa (con todos los valores,
// incluyendo los valores nulos).
booleano imprimir_mat(Matriz* mat);

// recibe una matriz dispersa y la guarda en un archivo de texto, respetando el
// formato solicitado. Luego de ejecutada esta función ya no estará disponible la matriz.
booleano guardar_mat(Matriz* mat, const char* nomArch);

#endif // FUNCIONES_H
