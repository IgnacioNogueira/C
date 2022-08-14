#include "Funciones.h"

void crearArchivoDePrueba(const char* nomArchivo)
{
    FILE* arch = fopen(nomArchivo, "wt");

    srand(time(NULL));

    int cantPilas = rand() % (MAX_PILA + 1) + MIN_PILA;

    fprintf(arch, "%d\n", cantPilas);

    int contador, i, j;

    for(contador = 0; contador < cantPilas; contador++)
    {
        i = rand() % (cantPilas + 1);
        j = rand() % MAX_ELEMENTO;
        if(rand() % 2 == 0)
            i *= -1;

        fprintf(arch, "(%d,%d)\n", i, j);
    }

    fclose(arch);
}

booleano procesamientoPilas(FILE* archEntrada, int cantPilas)
{
    Pila vPilas[cantPilas];

    int i, j, elemPila;

    char nomArchPilaActual[15];
    FILE* archActual;

    for(i = 1; i <= cantPilas; i++)
        crearPila(&vPilas[i-1]);

    while(fscanf(archEntrada, "(%d,%d)\n", &i, &j) != EOF)
    {
        if(i > 0 && j != 0)
            ponerEnPila(&vPilas[i-1], &j, sizeof(int));
        else if(i > 0 && j == 0)
            vaciarPila(&vPilas[i-1]);
        else if(i < 0)
            sacarDePila(&vPilas[abs(i)-1], &elemPila, sizeof(int));
        else if(i == 0)
            return FALSO;
    }

    fclose(archEntrada);

    for(i = 1; i <= cantPilas; i++)
    {
        if(!pilaVacia(&vPilas[i-1]))
        {
            sprintf(nomArchPilaActual, "pila%d.txt", i);
            archActual = fopen(nomArchPilaActual, "wt");

            if(!archActual)
                return FALSO;

            while(!pilaVacia(&vPilas[i-1]))
            {
                sacarDePila(&vPilas[i-1], &elemPila, sizeof(int));
                fprintf(archActual, "%d\n", elemPila);
            }

            fclose(archActual);
        }
    }

    return VERDADERO;
}
