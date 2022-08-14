#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include "main.h"
#include "utils.h"

int cargar_mat(FILE * archivoMatriz,int mat[][TAM_MAX],int ordenMatriz);


int verificar_mat(const tMatrizRala *m, int ordenMatriz);


void sumar_mat(int mat1[][TAM_MAX],
               int mat2[][TAM_MAX],
               int matRes[][TAM_MAX],
               int orden1,int orden2);

void imprimir_mat(int mat[][TAM_MAX],int orden);
void guardar_mat(int matRala[][TAM_MAX],int orden, FILE *archivoMatriz);

#endif // FUNCIONES_H_INCLUDED
