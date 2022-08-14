#include "matriz.h"

void menu(void)
{
    char opcion;

    do
    {
        printf("\n\n\n\n=======================MENU MATRICES=======================");
        printf("\n\nA- Ejercicio 29");
        printf("\n\nB- Ejercicio 30");
        printf("\n\nC- Ejercicio 31");
        printf("\n\nD- Ejercicio 32");
        printf("\n\nE- Ejercicio 33");
        printf("\n\nF- Ejercicio 34");
        printf("\n\nG- Ejercicio 35");
        printf("\n\nH- Ejercicio 36");
        printf("\n\nI- Ejercicio 37");

        printf("\n\n\n\n0- SALIR ");
        printf("\n\n\n[INGRESE OPCION]: ");
        fflush(stdin);

        scanf("%c", &opcion);
        opcion = aMayusc(opcion);


        switch(opcion)
        {
        case 'A':
            ejercicio29();
            break;

        case 'B':
            //ejercicio30();
            break;

        case 'C':
           // ejercicio31();
            break;

        case 'D':
           // ejercicio32();
            break;

        case 'E':
           // ejercicio33();
            break;

        case 'F':
          //  ejercicio34();
            break;

        case 'G':
          //  ejercicio35();
            break;

        case 'H':
           // ejercicio36();
            break;

        case 'I':
           // ejercicio37();
            break;

        case '0':
            exit(10);

        default:
            printf("\n\nNo esta en el abecedario, saliendo del programa...");
        }
    }
    while(opcion == 'A' || opcion == 'B' || opcion == 'C' || opcion == 'D'
            || opcion == 'E'|| opcion == 'F' || opcion == 'G' || opcion == 'H'
            || opcion == 'I');
}

void tab(int n)
{
    int i;

    for(i= 0; i<n; ++i)
    {
        printf("\t");
    }
}

void mostrarMatriz(const int mat[][col],int f,int c)
{
    int i,j;

    for(i=0; i<f; ++i)
    {
        for(j=0; j<c; ++j)
        {
            printf("%d \t", mat[i][j]);
        }
        printf("\n");
    }
}

int esMatrizCuadrada(int f,int c)
{
    return f == c;
}

void ejercicio29() ///PARA USAR LOS EJERCICIOS RESTANTES, IR DESCOMENTANDO DE A UNO Y COMENTANDO LOS DE ARRIBA DE A POCO
{

    int mat[][col]= {{1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15},
        {16,17,18,19,20},
        {21,22,23,24,25}
    };


    if(esMatrizCuadrada(fil,col))
    {
        printf("\n\n/////sumConDiagPrincipalInferior/////\n\n");
        sumConDiagPrincipalInferior(mat,fil,col);

        printf("\n\n/////sumSinDiagPrincipalInferior/////\n\n");
        sumSinDiagPrincipalInferior(mat,fil,col);

        printf("\n\n/////sumConDiagPrincipaSuperior/////\n\n");
        sumConDiagPrincipaSuperior(mat,fil,col);

        printf("\n\n/////sumSinDiagPrincipaSuperior/////\n\n");
        sumSinDiagPrincipaSuperior(mat,fil,col);

        printf("\n\n/////sumConDiagSecundSuperior/////\n\n");
        sumConDiagSecundSuperior(mat,fil,col);

        printf("\n\n/////sumSinDiagSecundSuperior/////\n\n");
        sumSinDiagSecundSuperior(mat,fil,col);

        printf("\n\n/////sumConDiagSecundInferior/////\n\n");
        sumConDiagSecundInferior(mat,fil,col);

        printf("\n\n/////sumSinDiagSecundInferior/////\n\n");
        sumSinDiagSecundInferior(mat,fil,col);


    }
    else
    {
        printf("\n\nError la matriz no es cuadrada\n\n");
    }

}


void sumConDiagPrincipalInferior(int mat[][col],int f,int c)
{
    int i,j,sum=0;

    for(i=0; i<f; ++i)
    {
        for(j=0; j<=i; ++j)
        {
            sum+=mat[i][j];
            printf("%d \t",mat[i][j]);
        }
        printf("\n");
    }
    printf("\n-La suma es: %d\n",sum);
}

void sumSinDiagPrincipalInferior(int mat[][col],int f,int c)
{
    int i,j,sum=0;

    for(i=0; i<f; ++i)
    {
        for(j=0; j<i; ++j)
        {
            sum+=mat[i][j];
            printf("%d \t",mat[i][j]);
        }
        printf("\n");
    }
    printf("\n-La suma es: %d\n",sum);
}


