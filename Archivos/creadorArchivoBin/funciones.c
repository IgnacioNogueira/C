#include "header.h"

int crearArchivoPed(char * nombreArchPed)
{
    tPedidos ped[] =
    {
        {"3",10001,20,50.85},
        {"177",10002,30,20.45},
        {"128",10003,50,120.85},
        {"128",10004,25,120.85},
        {"128",10005,15,80.85},
        {"128",10006,10,55.45},
        {"75",10007,12,110.12}

    };

    FILE *fp = fopen(nombreArchPed,"wb");

    if(fp)
    {
        fwrite(ped,sizeof(ped),1,fp);
        fclose(fp);
        return 1;
    }

    return 0;
}

int crearArchivoPag(char * nombreArchPag)
{
    tPagos pag[] =
    {
        {'T',"3",50.85},
        {'E',"128",150.15},
        {'T',"155",120.85},
        {'T',"75",1321.50}
    };

    FILE *fp = fopen(nombreArchPag,"wb");

    if(fp)
    {
        fwrite(pag,sizeof(pag),1,fp);
        fclose(fp);
        return 1;
    }

    return 0;
}

int crearArchivoBin(char * nombreBinario)
{
    FILE * fpb = fopen(nombreBinario,"wb");

    if(fpb)
    {
        fclose(fpb);
        return 1;
    }

    printf("\nNO SE PUDO CREAR EL NOMBRE DEL ARCHIVO %s",nombreBinario);
    return -3;
}

int nogueira_strcmp(const char *cad1,const char *cad2)
{

    while(*cad1 && *cad1 == *cad2)
    {
        cad1++;
        cad2++;

    }

    return *(unsigned char *)cad1 - *(unsigned char *)cad2;
}
