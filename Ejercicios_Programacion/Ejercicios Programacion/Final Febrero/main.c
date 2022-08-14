#include <stdio.h>
#include <stdlib.h>

#include "Funciones.h"

#define ERR_VERIFICAR 1
#define ERR_CARGAR 2
#define ERR_SUMAR 3
#define ERR_IMPRIMIR 4
#define ERR_GUARDAR 5

int main()
{
    if(!verificar_mat("mat1.txt", "mat2.txt", "suma.txt"))
        return ERR_VERIFICAR;

    Matriz mat1;
    if(!cargar_mat(&mat1, "mat1.txt"))
        return ERR_CARGAR;

    Matriz mat2;
    if(!cargar_mat(&mat2, "mat2.txt"))
        return ERR_CARGAR;

    Matriz mat3;
    if(!sumar_mat(&mat1, &mat2, &mat3))
        return ERR_SUMAR;

    puts("Imprimiendo matriz 1");
    if(!imprimir_mat(&mat1))
        return ERR_IMPRIMIR;

    puts("Imprimiendo matriz 2");
    if(!imprimir_mat(&mat2))
        return ERR_IMPRIMIR;

    puts("Imprimiendo matriz 3");
    if(!imprimir_mat(&mat3))
        return ERR_IMPRIMIR;

    guardar_mat(&mat1, "mat1.txt");
    guardar_mat(&mat2, "mat2.txt");
    guardar_mat(&mat3, "suma.txt");

    return 0;
}
