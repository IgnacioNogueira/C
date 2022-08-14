#ifndef PASAJEBINTEXT_H_INCLUDED
#define PASAJEBINTEXT_H_INCLUDED

#include "archivosBasico.h"

int pasarArchivoBinTextLV(const char* nomArchBin,
                          const char* nomArchText,
                          char separador);

int pasarArchivoTextLVBin(const char* nomArchText,
                          const char* nomArchBin,
                          char separador);

int pasarArchivoBinTextLF(const char* nomArchBin,
                          const char* nomArchText);

int pasarArchivoTextLFBin(const char* nomArchText,
                          const char* nomArchBin);

#endif // PASAJEBINTEXT_H_INCLUDED
