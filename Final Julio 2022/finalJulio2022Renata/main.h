#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TODO_BIEN 1
#define FAIL -1
#define ERROR_ARCH -2
#define ERROR_LOTE -3
#define ERROR_LISTA -4

#define NOMBRE_ARCHIVO_LOTE_PRUEBA "LotePrueba.bin"
#define NOMBRE_ARCHIVO_FINAL "ArchivoFinal.txt"

typedef struct
{
    char cod[6];
    char sector;
    int cant;

}tPedidos;


#endif // MAIN_H_INCLUDED
