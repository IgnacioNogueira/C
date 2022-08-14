#include "strings.h"

size_t nogueiraStrlen(const char * cad)
{

    size_t n = 0;

    while(*cad)
    {
        ++n;
        ++cad;
    }

    return n;
}

char * nogueiraStrcpy(char * dest, const char * orig)
{
    char *p = dest;

    while(*orig)
    {
        *dest = *orig;
        ++orig;
        ++dest;
    }

    *dest = '\0';
    return p;
}


void *nogueiraMemmove(void *dest,const void *orig, size_t cant)
{
    char *pDest = (char *)dest;
    const char *pOrig = (const char *)orig;

    if((pDest > pOrig) && (pDest < pOrig + cant))
    {
        while(cant)
        {
            *(pDest + cant) = *(pOrig + cant);
            --cant;
        }

    }

    else
    {
        while(cant)
        {
            *pDest = *pOrig;
            ++pDest;
            ++pOrig;
            --cant;

        }
    }

    return pDest;
}


int nogueiraStrcmp(const char* cad1,const char* cad2)
{

    while(*cad1 && *cad1 == *cad2)
    {
        ++cad1;
        ++cad2;
    }

    return *(unsigned char *)cad1 - *(unsigned char *)cad2;
}



int nogueiraStrncmp(const char* cad1,const char* cad2,size_t cant)
{
    if(cant == 0)
        return 0;

    while(*cad1 && --cant && *cad1 == *cad2)
    {
        ++cad1;
        ++cad2;
    }

    return *(unsigned char *)cad1 - *(unsigned char *)cad2;
}


char * nogueiraStrStr(const char* cad,const char * subcad){

    size_t tamSub = nogueiraStrlen(subcad);

    while(*cad && nogueiraStrncmp(cad,subcad,tamSub)){
        ++cad;
    }

    return *cad ? (char *)cad : NULL;
}

