#include "header.h"
#include "funciones.h"
#include "utils.h"
#include "tdaLista.h"

int main()
{
    // PUNTO A

    tListaD lc,ls;
    int c1,c2;
    crearListaDoble(&lc);
    crearListaDoble(&ls);
    crearLotePrueba(NOMBRE_ARCHIVO_PEDIDOS);

    PuntoALista(NOMBRE_ARCHIVO_PEDIDOS,&lc,cmpCodProdSectorYOficina,acumularCantidadPedida);

    printf("\nLista 1:\n");
    c1 = recorrerListaIzqADer(&lc,mostrarPedidos);
    printf("\nCantidad de elementos lista 1: %d\n",c1);

    PuntoALista(NOMBRE_ARCHIVO_PEDIDOS,&ls,cmpSectorYprod,acumularCantidadPedida);
    printf("\nLista 2:\n");
    c2 = recorrerListaIzqADer(&ls,mostrarPedidos);
    printf("\nCantidad de elementos lista 2: %d\n",c2);

    //PUNTO B

    puntoBNodos(&lc,4);

    // PUNTO C

    PuntoCArchivo(NOMBRE_ARCHIVO_RESULTADO_COMPRAS,&lc);
    mostrarArchivoFinal(NOMBRE_ARCHIVO_RESULTADO_COMPRAS);

    return 0;
}