void sumConDiagPrincipaSuperior(int mat[][col],int f,int c)
{
    int i,j,sum=0;

    for(i=0; i<f; ++i)
    {
        printf("%*s",i*8,"");

        for(j=0; j>=i; ++j) //        for(j=i; j<c; ++j)

        {
            sum+=mat[i][j];
            printf("%d \t",mat[i][j]);
        }
        printf("\n");
    }
    printf("\n-La suma es: %d\n",sum);
}

void sumSinDiagPrincipaSuperior(int mat[][col],int f,int c)
{
    int i,j,sum=0;

    for(i=0; i<f; ++i)
    {
        printf("%*s",i*8,"");

        for(j=i+1; j<c; ++j)
        {
            sum+=mat[i][j];
            printf("%d \t",mat[i][j]);
        }
        printf("\n");
    }
    printf("\n-La suma es: %d\n",sum);
}

void sumConDiagSecundSuperior(int mat[][col],int f,int c)
{
    int i,j,sum=0;

    for(i=0; i<f; ++i)
    {
        for(j=0; j<c-i; ++j) // segunda: va hasta 5 - 4 - 3 - 2 - 1
        {
            sum+=mat[i][j];
            printf("%d \t",mat[i][j]);
        }
        printf("\n");
    }
    printf("\n-La suma es: %d\n",sum);
}

void sumSinDiagSecundSuperior(int mat[][col],int f,int c)
{
    int i,j,sum=0;

    for(i=0; i<f; ++i)
    {
        //printf("%*s",i*8,"");

        for(j=0; j<c-i-1; ++j)
        {
            sum+=mat[i][j];
            printf("%d \t",mat[i][j]);
        }
        printf("\n");
    }
    printf("\n-La suma es: %d\n",sum);
}

void sumConDiagSecundInferior(int mat[][col],int f,int c)
{
    int i,j,sum=0;

    for(i=0; i<f; ++i)
    {
        tab(f-i-1);
        for(j=c-i-1; j<c; ++j) //como columna va a avanza, hasta el 5, no se reduce en la seg cond, sino que el mov es en el primero
        {
            sum+=mat[i][j];
            printf("%d \t",mat[i][j]);
        }
        printf("\n");
    }
    printf("\n-La suma es: %d\n",sum);
}

