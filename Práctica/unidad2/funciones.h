#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include "header.h"

//Ejercicios

//Ejercicio A
#define maxmM 256

char letraMasRepetida(const char * str);
void moverAIzqElems(void *p1,void *p2);
int eliminarLetraMasRepetida(char *str, const char letra);

//Ejercicio B

void unSoloEspacio(char * textComp);

//Ejercicio C - Archivos

int crearArchivoBin(char * nombreArchivo);
int crearArchivoTxt(char * nombreArchivo);
int leerYmostrarArchivoBinNotas(const char * nombreArchivo);

int leerYmostrarArchivoBinNotas2(const char * nombreArchivo);

int leerYmostrarArchivoTxt(const char * nombreArchivo);
int crearArchivoLF(const char * nombreOrig, const char * nombreDest);
void mostrarAlumnoNotas(const tAlumno * alum);

void mostrarAlumnoNotas2(const tAlumno * alum);

void mostrarAlumnoFinal(const tAlumno * alum);
int promAlumnos(char * archivoBinNotas, tAlumno * alumno, size_t cantNotas);
void trozarCamposLF(tAlumno * alum,char * linea);


#endif // FUNCIONES_H_INCLUDED
