#include "main.h"


//Cantidad maxima de vehiculos generados aleatoriamente -1
//Utilizar 1 para no generar vehiculos(archivo vacio/inexistente)
#define CANT_MAXIMA_REGISTROS 30

//Antiguedad maxima de vehiculos aleatorios
#define ANT_MAXIMA 10

int main() {
    int error;
    char nombreArchivo[] = "vehiculos.dat";

    //Utilizar uno de los siguientes set de datos:
    //generarArchivoConsigna(nombreArchivo); //Mismos datos que la consigna
    generarArchivo(nombreArchivo); //Datos aleatorios

    error = mostrarArchivo(nombreArchivo);
    if(error){
        printf("El archivo esta vacio\n");
    }
    if(!error){
        error = procesarVehiculos(nombreArchivo);
    }
    if(error){
        printf("ERROR AL ABRIR ARCHIVO DE DATOS");
    }

    return 0;
}

int generarArchivo(char *nombre) {
    FILE *fDatos;
    int cantidad;
    tVehiculo vehiculoAux;
    int i;
    char dominioGenerico[] = "DDD000";
    srand(time(NULL));
    cantidad = rand() % CANT_MAXIMA_REGISTROS;

    fDatos = fopen(nombre, "wb");
    if (!fDatos) {
        printf("ERROR AL ABRIR ARCHIVO DE DATOS\n");
        exit(-1);
    }

    for (i = 0; i < cantidad; i++) {
        //El dominio no afecta a la funcionalidad, por lo tanto uso uno generico
        strcpy(vehiculoAux.dominio, dominioGenerico);
        vehiculoAux.antiguedad = rand() % ANT_MAXIMA + 1;
        vehiculoAux.kilometros = rand() % 1000 + 1;
        fwrite(&vehiculoAux, sizeof(tVehiculo), 1, fDatos);
    }

    fclose(fDatos);
    return 1;
}


int generarArchivoConsigna(char *nombre) {
    tVehiculo vector[5] = {
            {"AAA111", 10, 200},
            {"BBB111", 5,  100},
            {"AAA222", 10, 300},
            {"CCC111", 1,  100},
            {"DDD111", 5,  500}
    };
    FILE *fDatos = fopen(nombre, "wb");
    if (!fDatos) {
        printf("ERROR AL ABRIR ARCHIVO DE DATOS\n");
        exit(-1);
    }

    fwrite(vector, sizeof(tVehiculo), 5, fDatos);
    fclose(fDatos);
    return 1;
};

int mostrarArchivo(char *nombre) {
    tVehiculo vehiculoAux;
    FILE *fDatos = fopen(nombre, "rb");
    if (!fDatos) {
        printf("ERROR AL ABRIR ARCHIVO DE DATOS\n");
        exit(-1);
    }

    fread(&vehiculoAux, sizeof(tVehiculo), 1, fDatos);
    //Si el archivo esta vacio:
    if(feof(fDatos)){
        return 1;
    }
    //Si el archivo no esta vacio:
    printf("*** MOSTRANDO ARCHIVO DE DATOS: ***\n");
    while (!feof(fDatos)) {
        printf("Dominio: %6s\tAntiguedad:%5d\tKilometros:%10d\n",
               vehiculoAux.dominio,
               vehiculoAux.antiguedad,
               vehiculoAux.kilometros
        );
        fread(&vehiculoAux, sizeof(tVehiculo), 1, fDatos);
    }
    printf("\n*** FIN ARCHIVO DATOS ***");
    return 0;
}
