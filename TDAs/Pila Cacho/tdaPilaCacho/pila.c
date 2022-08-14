#include "pila.h"
#include "pilaDinamica.h"
#include "pilaEstatica.h"
#include "funcionesPila.h"
#define tam 500

void ProbarPilaEstatica()
{
    int i;
    tPilaE pil;
    tProducto prod[] =
    {
        {1,"Producto Uno",15,50.88},
        {2,"Producto Dos",25,25.28},
        {3,"Producto Tres",10,40.88},
    };

    crearPilaEstatica(&pil);

    if(!pilaEstaticaLlena(&pil,sizeof(tProducto)))
    {
        for(i = 0; i< sizeof(prod)/sizeof(tProducto); ++i)
        {
            ponerEnPilaEstatica(&pil,&prod[i],sizeof(tProducto));

        }

    }

    printf("\n- Pila estatica original -\n");
    pilaEstaticaVerTope(&pil,&prod,sizeof(tProducto));
    printf("\nID: %d\tNombre producto: %s\tCantidad:%d\tPrecio:%.2f\n",prod->idProducto,
           prod->descripcion,
           prod->cantidad,
           prod->precioUnitario);

    printf("\n- Pila estatica original-1 -\n");
    sacarDePilaEstatica(&pil,&prod,sizeof(tProducto));
    pilaEstaticaVerTope(&pil,&prod,sizeof(tProducto));
    printf("\nID: %d\tNombre producto: %s\tCantidad:%d\tPrecio:%.2f\n",prod->idProducto,
           prod->descripcion,
           prod->cantidad,
           prod->precioUnitario);

    printf("\n- Pila estatica original-2 -\n");
    sacarDePilaEstatica(&pil,&prod,sizeof(tProducto));
    pilaEstaticaVerTope(&pil,&prod,sizeof(tProducto));
    printf("\nID: %d\tNombre producto: %s\tCantidad:%d\tPrecio:%.2f\n",prod->idProducto,
           prod->descripcion,
           prod->cantidad,
           prod->precioUnitario);


    printf("\nSE PROCEDE A VACIAR LA PILA...\n");
    vaciarPilaEstatica(&pil);

    if(!pilaEstaticaVacia(&pil))
    {
        pilaEstaticaVerTope(&pil,&prod,sizeof(tProducto));
        printf("\nID: %d\tNombre producto: %s\tCantidad:%d\tPrecio:%.2f\n",prod->idProducto,
               prod->descripcion,
               prod->cantidad,
               prod->precioUnitario);
    }
    else
    {
        printf("\n*********La pila esta vacía*********\n");
    }
}

void ProbarPilaDinamica()
{
    int i;
    tPilaD pil;
    tProducto prod[] =
    {
        {4,"Producto Cuatro",15,60.99},
        {5,"Producto Cinco",25,35.99},
        {6,"Producto Seis",10,50.99},
    };

    crearPilaDinamica(&pil);

    if(!pilaDinLlena(&pil,sizeof(tProducto)))
    {
        for(i = 0; i< sizeof(prod)/sizeof(tProducto); ++i)
        {
            ponerEnPilaDinamica(&pil,&prod[i],sizeof(tProducto));

        }
    }

    printf("\n- Pila dinamica original -\n");
    vaciarPilaDinamica(&pil);

    if(pilaDinVacia(&pil))
    {
        printf("\n:D");

    }

    /*
    verTopePilaDinamica(&pil,&prod,sizeof(tProducto));
    printf("\nID: %d\tNombre producto: %s\tCantidad:%d\tPrecio:%.2f\n",prod->idProducto,
           prod->descripcion,
           prod->cantidad,
           prod->precioUnitario);

    printf("\n- Pila dinamica original -1 -\n");
    sacarPilaDinamica(&pil,&prod,sizeof(tProducto));
    verTopePilaDinamica(&pil,&prod,sizeof(tProducto));
    printf("\nID: %d\tNombre producto: %s\tCantidad:%d\tPrecio:%.2f\n",prod->idProducto,
           prod->descripcion,
           prod->cantidad,
           prod->precioUnitario);

    printf("\n- Pila dinamica original -2 -\n");
    sacarPilaDinamica(&pil,&prod,sizeof(tProducto));
    verTopePilaDinamica(&pil,&prod,sizeof(tProducto));
    printf("\nID: %d\tNombre producto: %s\tCantidad:%d\tPrecio:%.2f\n",prod->idProducto,
           prod->descripcion,
           prod->cantidad,
           prod->precioUnitario);

    printf("\nSE PROCEDE A VACIAR LA PILA...\n");
    vaciarPilaDinamica(&pil);

    if(!pilaDinVacia(&pil))
    {
        verTopePilaDinamica(&pil,&prod,sizeof(tProducto));
        printf("\nID: %d\tNombre producto: %s\tCantidad:%d\tPrecio:%.2f\n",prod->idProducto,
               prod->descripcion,
               prod->cantidad,
               prod->precioUnitario);
    }
    else
    {
        printf("\n*********La pila esta vacía*********\n");
    }
    */
}

void ejercicioPilaSumaNrosGrandes()
{
    char nro1[tam] = "9";
    char nro2[tam] = "1";
    char resultado[tam+1];

    printf("\nEl resultado de la pila es: %s\n",sumarNGrandes(nro1,nro2,resultado));

}
