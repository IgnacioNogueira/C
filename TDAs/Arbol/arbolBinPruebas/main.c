#include "main.h"
int main()
{
    tArbol arbol;
    crearArbol(&arbol);
    crearCargarArchivoBin(NOMBRE_ARCH_BIN);

    printf("ARCH DESORDENADO: \n\n");
    mostrarArchivoBin(NOMBRE_ARCH_BIN);

    printf("\n\n *********************************** \n");
    printf("ARCH ORDENADO: \n\n");

    probarArbol_1(&arbol, NOMBRE_ARCH_BIN, "rb");

    return 0;
}
