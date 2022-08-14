#ifndef ARCHIVOSBASICO_H_INCLUDED
#define ARCHIVOSBASICO_H_INCLUDED

#include <stdio.h>
#include "trozadoLFLV.h"
#include "estructuras.h"

int abrirArchivo(FILE** arch, const char* nombre, const char* modoApertura);
int crearCargarArchivoBin(const char* nomArchBin);
void mostrarEmpleado(const void *);
void mostrarArchivoBin(const char* nomArchBin);
void mostrarArchivoTextLV(const char* nomArchText, char separador);
void mostrarArchivoTextLF(const char* nomArchText);

#endif // ARCHIVOSBASICO_H_INCLUDED
