#include "trozadoLFLV.h"

void parsearRegLF(char* reg, tEmpleado* emp)
{
    char* aux = reg + LONG_REG_LF;
    *aux = '\0';

    aux -= LONG_SUELDO;
    sscanf(aux, "%f", &emp->sueldo);
    *aux = '\0';

    aux -= LONG_FECHA;
    sscanf(aux, "%2d%2d%4d",&emp->fechaIngreso.dia,
                            &emp->fechaIngreso.mes,
                            &emp->fechaIngreso.anio);
    *aux = '\0';

    aux -= LONG_CAT;
    sscanf(aux, "%c", &emp->categoria);
    *aux = '\0';

    aux -= LONG_APYN;

    quitarEspaciosAlFinal(aux);

    strcpy(emp->apyn, aux);
    *aux = '\0';

    aux -= LONG_DNI;
    sscanf(aux, "%lu", &emp->dni);
    *aux = '\0';
}
void quitarEspaciosAlFinal(char *cad)
{
    char *ini = cad;
    if(!*cad)
    {
        return;
    }
    while(*cad)
    {
        ++cad;
    }
    --cad;


    while(cad > ini && !isalpha(*cad))
    {
        --cad;
    }
    if(cad > ini)
    {
        ++cad;
        *cad = '\0';
    }
}
void parsearRegLV(char* reg, tEmpleado* emp, char sep)
{
    char* aux = strchr(reg, '\n');
    *aux = '\0';

    aux = strrchr(reg, sep);
    sscanf(aux + 1, "%f", &emp->sueldo);
    *aux = '\0';

    aux = strrchr(reg, sep);

    sscanf(aux + 1, "%d/%d/%d",&emp->fechaIngreso.dia,
                                &emp->fechaIngreso.mes,
                                &emp->fechaIngreso.anio);
    *aux = '\0';

    aux = strrchr(reg, sep);
    sscanf(aux+1, "%c", &emp->categoria);
    *aux = '\0';

    aux = strrchr(reg, sep);
    strcpy(emp->apyn, aux+1);
    *aux = '\0';

    sscanf(reg, "%lu", &emp->dni);

}
