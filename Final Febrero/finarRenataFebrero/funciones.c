#include "funciones.h"

//antes de cargar la matriz rala, hay que verificar si
/*
- Si en la fila o en la columna no se carga un cero,
 no es rala

- Tanto en la fila como en la col, los elementos 0
 tienen que ser mayor o igual a los valores no nulos

*/

int cargar_mat(FILE * archivoMatriz,int mat[][TAM_MAX],int ordenMatriz)
{
    tMatrizRala m;

    char linea[100];

    while(fgets(linea,sizeof(linea),archivoMatriz))
    {
        trozarLongitudVariable(&m,linea);

        if(verificar_mat(&m,ordenMatriz) != TODO_BIEN) //podría usarse lo de matriz cuadrada, pero nomás obtenés el dato a la primera linea
            return FAIL;
        else
            mat[m.fila][m.col] = m.valor;
    }

    return TODO_BIEN;
}


int verificar_mat(const tMatrizRala *m, int ordenMatriz)
{
    if(m->valor == 0 || (m->fila > ordenMatriz || m->col > ordenMatriz))
        return FAIL;

    return TODO_BIEN;
}

void sumar_mat(int mat1[][TAM_MAX],
               int mat2[][TAM_MAX],
               int matRes[][TAM_MAX],
               int orden1,int orden2)
{
    int i,j;

    for(i = 0; i < orden1 ; ++i)
    {
        for(j = 0; j < orden2; ++j)
        {
            matRes[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void imprimir_mat(int mat[][TAM_MAX],int orden)
{
    int i, j;

    for(i = 0; i < orden ; ++i)
    {
        for(j = 0; j < orden ; ++j)
        {
            printf("%d \t",mat[i][j]);
        }
        printf("\n");
    }

}

void guardar_mat(int matRala[][TAM_MAX],int orden, FILE *archivoMatriz)
{
    int i,j;

    fprintf(archivoMatriz,"[%d][%d]\n",orden,orden);

    for(i = 0; i < orden; ++i)
    {
        for(j = 0; j < orden; ++j)
        {
            if(matRala[i][j] != 0)
            {
                fprintf(archivoMatriz,"[%d][%d]%d\n",i,j,matRala[i][j]);
            }
        }
    }

}
