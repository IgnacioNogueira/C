#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TODO_BIEN 1
#define FAIL 0
#define ERROR_ARCH -1

#define TAM_MAX 100

#define NOMBRE_ARCHIVO_MAT_1 "mat1.txt"
#define NOMBRE_ARCHIVO_MAT_2 "mat2.txt"
#define NOMBRE_ARCHIVO_MAT_RES "suma.txt"

typedef struct
{
    int valor;
    int fila;
    int col;

}tMatrizRala;

#endif // MAIN_H_INCLUDED
