#ifndef STRINGS_H_INCLUDED
#define STRINGS_H_INCLUDED

#include "header.h"

size_t nogueiraStrlen(const char * cad);
char * nogueiraStrcpy(char * dest, const char * orig);
void *nogueiraMemmove(void *dest,const void *orig, size_t cant);
int nogueiraStrcmp(const char* cad1,const char* cad2);
char * nogueiraStrcpyMOD(char * dest, const char * orig);
int nogueiraStrncmp(const char* cad1,const char* cad2,size_t cant);
char * nogueiraStrStr(const char* cad,const char * subcad);



#endif // STRINGS_H_INCLUDED
