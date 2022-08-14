#include "main.h"
#include "tdaArbol.h"
#include "tdaListaSimple.h"
#include "funciones.h"
#include "Utils.h"

int main()
{
    ///ITEM A:

    tArbolBinBusq arb;
    int i;
    int vec[] = {20,15,23,13,24,18,22};
    crearArbolBinBusq(&arb);

    for(i = 0; i < sizeof(vec)/sizeof(int);++i)
    {
        insertarEnArbolBinBusqRec(&arb,&vec[i],sizeof(int),cmp_ent);
    }

    if(!recorrerYMostrarArbolHastaNivel(&arb,ARBOL_NIVEL,imprimir,NULL))
        printf("ERROR: Nivel de arbol no valido.\n");
}


/*
int main()
{
   ///ITEM B:
    int r;

    if( (r = registrosPedidos(NOMBRE_ARCHIVO_LOTE_PRUEBA,NOMBRE_ARCHIVO_FINAL)) != TODO_BIEN)
        return r;

    return 0;
}
*/
