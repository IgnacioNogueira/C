#include "pedidos.h"
#include "colaDinamica.h"

void crearArchivoPedyPag(FILE * nombreArchPed,FILE * nombreArchPag)
{
    tPedidos ped[] =
    {
        {"3",10001,20,50.85},
        {"177",10002,30,20.45},
        {"128",10003,50,120.85},
        {"128",10003,50,120.85},
        {"128",10004,50,80.85},
        {"128",10005,50,55.45},
        {"75",10006,50,110.12},

    };

    tPagos pag[] =
    {
        {'T',"3",50.85},
        {'E',"128",150.15},
        {'T',"155",120.85},
        {'E',"155",20.45}
    };

    fwrite(ped,sizeof(ped),1,nombreArchPed);
    fwrite(pag,sizeof(pag),1,nombreArchPag);
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

int abrirArchivo(FILE **fp,const char * nombreArchivo,const char * modoApertura)
{
    *fp = fopen(nombreArchivo,modoApertura);

    if(*fp == NULL)
    {
        return 0;
    }

    return 1;
}


int leerYmostrarArchivoBin(FILE * archBin)
{
    tPedidos ped;

    fread(&ped,sizeof(tPedidos),1,archBin);

    while(!feof(archBin))
    {
        mostrarMaesBin(&ped);
        fread(&ped,sizeof(tPedidos),1,archBin);
    }

    return 1;
}

void mostrarMaesBin(tPedidos * ped)
{
    if(!ped)
    {
        printf("\nNo hay pedidos que mostrar");
        return;
    }

    printf("-%*.*s  %li %d  %.2f\n",
           (int)sizeof(ped->idCliente)-1,
           (int)sizeof(ped->idCliente)-1,
           ped->idCliente,
           ped->idProd,
           ped->cantPed,
           ped->precUnitario
          );
}


int leerYmostrarArchivoBinPagos(FILE * archBin)
{
    tPagos pag;

    fread(&pag,sizeof(tPagos),1,archBin);

    while(!feof(archBin))
    {
        mostrarMaesBinPagos(&pag);
        fread(&pag,sizeof(tPagos),1,archBin);
    }

    return 1;
}

void mostrarMaesBinPagos(tPagos * pag)
{
    if(!pag)
    {
        printf("\nNo hay pagos que mostrar");
        return;
    }

    printf("-%c  %*.*s  %.2f\n",
           pag->tipoPago,
           (int)sizeof(pag->idCliente)-1,
           (int)sizeof(pag->idCliente)-1,
           pag->idCliente,
           pag->montoPago
          );
}

void mostrarArchivosResult(const char * nombreArchivo)
{
    tPedidos ped;
    FILE * fp = fopen(nombreArchivo,"rb");

    if(!fp)
    {
        exit(-1);
    }

    fread(&ped,sizeof(tPedidos),1,fp);

    while(!feof(fp))
    {
        printf("-%*.*s  %li %d  %.2f\n",
               (int)sizeof(ped.idCliente)-1,
               (int)sizeof(ped.idCliente)-1,
               ped.idCliente,
               ped.idProd,
               ped.cantPed,
               ped.precUnitario
              );

        fread(&ped,sizeof(tPedidos),1,fp);
    }

    fclose(fp);
}


int StatusClienteDin(FILE *archPed,FILE *archPag, FILE *archPedOk, FILE *archNc,FILE *archClDesc)
{
    tPedidos ped,pedActual,pedAcum;
    tPagos pag;
    tColaD col;

    crearColaDin(&col);

    long posOrigPed = ftell(archPed);
    long posOrigPag = ftell(archPag);
    rewind(archPed);
    rewind(archPag);

    float totalValor;
    int enc,cantCoinc = 0;

    fread(&pag,sizeof(tPagos),1,archPag);
    fread(&ped,sizeof(tPedidos),1,archPed);
    fread(&pedActual,sizeof(tPedidos),1,archPed); //no funciona si ponés un solo dato

    if(feof(archPag))
    {
        printf("\n\n-------------No hay datos en el archivo de Pagos-------------\n\n");
        return 0;
    }
    else if(feof(archPed))
    {
        printf("\n\n-------------No hay datos en el archivo de Pedidos-------------\n\n");
        return 0;

    }
    else
    {
        while(!feof(archPed)) //me unifica las cosas de pagos
        {
            totalValor += ped.cantPed * ped.precUnitario;
            ponerEnColaDin(&col,&ped,sizeof(tPedidos));
            //fread(&pedActual,sizeof(tPedidos),1,archPed); //no funciona si ponés un solo dato

            while(!strcmp(ped.idCliente,pedActual.idCliente) && !feof(archPed))
            {
                fseek(archPed,-1L*(long)sizeof(tPedidos),SEEK_CUR); //para volver atrás
                fread(&ped,sizeof(tPedidos),1,archPed);
                totalValor += ped.cantPed * ped.precUnitario;
                ponerEnColaDin(&col,&ped,sizeof(tPedidos));

                if(!feof(archPed))
                {
                    fread(&pedActual,sizeof(tPedidos),1,archPed);
                }
                ++cantCoinc;
            }

            fseek(archPed,-1L*(long)sizeof(tPedidos),SEEK_CUR); //para volver atrás y guardar el %ped correcto. Sirve tanto para el while de adentro, como si encuentra uno en especial

            enc = estatusEncontrado(archPag,&ped,&pag);

            if(enc)
            {
                if(totalValor > pag.montoPago)
                {
                    while(!colaVaciaDin(&col))
                    {
                        /*verPrimeroColaDin(&col,&ped,sizeof(tPedidos));
                        printf("-%*.*s  %li %d  %.2f\n",
                               (int)sizeof(ped.idCliente)-1,
                               (int)sizeof(ped.idCliente)-1,
                               ped.idCliente,
                               ped.idProd,
                               ped.cantPed,
                               ped.precUnitario
                              );*/
                        sacarColaDin(&col,&pedAcum,sizeof(tPedidos));
                        fwrite(&pedAcum,sizeof(tPedidos),1,archNc);//no cubre
                    }
                }
                else if(totalValor <= pag.montoPago)
                {
                    while(!colaVaciaDin(&col))
                    {
                        /*verPrimeroColaDin(&col,&ped,sizeof(tPedidos));
                        printf("-%*.*s  %li %d  %.2f\n",
                               (int)sizeof(ped.idCliente)-1,
                               (int)sizeof(ped.idCliente)-1,
                               ped.idCliente,
                               ped.idProd,
                               ped.cantPed,
                               ped.precUnitario
                              );*/
                        sacarColaDin(&col,&pedAcum,sizeof(tPedidos));
                        fwrite(&pedAcum,sizeof(tPedidos),1,archPedOk);//cubre
                    }
                }
                ++cantCoinc;
            }
            else
            {
                while(!colaVaciaDin(&col))
                {
                    /*verPrimeroColaDin(&col,&ped,sizeof(tPedidos));
                    printf("-%*.*s  %li %d  %.2f\n",
                           (int)sizeof(ped.idCliente)-1,
                           (int)sizeof(ped.idCliente)-1,
                           ped.idCliente,
                           ped.idProd,
                           ped.cantPed,
                           ped.precUnitario
                          );*/
                    sacarColaDin(&col,&pedAcum,sizeof(tPedidos));
                    fwrite(&pedAcum,sizeof(tPedidos),1,archClDesc);//si te hice un pedido y no lo pagué, error
                }

            }
            fseek(archPed,0L,SEEK_CUR); //restablezco el flujo
            totalValor = 0;
            rewind(archPag);

            if(!feof(archPed))
            {
                fread(&ped,sizeof(tPedidos),1,archPed);
                if(!feof(archPed))
                {
                    fread(&pedActual,sizeof(tPedidos),1,archPed);
                }
            }
        } //se va del while

        if(!feof(archPed)) //por si queda lo de los repetidos abajo
        {
            fseek(archPed,-1L*(long)sizeof(tPedidos),SEEK_CUR);  //fseek problemático
            totalValor += ped.cantPed * ped.precUnitario;
            ponerEnColaDin(&col,&ped,sizeof(tPedidos));
            enc = estatusEncontrado(archPag,&ped,&pag);

            if(enc)
            {
                if(totalValor > pag.montoPago)
                {
                    while(!colaVaciaDin(&col))
                    {
                        verPrimeroColaDin(&col,&ped,sizeof(tPedidos));
                        printf("-%*.*s  %li %d  %.2f\n",
                               (int)sizeof(ped.idCliente)-1,
                               (int)sizeof(ped.idCliente)-1,
                               ped.idCliente,
                               ped.idProd,
                               ped.cantPed,
                               ped.precUnitario
                              );
                        sacarColaDin(&col,&pedAcum,sizeof(tPedidos));
                        fwrite(&pedAcum,sizeof(tPedidos),1,archNc);//no cubre
                    }

                }
                else if(totalValor <= pag.montoPago)
                {
                    while(!colaVaciaDin(&col))
                    {
                        verPrimeroColaDin(&col,&ped,sizeof(tPedidos));
                        printf("-%*.*s  %li %d  %.2f\n",
                               (int)sizeof(ped.idCliente)-1,
                               (int)sizeof(ped.idCliente)-1,
                               ped.idCliente,
                               ped.idProd,
                               ped.cantPed,
                               ped.precUnitario
                              );
                        sacarColaDin(&col,&pedAcum,sizeof(tPedidos));
                        fwrite(&pedAcum,sizeof(tPedidos),1,archPedOk);//cubre
                    }
                }
                ++cantCoinc;
            }
            else
            {
                while(!colaVaciaDin(&col))
                {

                    verPrimeroColaDin(&col,&ped,sizeof(tPedidos));
                    printf("-%*.*s  %li %d  %.2f\n",
                           (int)sizeof(ped.idCliente)-1,
                           (int)sizeof(ped.idCliente)-1,
                           ped.idCliente,
                           ped.idProd,
                           ped.cantPed,
                           ped.precUnitario
                          );
                    sacarColaDin(&col,&pedAcum,sizeof(tPedidos));
                    fwrite(&pedAcum,sizeof(tPedidos),1,archClDesc);//si te hice un pedido y no lo pagué, error

                }
            }
        }

        fseek(archPed,posOrigPed,SEEK_SET);
        fseek(archPag,posOrigPag,SEEK_SET);
    }

    return cantCoinc;
}

int estatusEncontrado(FILE *archPag,tPedidos *ped,tPagos * pag)
{
    while(!feof(archPag))
    {
        if(!strcmp(pag->idCliente,ped->idCliente))
        {
            return 1;
        }
        fread(pag,sizeof(tPagos),1,archPag);
    }

    return 0;
}
