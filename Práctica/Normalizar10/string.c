//#include "cadena.h"
#include "string.h"

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

void *nogueiraMemmove(void *dest,const void *orig, size_t cant)
{
    char *pDest = (char *)dest;
    const char *pOrig = (const char *)orig;

    if((pDest > pOrig) && (pDest < pOrig + cant))
    {
        while(cant)
        {
            *(pDest + cant) = *(pOrig + cant);
            cant--;
        }

    }

    else
    {
        while(cant)
        {
            *pDest = *pOrig;
            pDest++;
            pOrig++;
            cant--;

        }
    }

    return pDest;
}

char * nogueiraStrcpy(char * dest, const char * orig)
{
    char *p = dest;

    while(*orig)
    {
        *dest = *orig;
        ++dest;
        ++orig;
    }
    *dest = '\0';
    return p; //va a devolver el string como puntero -> por eso la creación de principio
}


int nogueiraStrncmp(const char* cad1,const char* cad2,size_t cant)
{
    if(cant == 0)
        return 0;

    while(*cad1 && --cant && *cad1 == *cad2)
    {
        cad1++;
        cad2++;
    }

    return *(unsigned char *)cad1 - *(unsigned char *)cad2;
}

char * nogueiraStrStr(const char* cad,const char * subcad)
{
    size_t tamSub = nogueiraStrlen(subcad);

    while(*cad && nogueiraStrncmp(cad,subcad,tamSub))   //hasta que no sea != no deja de retornar
    {
        cad++;
    }
    return *cad ? (char *)cad : NULL;
}
