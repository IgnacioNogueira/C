#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include "header.h"

void menu(void);

int atoiMio(const char *cad);

char * revertirString(char * cad);
char * itoaMio(int num, char * cad,int base);
void trabajoConStrings(char * cad);

void espacioPrincipioFin(char *cad);
void sacarCaracteresYnumeros(char *cad);
void unSoloEspacio(char * cad);
size_t cantPalabrasOracion(const char * cad);
void textoAMinus(char *cad);
//const char * palabraMasRepetida(const char * cad,size_t cantPal);
char * palabraMasRepetida(char * cad,size_t cantPal);

//void palabraMasRepetida(const char * cad);


//Ejercicios

void EjercicioAtoiItoa();
void EjercicioContarPalabras();
void EjercicioEliminarPalMasRepetida();


#endif // FUNCIONES_H_INCLUDED
