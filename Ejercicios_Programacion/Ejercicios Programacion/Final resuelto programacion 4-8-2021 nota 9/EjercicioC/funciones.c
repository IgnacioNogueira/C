#include "funciones.h"

int compararAntiguedad(const void *res1, const void *res2);

int acumularResultados(void **res1, unsigned int *tam1, const void *res2, unsigned tam2);

void mostrarResultados(void *res, unsigned int tam, void *params);

int procesarVehiculos(char *nombreArchivoDatos) {
    tLista listaResultados;
    tVehiculo vehiculoAux;
    tResultado resultadoAux;
    FILE *fDatos;

    crearLista(&listaResultados);

    fDatos = fopen(nombreArchivoDatos, "rb");
    if (!fDatos) {
        return 1; //error
    }

    fread(&vehiculoAux, sizeof(tVehiculo), 1, fDatos);
    while (!feof(fDatos)) {
        resultadoAux.antiguedad = vehiculoAux.antiguedad;
        resultadoAux.cantidad = 1;
        resultadoAux.kilometros = vehiculoAux.kilometros;

        ponerEnOrden(&listaResultados, &resultadoAux, sizeof(resultadoAux), compararAntiguedad, acumularResultados);
        fread(&vehiculoAux, sizeof(tVehiculo), 1, fDatos);
    }

    fclose(fDatos);

    printf("\n\n*** MOSTRANDO RESULTADOS: ***\n");
    recorrerLista(&listaResultados, NULL, mostrarResultados);
    printf("*** FIN RESULTADOS ***");
    return 0;
}

int compararAntiguedad(const void *res1, const void *res2) {
    if (((const tResultado *) res1)->antiguedad < ((const tResultado *) res2)->antiguedad) {
        return -1;
    }
    if (((const tResultado *) res1)->antiguedad > ((const tResultado *) res2)->antiguedad) {
        return 1;
    }
    return 0;

}

int acumularResultados(void **res1, unsigned int *tam1, const void *res2, unsigned tam2) {
    tResultado *resultado = *((tResultado **) res1);
    const tResultado *resultado2 = (tResultado *) res2;
    resultado->kilometros += resultado2->kilometros;
    resultado->cantidad++;
    return 1;
}

void mostrarResultados(void *res, unsigned int tam, void *params) {
    tResultado *resultado = res;
    printf("Antiguedad: %5d\tKilometros:%10.2f\n",
           resultado->antiguedad,
           ((float)resultado->kilometros / (float)resultado->cantidad));
}
