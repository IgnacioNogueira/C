#include "listaDoble.h"

/*
int main() ///1
{
    int i;

    tProducto prod[] =
    {
        {12345,"Producto Uno",15,55.87},
        {12345,"Producto Uno",15,55.87},
        {12347,"Producto Tres",45,98.55},
        {12347,"Producto Tres",45,98.55},
        {12347,"Producto Tres",45,98.55},
        {12348,"Producto Cuatro",60,120.87},
        {12348,"Producto Cuatro",60,120.87},
        {12346,"Producto Dos",30,25.80}
    };

    tListaD ld;

    crearListaDoble(&ld);
    //crearListaDoble(&ld2);
    int cant;

    printf("\nInsertando al comienzo:\n\n");
    for(i = 0; i<sizeof(prod)/sizeof(tProducto); ++i)
    {
        printf("%d- %li %-*.*s  %d  %.2f\n",i+1,
               prod[i].idProducto,
               (int)sizeof(prod[i].descripcion)-1,
               (int)sizeof(prod[i].descripcion)-1,
               prod[i].descripcion,
               prod[i].cantidad,
               prod[i].precioUnitario
              );
        insertarAlFinalLD(&ld,&prod[i],sizeof(tProducto));
    }

    printf("\nMostrando de izq a der:\n\n");
    mostrarDeIzqADer(&ld,mostrarProd);

    ordenarLista(&ld,compararProd);

    printf("\nMostrando lista ordenada:\n\n");
    mostrarDeIzqADer(&ld,mostrarProd);

    cant = eliminaryAcumDuplicadosLD(&ld,compararProd,acumularCantidadProd);

    printf("\nElementos eliminados:%d\n\n",cant);
    mostrarDeIzqADer(&ld,mostrarProd);

    printf("\nCon el primero sacado:\n");
    sacarPrimeroLD(&ld,&prod,sizeof(tProducto));
    mostrarDeIzqADer(&ld,mostrarProd);

    sacarUltimoLD(&ld,&prod,sizeof(tProducto));
    printf("\nCon el ultimo sacado:\n");
    mostrarDeIzqADer(&ld,mostrarProd);

    vaciarListaDoble(&ld);

    if(listaDobleVacia(&ld))
    {
        printf("\nSE VACIO CORRECTAMENTE");
    }
    else
    {
        printf("\n NO SE VACIO CORRECTAMENTE");
        mostrarDeIzqADer(&ld,mostrarProd);
    }


//    tProducto prod2[] =
//    {
//        {12349,"Producto Cinco",15,55.87},
//        {12350,"Producto Seis",30,25.80},
//        {12351,"Producto Siete",45,98.55},
//        {12352,"Producto Ocho",60,120.87}
//    };
//
//    printf("\n\n/////////////////////////////////\n\n");
//
//    printf("\n\nInsertando al final:\n\n");
//    for(i = 0; i<sizeof(prod2)/sizeof(tProducto); ++i)
//    {
//        printf("%d- %li %-*.*s  %d  %.2f\n",i,
//               prod2[i].idProducto,
//               (int)sizeof(prod2[i].descripcion)-1,
//               (int)sizeof(prod2[i].descripcion)-1,
//               prod2[i].descripcion,
//               prod2[i].cantidad,
//               prod2[i].precioUnitario
//              );
//        insertarAlFinalLD(&ld2,&prod2[i],sizeof(tProducto));
//
//    }
//
//    printf("\nMostrando de der a izq:\n\n");
//    mostrarDeDerAIzq(&ld2,mostrarProd);
//    printf("\nMostrando de izq a der:\n\n");
//    mostrarDeIzqADer(&ld2,mostrarProd);

    return 0;
}
*/

