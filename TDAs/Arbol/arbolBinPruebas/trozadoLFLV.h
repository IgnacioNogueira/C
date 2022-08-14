#ifndef TROZADOLFLV_H_INCLUDED
#define TROZADOLFLV_H_INCLUDED

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "estructuras.h"

#define LONG_REG 100

#define LONG_DNI 8
#define LONG_APYN 35
#define LONG_CAT 1
#define LONG_FECHA 8
#define LONG_SUELDO 9
#define LONG_REG_LF 61

void parsearRegLV(char* reg, tEmpleado* emp, char separador);
void parsearRegLF(char* reg, tEmpleado* emp);
void quitarEspaciosAlFinal(char *cad);


#endif // TROZADOLFLV_H_INCLUDED
