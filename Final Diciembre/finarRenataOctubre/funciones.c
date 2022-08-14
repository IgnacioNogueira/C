#include "funciones.h"


//antes de cargar la matriz rala, hay que verificar si
/*
- Si en la fila o en la columna no se carga un cero,
 no es rala

- Tanto en la fila como en la col, los elementos 0
 tienen que ser mayor o igual a los valores no nulos

*/

int cargar_mat_rala(const char *archivoMatrizRala, int *matRala)
{
    FILE *fp;
    tMatrizRala m;

    char linea[100];
    int v[1000];
    int f[1000];
    int c[1000];

    int r,i = 0;

    fp = fopen(archivoMatrizRala,"rt");

    if(!fp)
        return ERROR_ARCH;

    //los valores pueden verificarse para ver si es nxn
    fgets(linea,sizeof(linea),fp); //obtiene el tamaño de la matriz
    trozarLongitudVariable(&m,linea);

    if(!esMatrizCuadrada(&m))
        return FAIL;

    while(fgets(linea,sizeof(linea),fp))
    {
        trozarLongitudVariable(&m,linea);

        if(verificar_mat(&m) != TODO_BIEN) //podría usarse lo de matriz cuadrada, pero nomás obtenés el dato a la primera linea
            return FAIL;
        else
        {
            r = concatenarPosicion(&m);
            v[i] = r;
            f[i] = m.fila;
            c[i] = m.col;
            ++i;
        }
    }

    return TODO_BIEN;
}


int verificar_mat(const tMatrizRala *m)
{
    return m->valor == 0 ? FAIL:TODO_BIEN;
}

int cargar_mat_rala(const int *v,
                        const int *f,
                        const int *c,
                        int *mat)
{





}
