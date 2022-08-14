#include "main.h"
#include "funciones.h"

int main()
{
    if(crearSetDeDatos(NOMBRE_ARCHIVO_TEXTO) == TODO_BIEN)
    {
        procesarArchivoPilas(NOMBRE_ARCHIVO_TEXTO);
        remove(NOMBRE_ARCHIVO_TEXTO);
    }

    return 0;
}
