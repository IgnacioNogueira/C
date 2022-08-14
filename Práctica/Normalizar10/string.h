#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

#include "cadena.h"

size_t nogueiraStrlen(const char * cad);
//void *nogueiraMemmove(void *dest,void *orig, size_t cant);
void *nogueiraMemmove(void *dest,const void *orig, size_t cant);
char * nogueiraStrcpy(char * dest, const char * orig);
int nogueiraStrncmp(const char* cad1,const char* cad2,size_t cant);
char * nogueiraStrStr(const char* cad,const char * subcad);


#endif // STRING_H_INCLUDED
