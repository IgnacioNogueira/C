#include "main.h"
#include "funciones.h"
#include "utils.h"

int main()
{
    FILE *fpm1,*fpm2,*fpr;
    int orden1,orden2;

    int mat1[TAM_MAX][TAM_MAX];
    int mat2[TAM_MAX][TAM_MAX];
    int matR[TAM_MAX][TAM_MAX];

    fpm1 = fopen(NOMBRE_ARCHIVO_MAT_1,"rt");

    if(!fpm1)
        return ERROR_ARCH;


    fpm2 = fopen(NOMBRE_ARCHIVO_MAT_2,"rt");

    if(!fpm2)
    {
        fclose(fpm1);
        return ERROR_ARCH;
    }

    fpr = fopen(NOMBRE_ARCHIVO_MAT_RES,"wb");

    if(!fpr)
    {
        fclose(fpm1);
        fclose(fpm2);
        return ERROR_ARCH;
    }

    orden1 = ordenMatriz(fpm1);
    orden2 = ordenMatriz(fpm2);

    if(orden1 != FAIL && orden2 != FAIL)
    {
        cargar_mat(fpm1,mat1,orden1);
        printf("\nMatriz 1:\n");
        imprimir_mat(mat1,orden1);
        cargar_mat(fpm2,mat2,orden2);
        printf("\nMatriz 2:\n");
        imprimir_mat(mat2,orden2);
        printf("\nMatriz resultado:\n");
        sumar_mat(mat1,mat2,matR,orden1,orden2);
        imprimir_mat(matR,orden1);
        guardar_mat(matR,orden1,fpr);
    }
    else
    {
        fprintf(fpr,"\nUNA DE LAS MATRICES NO ES CUADRADA, ERROR\n");
        printf("\nUNA DE LAS MATRICES NO ES CUADRADA, ERROR\n");
        return FAIL;
    }

    fclose(fpm1);
    fclose(fpm2);
    fclose(fpr);
    return 0;
}