void sumSinDiagSecundInferior(int mat[][col],int f,int c)
{
    int i,j,sum=0;

    for(i=0; i<f; ++i)
    {
        tab(f-i);
        for(j=c-i; j<c; ++j) //como columna va a avanza, hasta el 5, no se reduce en la seg cond, sino que el mov es en el primero
        {
            sum+=mat[i][j];
            printf("%d \t",mat[i][j]);
        }
        printf("\n");
    }
    printf("\n-La suma es: %d\n",sum);
}
/*
void ejercicio30()
{

    int mat[][col]= {{1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15},
        {16,17,18,19,20},
        {21,22,23,24,25}
    };


    if(esMatrizCuadrada(fil,col))
    {
        sumaDiagPrincipal(mat,fil,col);
        sumaDiagSecundaria(mat,fil,col);
    }
    else
    {
        printf("\n\nError la matriz no es cuadrada\n\n");
    }

}

void sumaDiagPrincipal(int mat[][col],int f,int c)
{
    int i,j,suma = 0;

    for(i = 0; i<f; ++i)
    {
        printf("%*s",i*8,"");
        for(j=i; j<=i; ++j)
        {
            suma+=mat[i][j];
            printf("%d \t", mat[i][j]);
        }
        printf("\n");
    }

    printf("\n\n-La suma de la diagonal principal es: %d\n\n",suma);
}

void sumaDiagSecundaria(int mat[][col],int f,int c)
{
    int i,j,suma = 0;

    for(i = 0; i<f; ++i)
    {
        tab(f-i);
        for(j=c-i-1; j<c-i; ++j)
        {
            suma+=mat[i][j];
            printf("%d \t", mat[i][j]);

        }
        printf("\n");
    }
    printf("\n\n-La suma de la diagonal secundaria es: %d\n\n",suma);
}

void ejercicio31()
{

    int mat[][col]=
       {{1,1,0,0,0},
        {0,1,0,0,0},
        {0,0,1,0,0},
        {0,0,0,1,0},
        {0,0,0,0,1}
    };


    if(esMatrizDiagonal(mat,fil,col))
    {
        printf("\n\nEs matriz diagonal\n\n");
        mostrarMatriz(mat,fil,col);
    }
    else
    {
        printf("\n\nError la matriz no es diagonal\n\n");
    }

}

int esMatrizDiagonal(int mat[][col],int f,int c)
{
    int i,j;

    for(i = 0; i<f; i++)
    {
        for(j=0; j<c; j++)
        {
            if( (mat[i][j] != 0 && i!=j) || (mat[i][j] == 0 && i==j) ) //Si algún elemento de afuera es != 0 y f!=, chau
            {
                return NO;
            }
        }
    }
    return OK;
}

void ejercicio32()
{

    int mat[][col]=
       {{1,0,0,0,0},
        {0,1,0,0,0},
        {0,0,1,0,0},
        {0,0,0,1,0},
        {0,0,0,0,1}
    };

    if(esMatrizIdentidad(mat,fil,col))
    {
        printf("\n\nEs matriz identidad\n\n");
        mostrarMatriz(mat,fil,col);
    }
    else
    {
        printf("\n\nError la matriz no es identidad\n\n");
    }

}

int esMatrizIdentidad(int mat[][col],int f,int c)
{
    int i,j;//cont = 0;

    for(i = 0; i<f; i++)
    {
        for(j=0; j<c; j++)
        {
            if( (mat[i][j] != 0 && i!=j) || (mat[i][j] != 1 && i == j))
            {
                return NO;
            }
        }
    }

    return OK;
}


void ejercicio33()
{

    int mat[][col]= {{1,0,0,0,0},
        {0,1,2,2,0},
        {0,0,1,0,0},
        {0,0,0,1,0},
        {0,0,0,0,1}
    };

    if(esMatrizSimetrica(mat,fil,col))
    {
        printf("\n\nEs matriz simetrica\n\n");
        mostrarMatriz(mat,fil,col);
    }
    else
    {
        printf("\n\nLa matriz no es simetrica\n\n");
    }

}


int esMatrizSimetrica(int mat[][col],int f,int c)
{

    int i,j;

    for(i = 0; i<f; i++)
    {
        for(j=0; j<c; j++)
        {
            if(mat[i][j] != mat[j][i]) //Si algún elemento de afuera es != 0 y f!=c , chau
            {
                return NO;
            }
        }
    }
    return OK;
}

void mostrarMatrizTransp(int mat[][col2],int f,int c)
{
    int i,j;

    for(i=0; i<f; ++i)
    {
        for(j=0; j<c; ++j)
        {
            printf("%d \t", mat[i][j]);
        }
        printf("\n");
    }
}


void ejercicio34()
{

    int mat[][col2]=
    {
        {7,0,-3},
        {5,0,3},
        {-3,1,2},
    };

    printf("\n\n");
    mostrarMatrizTransp(mat,fil2,col2);
    matrizTranspuestaNxN(mat,fil2,col2);
    printf("\n\n");
    mostrarMatrizTransp(mat,fil2,col2);

}



//    1   2   3           1   2   3
// A= 2   5   0   ->  At= 2   5   0
//    3   0   5           3   0   5





void matrizTranspuestaNxN(int mat[][col2],int f,int c)
{
    int i,j,aux;

    for(i = 0; i < f; ++i)
    {
        for(j = 0+i ; j < c; ++j)
        {
            if(mat[i][j] != mat[j][i])
            {
                aux = mat[j][i];
                mat[j][i] = mat[i][j];
                mat[i][j] = aux;
            }
        }
    }
}

void ejercicio35()
{
    int mat[fil3][col3]=
    {
        {7,0,-3},
        {5,0,3},
        {-3,1,2},
        {1,0,1}

    };

    int mat2[col3][fil3];

    printf("\n\n");
    mostrarMatriz2(mat,fil3,col3); //mat 4 3
    matrizTranspuestaNxM(mat,mat2,fil3,col3);
    printf("\n\n");
    mostrarMatrizTransp2(mat2,col3,fil3); // mat 3 4

}

void mostrarMatriz2(int mat[][col3],int f,int c)
{
    int i,j;

    for(i=0; i<f; ++i)
    {
        for(j=0; j<c; ++j)
        {
            printf("%d \t", mat[i][j]);
        }
        printf("\n");
    }
}

void mostrarMatrizTransp2(int mat[][fil3],int f,int c)
{
    int i,j;

    for(i=0; i<f; ++i)
    {
        for(j=0; j<c; ++j)
        {
            printf("%d \t", mat[i][j]);
        }
        printf("\n");
    }
}

void matrizTranspuestaNxM(int mat[][col3],int mat2[][fil3],int f,int c)
{
    int i,j;

    for(i = 0; i < f; ++i)
    {
        for(j = 0; j < c; ++j)
        {
            mat2[j][i] = mat[i][j];
        }
    }
}

void ejercicio36()
{
    int mat1[fil3][col3]=
    {
        {7,0,-3},
        {5,0,3},
        {-3,1,2},
        {1,0,1}

    };

    int mat2[col3][fil3] =
    {
        {7,0,-3,5},
        {5,0,3,8},
        {-3,1,2,7},
    };

    int mat3[fil3][fil3];

    productoMatrices(mat1,mat2,mat3,fil3,col3);
    printf("\nLa matriz de resultado es:\n");
    mostrarMatrizProd(mat3,fil3,fil3);



}

void mostrarMatrizProd(const int mat[][fil3],int f,int c)
{
    int i,j;

    for(i=0; i<f; ++i)
    {
        for(j=0; j<c; ++j)
        {
            printf("%d \t", mat[i][j]);
        }
        printf("\n");
    }
}


void productoMatrices(int mat1[][col3],int mat2[][fil3],int mat3[][fil3],int f,int c)
{

    int i, j, k, suma;

    for(i = 0; i < f; ++i)
    {

        for(j=0; j < f; ++j) //este es igual porque es fxc -> y las dos tienen el mismo tam(4*3 vs 3*4 -> se multp 4 x 4 (fxc) K termina con 4x4
        {

            suma = 0; // se reinicia el sumador

            for(k = 0 ; k < c; ++k)
            {
                suma += mat1[i][k] * mat2[k][j];
            }
            mat3[i][j] = suma;
        }
    }
}

void ejercicio37()
{
    int partidos[fil2][col2] =
    {
        {0,1,3},
        {1,0,1},
        {0,1,0}
    };

    if(puntosEquipos(partidos,fil2,col2) && esMatrizCuadrada(fil2,col2)){
        printf("\nLa tabla esta generada CORRECTAMENTE\n");
        mostrarMatrizPart(partidos,fil2,col2);

    }
    else{
        printf("\nLa tabla esta generada INCORRECTAMENTE\n");
        mostrarMatrizPart(partidos,fil2,col2);
    }

}

void mostrarMatrizPart(const int partidos[][col2],int f,int c)
{
    int i,j;

    for(i=0; i<f; ++i)
    {
        for(j=0; j<c; ++j)
        {
            printf("%d \t", partidos[i][j]);
        }
        printf("\n");
    }
}


unsigned int puntosEquipos(const int partidos[][col2],int f, int c)
{
    int i,j;

    for(i = 0; i< f; ++i)
    {
        for(j = 0; j < c; ++j)
        {
            if(!diagonalPrincipalCeros(partidos,f,c) && !sumaCorrectaPuntos(partidos,f,c)) // SE ASUME QUE PUEDEN METER OTROS VALORES APARTE DE 3, 1 O 0
                return NO;
        }
    }

    return OK;
}

int diagonalPrincipalCeros(const int partidos[][col2],int f, int c)
{

    int i,j;

    for(i = 0; i< f; ++i)
    {
        for(j = i; j <= i; ++j)
        {
            if(partidos[i][j] != 0)
            {
                return NO;
            }
        }
    }

    return OK;
}

int sumaCorrectaPuntos(const int partidos[][col2],int f, int c)
{

    int i,j,suma1,suma2;

    printf("\nFilas\n");
    // para sumar las filas
    for(i = 0; i< f; ++i)
    {
        suma1 = 0; //reinicio el sumador
        for(j = 0; j < c; ++j)
        {
            suma1+=partidos[i][j];

        if(suma1 < 0 || suma1 > 4)
            return NO;

        }
    }
    // para sumar las columnas


    printf("\nColumnas\n");

    for(j = 0; j< c; ++j)
    {
        suma2 = 0; //reinicio el sumador
        for(i = 0; i < f; ++i)
        {
            suma2+=partidos[i][j];

            if(suma2 == 5 || suma2 > 6)
                return NO;
        }
    }

    return OK;
}
*/
