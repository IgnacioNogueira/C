#include <stdio.h>
#include <stdlib.h>

#include "ArbolImplDinamica.h"

int cmpInt(const void* d1, const void* d2);
void mostrarInt(const void* elem, size_t tamElem, void* param);

int main()
{
    Arbol arbolInt;

    crearArbol(&arbolInt);

    int n = 15;
    insertarEnArbol(&arbolInt, &n, sizeof(int), cmpInt);

    n = 6;
    insertarEnArbol(&arbolInt, &n, sizeof(int), cmpInt);

    n = 20;
    insertarEnArbol(&arbolInt, &n, sizeof(int), cmpInt);

    n = 3;
    insertarEnArbol(&arbolInt, &n, sizeof(int), cmpInt);

    n = 9;
    insertarEnArbol(&arbolInt, &n, sizeof(int), cmpInt);

    n = 18;
    insertarEnArbol(&arbolInt, &n, sizeof(int), cmpInt);

    n = 24;
    insertarEnArbol(&arbolInt, &n, sizeof(int), cmpInt);

    n = 1;
    insertarEnArbol(&arbolInt, &n, sizeof(int), cmpInt);

    n = 4;
    insertarEnArbol(&arbolInt, &n, sizeof(int), cmpInt);

    n = 7;
    insertarEnArbol(&arbolInt, &n, sizeof(int), cmpInt);

    n = 12;
    insertarEnArbol(&arbolInt, &n, sizeof(int), cmpInt);

    n = 17;
    insertarEnArbol(&arbolInt, &n, sizeof(int), cmpInt);

    if(!mostrarNodosDeNivel(&arbolInt, 3, mostrarInt, NULL))
        printf("ERROR: Nivel de arbol no valido.\n");

    return 0;
}

int cmpInt(const void* d1, const void* d2)
{
    return *((int*)d1) - *((int*)d2);
}

void mostrarInt(const void* elem, size_t tamElem, void* param)
{
    int num = *((int*)elem);
    printf("%d \t", num);
}
