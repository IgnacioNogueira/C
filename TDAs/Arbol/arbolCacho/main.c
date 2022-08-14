#include "arbol.h"
#include "Utils.h"
#include "funciones.h"
/*
int main()
{
    tArbolBinBusq arb,arb2;
    int vec[] = {20,15,23,13,24,18,22,29};
    int vec2[] = {13,15,18,20,22,23,24,29};


//    crearArbolBinBusq(&arb);
//    for(i = 0;i < sizeof(vec)/sizeof(int);i++)
//    {
//        printf("%d\n",vec[i]);
//        //insertarArbolBinBusq(&arb,&vec[i],sizeof(int),cmp_ent);
//    }
//
//    printf("\n\nPREORDEN\n\n");
//    recorrerPreOrdenArbolBinBusq(&arb,NULL,imprimir);
//    printf("\n\n");
//
//
//    printf("\n\nPOSTORDEN\n\n");
//    recorrerPostOrdenArbolBinBusq(&arb,NULL,imprimir);
//    printf("\n\n");
//
//    printf("\n\nORDEN INVERSO\n\n");
//    recorrerOrdenInversoArbolBinBusq(&arb,NULL,imprimir);
//    printf("\n\n");

    crearArbolBinBusq(&arb2);
    cargarDesdeDatOrdenArbolBinRec(&arb2,vec2,sizeof(vec2)/sizeof(int),leerDesdeVectorEnteros,NULL);
    printf("\n\nEN ORDEN\n\n"); //no funca con el insertar hay que cargar los datos ordenados
    recorrerEnOrdenArbolBinBusq(&arb2,NULL,imprimir);
    printf("\n\n");

    return 0;
}
*/


int main()
{
    tArbolBinBusq arb;
    int i;
    int vec[] = {20,15,23,13,24,18,22};
    //int vec2[] = {13,15,18,20,22,23,24,29};

    crearArbolBinBusq(&arb);

    for(i = 0; i < sizeof(vec)/sizeof(int); i++)
    {
        printf("%d\n",vec[i]);
        insertarEnArbBinBusqRec(&arb,&vec[i],sizeof(int),cmp_ent);
    }

    recorrerPreOrdenArbolBinBusq(&arb,vec,imprimir);

   // printf("\nLa cantidad de nodos pares es de: %d\n",contarNodosCondicion(&arb,accionContarPares));
    //printf("\nLa cantidad de nodos pares es de: %d\n",cantNodosArbolBinPares(&arb,accionContarPares));
    //printf("\nLa cantidad de nodos pares es de: %d\n",cantNodosArbolBinHastaNivel(&arb,1,accionContarPares));

    return 0;
}

/*
int main()
{
    /// Ejercicio 1
    tArbolBinBusq arb;

    crearArbolBinBusq(&arb);
    leerYMostrarArchivo(NOMBRE_ARCHIVO_FUSION);
    cargarIndiceArbolArch(NOMBRE_ARCHIVO_FUSION,&arb,cmp_ent);
    recorrerPreOrdenArbolBinBusq(&arb,NULL,imprimir);
    printf("\n\n");
    guardarArbolGeneradoArchTemp(&arb,guardarRegIndiceArchivo);
    vaciarArbolBinBusq(&arb);
    cargarArbolArchivoINDTemp(&arb,cmp_ind);
    recorrerPreOrdenArbolBinBusq(&arb,NULL,imprimir);
    printf("\n\n");

    if(esArbolBalanceadoBin(&arb,alturaArbolBin(&arb)))
    {
        printf("\nEs un arbol balanceado");
    }

}
*/
