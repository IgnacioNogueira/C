#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

#include "header.h"

size_t nogueiraStrlen(const char *cad);
int nogueiraStrncmp(const char * cad1, const char * cad2, size_t cant);
char * nogueiraStrStr(const char *cad, const char *subcad);
void * nogueiraMemmove(void * dest, const void *orig,size_t cant);



#endif // STRING_H_INCLUDED
