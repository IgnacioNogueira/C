#include "utilitarias.h"

int leerRegistro(FILE *archivo, tPedido *pedido)
{
    return fscanf(archivo, "%d|%[^|\n]|%d|%c|%[^|\n]\n",
                  &pedido->nroPedido, pedido->codPro,
                  &pedido->cantPedida, &pedido->codSector,
                  pedido->oficina) == 5;
}

int cargarCompras(FILE *archivo, tLista *compras)
{
    tPedido pedido;
    tCompra compra;
    while(leerRegistro(archivo, &pedido))
    {
        compra.cantPedida = pedido.cantPedida;
        strcpy(compra.codPro, pedido.codPro);
        if(!ponerEnOrden(compras, &compra, sizeof(tCompra), compararCompras, acumularCompras))
            return ERROR;
    }
    rewind(archivo);
    return TODO_OK;
}

int compararCompras(const void *d1, const void *d2)
{
    tCompra *p1 = (tCompra *)d1;
    tCompra *p2 = (tCompra *)d2;
    return strcmp(p1->codPro, p2->codPro);
}

int acumularCompras(void **destino, unsigned *tamDestino, const void *origen, unsigned tamOrigen)
{
    tCompra **aux1 = (tCompra **)destino;
    tCompra *aux2 = (tCompra *)origen;
    (*aux1)->cantPedida += aux2->cantPedida;
    return TODO_OK;
}

int cargarSectores(FILE *archivo, tLista *sectores)
{
    tPedido pedido;
    tSector sector;
    while(leerRegistro(archivo, &pedido))
    {
        sector.cantPedida = pedido.cantPedida;
        strcpy(sector.codPro, pedido.codPro);
        sector.codSector = pedido.codSector;
        if(!ponerEnOrden(sectores, &sector, sizeof(tSector), compararSectores, acumularSectores))
            return ERROR;
    }
    rewind(archivo);
    return TODO_OK;
}

int compararSectores(const void *d1, const void *d2)
{
    tSector *p1 = (tSector *)d1;
    tSector *p2 = (tSector *)d2;
    int cmp;
    if(!(cmp = p1->codSector - p2->codSector))
        cmp = strcmp(p1->codPro, p2->codPro);
    return cmp;
}

int acumularSectores(void **destino, unsigned *tamDestino, const void *origen, unsigned tamOrigen)
{
    tSector **aux1 = (tSector **)destino;
    tSector *aux2 = (tSector *)origen;
    (*aux1)->cantPedida += aux2->cantPedida;
    return TODO_OK;
}
