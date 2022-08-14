#include <stdio.h>
#include <stdlib.h>

#include "Funciones.h"

#define ERR_PROCESO 1
#define ERR_CANTPILAS 2

int main()
{
    crearArchivoDePrueba("datos.txt");

    FILE* archEntrada = fopen("datos.txt", "rt");

    int cantPilas;

    fscanf(archEntrada, "%d\n", &cantPilas);

    if(cantPilas < 1 || cantPilas > 500)
        return ERR_CANTPILAS;

    booleano ret = procesamientoPilas(archEntrada, cantPilas);

    if(ret != VERDADERO)
        return ERR_PROCESO;

    remove("datos.txt");

    return 0;
}
