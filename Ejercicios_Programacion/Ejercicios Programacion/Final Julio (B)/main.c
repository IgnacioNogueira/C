#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Tipos.h"
#include "Comun.h"
#include "Funciones.h"

int main()
{
    generarArchivoPedidos("pedido.dat");

    int ret;

    if((ret = procesarPedidos("pedido.dat", "codigos.txt")) != TODO_OK)
        return ret;

    return 0;
}
