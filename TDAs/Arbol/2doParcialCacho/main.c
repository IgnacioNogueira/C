#include "main.h"
#include "funciones.h"
#include "tdaArbol.h"
#include "tdaListaDoble.h"
#include "tdaColaImpListaCircular.h"

int ejercicio4(const char *archivoEstadosFinan, tCola *col,
               const char *archivoInforme,tArbolBinBusq *p,
               int (*cmp)(const void *,const void*));


int main()
{
    /// Ejercicio 1
    tArbolBinBusq arb;
    crearArbolBinBusq(&arb);

    printf("\n///////////////Ejercicio 1///////////////\n");

    leerYMostrarArchivo(NOMBRE_ARCHIVO_MAESTRO_PRODUCTOS);
    cargarIndiceArbolArch(NOMBRE_ARCHIVO_MAESTRO_PRODUCTOS,&arb,cmp_ent);
    recorrerPreOrdenArbolBinBusq(&arb,NULL,imprimir);
    printf("\n\n");
    guardarArbolGeneradoArchTemp(&arb,guardarRegIndiceArchivo);
    vaciarArbolBinBusq(&arb);
    cargarArbolArchivoINDTemp(&arb,cmp_ind);
    recorrerPreOrdenArbolBinBusq(&arb,NULL,imprimir);
    printf("\n\n");

    recorrerArbolInOrderBasico(&arb,mostrarIndice);

    if(esArbolBalanceadoBin(&arb,alturaArbolBin(&arb)))
    {
        printf("\nEs un arbol balanceado");
    }

    ///Ejercicio 2

    printf("\n///////////////Ejercicio 2///////////////\n");

    tListaD listD;
    tNovedad nov;
    FILE * fpLista;
    char linea[100];
    int cantElem;

    crearListaDoble(&listD);
    fpLista = fopen(NOMBRE_ARCHIVO_NOVEDADES,"rt");

    if(!fpLista)
    {
        printf("\nNo se pudo abrir el archivo %s",NOMBRE_ARCHIVO_NOVEDADES);
        return -4;
    }

    while(fgets(linea,sizeof(linea),fpLista))
    {
        trozarCampoLongitudVariable(linea,&nov);
        insertarEnOrdenAcum(&listD,&nov,sizeof(tNovedad),cmp_ent,acumularCantidadNov);
    }

    printf("\n\nLista doble:\n\n");
    cantElem = mostrarDeIzqADer(&listD,mostrarNovedad);
    printf("\n\n-Cantidad de elementos de la lista: %d\n\n",cantElem);


    ///Ejercicio 3

    printf("\n///////////////Ejercicio 3///////////////\n");
    tCola col;
    crearCola(&col);

    while(!listaVaciaDoble(&listD))
    {
        sacarPrimeroListaDoble(&listD,&nov,sizeof(tNovedad));
        ponerEnColaCir(&col,&nov,sizeof(tNovedad));
    }

    if(listaVaciaDoble(&listD))
    {
        printf("\n****La lista esta vacia****\n");
    }

//    ///Ejercicio 4
//
//    int cantAct;
//    printf("\n///////////////Ejercicio 4///////////////\n");
//    cantAct = ejercicio4(NOMBRE_ARCHIVO_MAESTRO_PRODUCTOS,&col,
//                         NOMBRE_ARCHIVO_CUENTAS_NO_EXISTENTES,&arb,
//                         cmp_arbol_nov);
//
//    printf("\n\n-Cantidad de actualizaciones: %d\n\n",cantAct);


    ///Ejercicio 5
    //int r;
    tCola col2;
    crearCola(&col2);
    int cant;
    tIndice ind,ind2;

    cant = podarArbolyGuardarEnCola(&arb,ALTURA_PODA,&col);

    printf("\nLa cantidad de elementos eliminados es de: %d",cant);

    if(arbolBinVacio(&arb))
    {
        printf("El arbol está vacio");
    }

    if(colaVacia(&col2))
    {
        printf("\nLa cola esta vacia");
    }

    while(!colaVacia(&col2))
    {
        verPrimeroCola(&col2,&ind,sizeof(tIndice));
        mostrarIndice(&ind);
        sacarEnColaCir(&col,&ind2,sizeof(tIndice));

    }


//    if(r == TODO_BIEN)
//    {
//        printf("\nSe pudo podar todo correctamente");
//        recorrerPreOrdenArbolBinBusq(&arb,NULL,imprimir);
//    }
//    else
//        printf("\nNo se pudo podar correctamente");


    return 0;
}
