#include "main.h"
#include "funciones.h"

int main()
{
    int act;
    tIndice ind;
    tLista lista;
    FILE *fp;

    printf("-> Contenido del archivo maestro <-\n");
    leerYMostrarArchivo(NOM_ARCH_MAESTRO);
    printf("-> Contenido del archivo novedades <-\n");
    leerYMostrarArchivoDeTexto(NOM_ARCH_NOVEDAD);
    crearIndice(NOM_ARCH_MAESTRO, &ind, &lista, fp);
    act = actualizarMaestro(NOM_ARCH_MAESTRO, NOM_ARCH_NOVEDAD, &lista);
    printf("-> Contenido del archivo maestro actualizado <-\n");
    leerYMostrarArchivo(NOM_ARCH_MAESTRO);
    printf("-> Se realizaron %d actualizaciones <-",act);
    return 0;
}
