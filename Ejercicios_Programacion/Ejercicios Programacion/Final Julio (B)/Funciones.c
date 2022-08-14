#include "Funciones.h"

int cmpPedidosXCodigo(const void* elem1, const void* elem2);
int acumPedidos(void** elem1, size_t* tamElem1, void* elem2, size_t tamElem2);
void imprimirPedidoEnArchivo(const void* elem, size_t tamElem, void* paramAccion);

void generarArchivoPedidos(const char* pathPedidos)
{
    FILE* arch = fopen(pathPedidos, "wb");

    Pedido vPedidos[] = {
        {"HAMBU", 'A', 10},
        {"PAN", 'B', 20},
        {"CARNE", 'C', 7},
        {"TOMAT", 'D', 15},
        {"CARNE", 'E', 6},
        {"HAMBU", 'F', 18},
        {"PAN", 'G', 1},
        {"HAMBU", 'A', 2},
        {"TOMAT", 'B', 8},
        {"CARNE", 'C', 10}
    };

    fwrite(vPedidos, sizeof(vPedidos), 1, arch);

    fclose(arch);
}

int procesarPedidos(const char* pathPedidos, const char* pathAcumulador)
{
    FILE* archPedidos = fopen(pathPedidos, "rb");

    if(!archPedidos)
    {
        puts("Error al abrir el archivo de pedidos.");
        return ERR_ARCHIVO;
    }

    Lista listaPedidos;
    crearLista(&listaPedidos);

    Pedido lectPedido;

    fread(&lectPedido, sizeof(Pedido), 1, archPedidos);

    while(!feof(archPedidos))
    {
        insertarAlFinalDeLista(&listaPedidos, &lectPedido, sizeof(Pedido));
        fread(&lectPedido, sizeof(Pedido), 1, archPedidos);
    }

    fclose(archPedidos);

    if(eliminarDuplicadosDeListaDesord(&listaPedidos, cmpPedidosXCodigo, acumPedidos) != TODO_OK)
        return ERR_LISTA;

    FILE* archAcumXCodigo = fopen(pathAcumulador, "wt");

    if(!archAcumXCodigo)
    {
        puts("Error al abrir el archivo de acumulacion por codigo de producto.");
        return ERR_ARCHIVO;
    }

    vaciarListaConAccion(&listaPedidos, imprimirPedidoEnArchivo, archAcumXCodigo);

    fclose(archAcumXCodigo);

    return TODO_OK;
}

int cmpPedidosXCodigo(const void* elem1, const void* elem2)
{
    Pedido* p1 = (Pedido*)elem1;
    Pedido* p2 = (Pedido*)elem2;

    return strcmp(p1->cod, p2->cod);
}

int acumPedidos(void** elem1, size_t* tamElem1, void* elem2, size_t tamElem2)
{
    Pedido** p1 = (Pedido**)elem1;
    Pedido* p2 = (Pedido*)elem2;

    (*p1)->sector = ' ';
    (*p1)->cant += p2->cant;

    return TODO_OK;
}

void imprimirPedidoEnArchivo(const void* elem, size_t tamElem, void* paramAccion)
{
    FILE* arch = (FILE*)paramAccion;

    Pedido* pedido = (Pedido*)elem;

    fprintf(arch, "%s|%d\n", pedido->cod, pedido->cant);
}
