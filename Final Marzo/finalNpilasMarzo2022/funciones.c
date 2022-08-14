#include "funciones.h"

int crearSetDeDatos(const char *nombreArchivo)
{
    FILE *fp = fopen(nombreArchivo,"wt");

    if(!fp)
    {
        printf("\nNO SE PUDO CREAR EL SET DE DATOS, ERROR\n");
        return ERROR_ARCH;
    }

    srand(time(NULL));
    int cantPilas = rand() % (MAX_PILA +1) + MIN_PILA;
    fprintf(fp,"%d\n",cantPilas);

    int i,j,iter;

    for(iter = 0; iter < cantPilas; ++iter)
    {
        i = rand() %(cantPilas +1);
        j = rand() % MAX_ELEM;

        if(rand() %2 == 0)
            i *= -1;

        fprintf(fp,"(%d,%d)\n",i,j);
    }

    fclose(fp);
    return TODO_BIEN;
}

int verificarPila(FILE *fpDatos)
{
    int cantPilas;
    fscanf(fpDatos,"%d\n",&cantPilas);

    if(cantPilas < 1 || cantPilas > 500)
        return ERROR_PILA;

    return cantPilas;
}

void crearCantidadPilas(tPila *vPilas,int cantPilas)
{
    int iter;

    for(iter = 1; iter <= cantPilas; ++iter) //empieza con una pila -> hace referencia a la cantidad que se sacan
        crearPila(&vPilas[iter-1]);
}

int interaccionPilas(FILE *fpd, tPila *vPilas)
{
    int i,j,k;

    while(fscanf(fpd,"(%d,%d)\n",&i,&j) != EOF)
    {
        if(i == 0)
        {
            return VAL_ANORMAL;
        }
        else
        {
            if(i > 0)
            {
                if(j == 0)
                {
                    vaciarPila(&vPilas[i-1]);
                }
                else
                {
                    insertarEnPila(&vPilas[i-1],&j,sizeof(int));
                    verTopePila(&vPilas[i-1],&k,sizeof(int));
                    printf("%d\n",k);
                }
            }
            else
            {
                verTopePila(&vPilas[i-1],&k,sizeof(int));
                printf("%d\n",k);
                sacarDePila(&vPilas[abs(i)-1],&k,sizeof(int));
            }
        }
    }

    return TODO_BIEN;
}

int sacarYGrabarArchivoNuevo(tPila *vPilas,int posElem)
{
    int elemPila;
    char nombreArchivoNuevoPil[15];
    FILE *archNuevoPil;

    while(sacarDePila(&vPilas[posElem-1],&elemPila,sizeof(int)))
    {
        sprintf(nombreArchivoNuevoPil,"pila%d.txt",posElem);
        archNuevoPil = fopen(nombreArchivoNuevoPil,"wt");

        if(!archNuevoPil)
            return ERROR_ARCH;

        fprintf(archNuevoPil,"%d\n",elemPila);
    }

    fclose(archNuevoPil);
    return TODO_BIEN;
}


int procesarArchivoPilas(const char *nombreArchivoDatos)
{

    int i, j,cantPilas, elemPila;

    FILE *fpd = fopen(nombreArchivoDatos,"rt");

    if(!fpd)
    {
        printf("\nNO SE ENCONTRO EL ARCHIVO DE DATOS, ERROR\n");
        return ERROR_ARCH;
    }

    if( (cantPilas = verificarPila(fpd)) == ERROR_PILA)
    {
        printf("\nCANTIDAD DE PILAS INCORRECTO, ERROR\n");
        fclose(fpd);
        return ERROR_PILA;
    }

    tPila vPilas[cantPilas];
    char nomArchPilaActual[15];
    FILE* archActual;

    for(i = 1; i <= cantPilas; i++)
        crearPila(&vPilas[i-1]);

    while(fscanf(fpd, "(%d,%d)\n", &i, &j) != EOF)
    {
        if(i > 0 && j != 0)
            insertarEnPila(&vPilas[i-1], &j, sizeof(int));
        else if(i > 0 && j == 0)
            vaciarPila(&vPilas[i-1]);
        else if(i < 0)
            sacarDePila(&vPilas[abs(i)-1], &elemPila, sizeof(int));
        else if(i == 0)
            return 0;
    }

    fclose(fpd);

    for(i = 1; i <= cantPilas; i++)
    {
        sprintf(nomArchPilaActual, "pila%d.txt", i);
        archActual = fopen(nomArchPilaActual, "wt");

        if(!archActual)
            return 0;

        while(sacarDePila(&vPilas[i-1], &elemPila, sizeof(int)))
        {
            fprintf(archActual, "%d\n", elemPila);
        }

        fclose(archActual);
    }

    return TODO_BIEN;
}





/*
int procesarArchivoPilas(const char *nombreArchivoDatos)
{
int cantPilas,i;
FILE *fpd = fopen(nombreArchivoDatos,"rt");

if(!fpd)
{
    printf("\nNO SE ENCONTRO EL ARCHIVO DE DATOS, ERROR\n");
    return ERROR_ARCH;
}

if( (cantPilas = verificarPila(fpd)) == ERROR_PILA)
{
    printf("\nCANTIDAD DE PILAS INCORRECTO, ERROR\n");
    fclose(fpd);
    return ERROR_PILA;
}

tPila vPilas[cantPilas]; //se van a almacenar el tamaño de la cantidad de pilas que se obtuvo del txt

crearCantidadPilas(vPilas,cantPilas);

if(interaccionPilas(fpd,vPilas) != TODO_BIEN)
{
    printf("\nVALOR ANORMAL DE PILA, ERROR\n");
    fclose(fpd);
    return VAL_ANORMAL;
}

for(i = 1; i <= cantPilas; ++i)
{
    if(sacarYGrabarArchivoNuevo(vPilas,i) != TODO_BIEN)
    {
        printf("\nNO SE PUDO CREAR ARCHIVO TXT PARA GRABAR PILAS");
        return ERROR_ARCH;
    }
}

fclose(fpd);
return TODO_BIEN;
}


*/
