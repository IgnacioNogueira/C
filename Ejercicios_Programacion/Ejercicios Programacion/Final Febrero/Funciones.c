#include "Funciones.h"

int cmpFilaYColumna(const void* d1, const void* d2);
void grabarMatriz(const void* elem, size_t tamElem, FILE* arch);

/*
Objetivo propuesto: desarrollar una aplicación, main y la/s función/es necesarias, para sumar los
elementos de 2 matrices dispersas (Archivo 1 y Archivo 2). Luego mostrar la matriz resultado,
mostrando tanto los elementos nulos como los no nulos. Guardar el resultado en otro archivo (Archivo 3).
*/

// Esta función verifica si es posible alcanzar el objetivo propuesto. Esta función
// debe invocarse antes de cargar las matrices en memoria.
booleano verificar_mat(const char* nomArch1, const char* nomArch2, const char* nomArch3)
{
    FILE* arch1 = fopen(nomArch1, "rt");
    FILE* arch2 = fopen(nomArch2, "rt");
    FILE* arch3 = fopen(nomArch3, "wt");

    if(!arch1 || !arch2 || !arch3)
    {
        fclose(arch1);
        fclose(arch2);
        fclose(arch3);
        return FALSO;
    }

    int cantF1, cantF2, cantC1, cantC2;

    fscanf(arch1, "[%d][%d]\n", &cantF1, &cantC1);
    fscanf(arch2, "[%d][%d]\n", &cantF2, &cantC2);

    if(cantF1 != cantF2 || cantC1 != cantC2 || cantF1 < 1 || cantF1 > 1000 || cantC1 < 1 || cantC1 > 1000)
    {
        fclose(arch1);
        fclose(arch2);
        fclose(arch3);
        return FALSO;
    }

    fclose(arch1);
    fclose(arch2);
    fclose(arch3);

    return VERDADERO;
}

// Función para cargar una matriz en memoria.
// Carga en memoria una matriz dispersa de forma tal de poder realizar la suma de matrices. Usted
// debe seleccionar la estructura de datos más conveniente. Debe optimizar el uso de memoria.
booleano cargar_mat(Matriz* mat, const char* nomArch)
{
    FILE* arch = fopen(nomArch, "rt");

    if(!arch)
        return FALSO;

    ValorNoNuloMat val;

    fscanf(arch, "[%d][%d]\n", &(mat->cantFilas), &(mat->cantColumnas));

    crearLista(&(mat->listaValNoNulos));

    while(fscanf(arch, "[%d][%d] %d\n", &val.fila, &val.columna, &val.valor) != EOF)
        insertarEnListaOrd(&(mat->listaValNoNulos), &val, sizeof(ValorNoNuloMat), cmpFilaYColumna);

    fclose(arch);

    return VERDADERO;
}

int cmpFilaYColumna(const void* d1, const void* d2)
{
    ValorNoNuloMat* val1 = (ValorNoNuloMat*)d1;
    ValorNoNuloMat* val2 = (ValorNoNuloMat*)d2;

    int comp = val1->fila - val2->fila;

    if(comp == 0)
        return val1->columna - val2->columna;
    else
        return comp;
}

// Función que realiza la suma de dos matrices. Optimizar el uso de memoria.
booleano sumar_mat(Matriz* mat1, Matriz* mat2, Matriz* mat3)
{
    Iterador it1;
    Iterador it2;

    ValorNoNuloMat val1, val2;

    if(!crearIterador(&it1, &(mat1->listaValNoNulos)) || !crearIterador(&it2, &(mat2->listaValNoNulos)))
        return FALSO;

    mat3->cantFilas = mat1->cantFilas;
    mat3->cantColumnas = mat1->cantColumnas;
    crearLista(&(mat3->listaValNoNulos));

    primeroDeLista(&it1, &val1, sizeof(ValorNoNuloMat));
    primeroDeLista(&it2, &val2, sizeof(ValorNoNuloMat));

    while(!finDeLista(&it1) && !finDeLista(&it2))
    {
        int comp = cmpFilaYColumna(&val1, &val2);
        if(comp == 0)
        {
            val1.valor += val2.valor;
            insertarEnListaOrd(&(mat3->listaValNoNulos), &val1, sizeof(ValorNoNuloMat), cmpFilaYColumna);
            siguienteDeLista(&it1, &val1, sizeof(ValorNoNuloMat));
            siguienteDeLista(&it2, &val2, sizeof(ValorNoNuloMat));
        }
        else if(comp < 0)
        {
            insertarEnListaOrd(&(mat3->listaValNoNulos), &val1, sizeof(ValorNoNuloMat), cmpFilaYColumna);
            siguienteDeLista(&it1, &val1, sizeof(ValorNoNuloMat));
        }
        else if(comp > 0)
        {
            insertarEnListaOrd(&(mat3->listaValNoNulos), &val2, sizeof(ValorNoNuloMat), cmpFilaYColumna);
            siguienteDeLista(&it2, &val2, sizeof(ValorNoNuloMat));
        }
    }

    while(!finDeLista(&it1))
    {
        insertarEnListaOrd(&(mat3->listaValNoNulos), &val1, sizeof(ValorNoNuloMat), cmpFilaYColumna);
        siguienteDeLista(&it1, &val1, sizeof(ValorNoNuloMat));
    }

    while(!finDeLista(&it2))
    {
        insertarEnListaOrd(&(mat3->listaValNoNulos), &val2, sizeof(ValorNoNuloMat), cmpFilaYColumna);
        siguienteDeLista(&it2, &val2, sizeof(ValorNoNuloMat));
    }

    return VERDADERO;
}

// recibe una matriz dispersa y la muestra completa (con todos los valores,
// incluyendo los valores nulos).
booleano imprimir_mat(Matriz* mat)
{
    Iterador itMatriz;
    ValorNoNuloMat val;
    int i, j;

    if(crearIterador(&itMatriz, &(mat->listaValNoNulos)) != VERDADERO)
        return FALSO;

    primeroDeLista(&itMatriz, &val, sizeof(ValorNoNuloMat));

    for(i = 0; i < mat->cantFilas; i++)
    {
        for(j = 0; j < mat->cantColumnas; j++)
        {
            if(i == val.fila && j == val.columna)
            {
                printf("%d\t", val.valor);
                if(haySiguienteDeLista(&itMatriz))
                    siguienteDeLista(&itMatriz, &val, sizeof(ValorNoNuloMat));
            }
            else
                printf("0\t");
        }
        printf("\n");
    }

    return VERDADERO;
}

// recibe una matriz dispersa y la guarda en un archivo de texto, respetando el
// formato solicitado. Luego de ejecutada esta función ya no estará disponible la matriz.
booleano guardar_mat(Matriz* mat, const char* nomArch)
{
    FILE* arch = fopen(nomArch, "wt");

    if(!arch)
        return FALSO;

    fprintf(arch, "[%d][%d]\n", mat->cantFilas, mat->cantColumnas);

    vaciarListaYGrabarEnArch(&(mat->listaValNoNulos), grabarMatriz, arch);

    fclose(arch);

    return VERDADERO;
}

void grabarMatriz(const void* elem, size_t tamElem, FILE* arch)
{
    ValorNoNuloMat* val = (ValorNoNuloMat*)elem;

    fprintf(arch, "[%d][%d] %d\n", val->fila, val->columna, val->valor);
}