/*
int main() ///2
{
    int i;
    tListaD ld,ld2;


    tProducto prod[] =
    {
        {12348,"Producto Cuatro",60,120.87},
        {12348,"Producto Cuatro",60,120.87},
        {12346,"Producto Dos",30,25.80},
        {12346,"Producto Dos",30,25.80},
        {12345,"Producto Uno",15,55.87},
        {12345,"Producto Uno",15,55.87},
        {12345,"Producto Uno",15,55.87},
        {12347,"Producto Tres",45,98.55},
        {12347,"Producto Tres",45,98.55}
    };

    crearListaDoble(&ld);
    //crearListaDoble(&ld3);
    printf("\nInsertando en orden sin duplicados:\n\n");
    for(i = 0; i<sizeof(prod)/sizeof(tProducto); ++i)
    {
        printf("%d- %li %-*.*s  %d  %.2f\n",i,
               prod[i].idProducto,
               (int)sizeof(prod[i].descripcion)-1,
               (int)sizeof(prod[i].descripcion)-1,
               prod[i].descripcion,
               prod[i].cantidad,
               prod[i].precioUnitario
              );
        insertarEnOrden(&ld,&prod[i],sizeof(tProducto),compararProd); //si hay un duplicado no te deja
    }

    printf("\nMostrando de der a izq:\n\n");
    mostrarDeDerAIzq(&ld,mostrarProd);

    printf("\nMostrando de izq a der:\n\n");
    mostrarDeIzqADer(&ld,mostrarProd);

    crearListaDoble(&ld2);
    tProducto prod2[] =
    {
        {12349,"Producto Cinco",15,55.87},
        {12350,"Producto Seis",30,25.80},
        {12349,"Producto Cinco",15,55.87},
        {12349,"Producto Cinco",15,55.87},
        {12351,"Producto Siete",45,98.55},
        {12352,"Producto Ocho",60,120.87},
        {12350,"Producto Seis",30,25.80},
        {12352,"Producto Ocho",60,120.87},
        {12352,"Producto Ocho",60,120.87},
        {12352,"Producto Ocho",60,120.87}
    };

    printf("\n\n/////////////////////////////////\n\n");


    printf("\nInsertando en orden con duplicados (Acumular):\n\n");
    for(i = 0; i<sizeof(prod2)/sizeof(tProducto); ++i)
    {
        printf("%d- %li %-*.*s  %d  %.2f\n",i,
               prod2[i].idProducto,
               (int)sizeof(prod2[i].descripcion)-1,
               (int)sizeof(prod2[i].descripcion)-1,
               prod2[i].descripcion,
               prod2[i].cantidad,
               prod2[i].precioUnitario
              );
        insertarEnOrdenAcum(&ld2,&prod2[i],sizeof(tProducto),compararProd,acumularCantidadProd);
        //insertarAlFinalLD(&ld2,&prod2[i],sizeof(tProducto));
    }

    //rintf("\nMostrando de der a izq:\n\n");
    //mostrarDeDerAIzq(&ld2,mostrarProd);
    printf("\nMostrando de izq a der:\n\n");
    mostrarDeIzqADer(&ld2,mostrarProd);


    tProducto aElim = {12352};

    printf("\nEliminando clave 12352 (Producto 8):\n\n");
    eliminarPorClave(&ld2,&aElim,sizeof(tProducto),compararProd);
    mostrarDeIzqADer(&ld2,mostrarProd);


    return 0;
}*/

int main()
{
    //int vec[] = {1,2,3,2,2,4,5,5,6,0};
    //int *aux = vec;
    // int num;

    tProducto prod2[] =
    {
        {12349,"Producto Cinco",15,55.87},
        {12349,"Producto Cinco",15,55.87},
        {12349,"Producto Cinco",15,55.87},
        {12350,"Producto Seis",30,25.80},
        {12350,"Producto Seis",30,25.80},
        {12351,"Producto Siete",45,98.55},
        {12352,"Producto Ocho",60,120.87},
        {12352,"Producto Ocho",60,120.87},
    };

    tListaD l;
    int i;
    crearListaDoble(&l);

    for(i = 0; i<sizeof(prod2)/sizeof(tProducto); ++i)
    {
        printf("%d- %li %-*.*s  %d  %.2f\n",i,
               prod2[i].idProducto,
               (int)sizeof(prod2[i].descripcion)-1,
               (int)sizeof(prod2[i].descripcion)-1,
               prod2[i].descripcion,
               prod2[i].cantidad,
               prod2[i].precioUnitario
              );
        //insertarEnOrdenAcum(&l,&prod2[i],sizeof(tProducto),compararProd,acumularCantidadProd);
        insertarAlFinalLD(&l,&prod2[i],sizeof(tProducto));
    }

    printf("\n\n\n");
    printf("\nMOSTRAR:\n");
    mostrarDeIzqADer(&l,mostrarProd);
    printf("\n\n\n");

    eliminaryAcumDuplicadosLD_MIO(&l,compararProd,acumularCantidadProd);

    printf("\nMOSTRAR DESPUES:\n");
    mostrarDeIzqADer(&l,mostrarProd);
    printf("\n\n\n");



//    printf("\nMOSTRAR ELIMINADOS:\n");
//    while(!listaDobleVacia(&l))
//    {
//        sacarPrimeroLD_MIO(&l,&prod,sizeof(tProducto));
//        printf("-%li %-*.*s  %d  %.2f\n",
//               prod.idProducto,
//               (int)sizeof(prod.descripcion)-1,
//               (int)sizeof(prod.descripcion)-1,
//               prod.descripcion,
//               prod.cantidad,
//               prod.precioUnitario
//              );
//    }

    return 0;
}
