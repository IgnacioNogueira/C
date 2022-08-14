#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "utilitarias.h"

int main()
{
    FILE *pedidos;
    tLista compras, sectores;
    pedidos = fopen("pedidos.txt","rt");
    if(!pedidos)
    {
        printf("ERROR al abrir los archivos.\n");
        return 1;
    }
    crearLista(&compras);
    if(!cargarCompras(pedidos, &compras))
    {
        printf("ERROR al crear la lista de compras.\n");
    }
    crearLista(&sectores);
    if(!cargarSectores(pedidos, &sectores))
    {
        printf("ERROR al crear la lista de sectores.\n");
    }
    fclose(pedidos);
    return 0;
}
