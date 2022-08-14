#include "archivo.h"

int crearArchivoMae(char * nombreBinario)
{
    FILE * fpb = fopen(nombreBinario,"wb");

    tProducto prod[] =
    {
        {'A',"Dulce de leche",20,50.85},
        {'B',"Manteca",30,20.45},
        {'C',"Queso",50,120.85}
    };

    if(fpb)
    {
        fwrite(&prod,sizeof(prod),1,fpb);
        fclose(fpb);
        return OK;
    }

    return -1;
}

int crearArchivoMaeDes(char * nombreBinario)
{
    FILE * fpb = fopen(nombreBinario,"wb");

    tProducto prod[] =
    {
        {'H',"Budin",44,100.02},
        {'B',"Manteca",30,20.45},
        {'A',"Dulce de leche",20,50.85},
        {'C',"Queso",50,120.85}

    };

    if(fpb)
    {
        fwrite(&prod,sizeof(prod),1,fpb);
        fclose(fpb);
        return OK;
    }

    return -1;
}


int crearArchivoBin(char * nombreBinario)
{
    FILE * fpb = fopen(nombreBinario,"wb");

    if(fpb)
    {
        fclose(fpb);
        return OK;
    }

    return -2;
}


int crearArchivoTxt(char * nombreTxt)
{
    FILE * fpt = fopen(nombreTxt,"wt");

    if(fpt)
    {
        fclose(fpt);
        return OK;
    }

    return -3;
}

int abrirArchivo(FILE **fp,const char * nombreArchivo,const char * modoApertura,int mostrarError)
{
    *fp = fopen(nombreArchivo,modoApertura);

    if(*fp == NULL)
    {
        if(mostrarError == 1)
        {
            fprintf(stderr,"No se pudo abrir el archivo %s en el modo %s",nombreArchivo,modoApertura);
        }
        return -4;
    }

    return OK;
}

int leerYmostrarArchivoMast(const char * nombreArchivoMaes)
{
    tProducto prod;

    FILE *fpm = fopen(nombreArchivoMaes,"rb");

    if(!fpm)
    {
        printf("\nNo se puede abrir el archivo %s",nombreArchivoMaes);
        return -5;
    }

    fread(&prod,sizeof(tProducto),1,fpm);

    while(!feof(fpm))
    {
        mostrarMaesBin(&prod);
        fread(&prod,sizeof(tProducto),1,fpm);
    }

    fclose(fpm);
    return OK;
}

//Longitud variable
void mostrarMaesBin(tProducto * prod)
{
    if(!prod)
    {
        printf("\nNo hay productos que mostrar");
        return;
    }

    printf("-%li %-*.*s %02d/%02d/%02d %d %8.2f\n",
           prod->codProd,
           (int)sizeof(prod->descrip)-1,
           (int)sizeof(prod->descrip)-1,
           prod->descrip,
           prod->fecUltAct.dia,
           prod->fecUltAct.mes,
           prod->fecUltAct.anio,
           prod->cantidad,
           prod->precioUnitario
           );
}


int leerYmostrarArchivoNov(char * nombreArchNov) //como no lo abro, no lo cierro (Lo hago en una función anterior)
{
    tNovedades nov;
    char linea[100];

    FILE * fpn = fopen(nombreArchNov,"rt");

    if(!fpn)
    {
        printf("\nNo se encuentra el archivo %s\n",nombreArchNov);
        return -6;
    }

    while(fgets(linea,sizeof(linea),fpn))
    {
        trozarArchivoLV(&nov,linea);
        mostrarNovTxt(&nov);

    }
    fclose(fpn);
    return OK;
}

void mostrarNovTxt(const tNovedades * nov)
{
    if(!nov)
    {
        printf("\nNo hay novedades que mostrar");
        return;
    }

    printf("-%li  %c  %d\n",nov->codProd,
           nov->tipoOp,
           nov->cantidad
          );
}

void trozarArchivoLV(tNovedades * nov,char *linea)
{
    char *aux = strchr(linea,'\n');
    *aux = '\0';

    aux = strrchr(linea,';');
    sscanf(aux+1,"%c",&nov->tipoOp);
    *aux = '\0';

    aux = strrchr(linea,';');
    sscanf(aux+1,"%d",&nov->cantidad);
    *aux = '\0';

    sscanf(linea,"%c",&nov->codProd);
}

void trozarArchivoLF(tNovedades * nov,char *linea)
{
    char *aux = linea + TAM_LINEA;
    *aux = '\0';

    aux -= TAM_OP;
    sscanf(aux,"%c",&nov->tipoOp);
    *aux = '\0';

    aux -= TAM_CANT;
    sscanf(aux,"%d",&nov->cantidad);
    *aux = '\0';

    aux -= TAM_CODPROD;
    sscanf(aux,"%c",&nov->codProd);
    *aux = '\0';
}

int actualizarMercaditoArchOrd(FILE * archMaster,FILE * archNov, FILE * sinStock, FILE * archErr)
{
    tProducto prod;
    tNovedades nov;
    long posOrigMast = ftell(archMaster);
    int cantAct = 0,i = 0;
    char linea[100];
    rewind(archMaster);
    rewind(archNov);

    if(fgets(linea,sizeof(linea),archNov))
    {
        trozarArchivoLV(&nov,linea);
        fread(&prod,sizeof(tProducto),1,archMaster); //inicialización para la primer pasada

        while(!feof(archMaster))
        {
            if(prod.codProd == nov.codProd)
            {
                if(aMayus(nov.tipoOp) == 'C')
                {
                    prod.cantidad+=nov.cantidad;
                    fseek(archMaster,-1L*(long)sizeof(tProducto),SEEK_CUR);
                    fwrite(&prod,sizeof(tProducto),1,archMaster);
                    fseek(archMaster,0L,SEEK_CUR);
                    ++cantAct;
                }
                else
                {
                    if(aMayus(nov.tipoOp) == 'V')
                    {
                        if(nov.cantidad > prod.cantidad)
                        {
                            fprintf(sinStock,"-Movimiento %d. El producto con ID:%c necesita reponerse. Cantidad solicitada:%d vs disponible:%d\n",i+1,prod.codProd,
                                    nov.cantidad,prod.cantidad); //guardo el producto sin stock -> no sé si está mal pasar ciertos datos, o tengo que pasar todo
                        }
                        else
                        {
                            prod.cantidad-=nov.cantidad;
                            fseek(archMaster,-1L*(long)sizeof(tProducto),SEEK_CUR);
                            fwrite(&prod,sizeof(tProducto),1,archMaster);
                            fseek(archMaster,0L,SEEK_CUR);
                            ++cantAct;
                        }
                    }
                }
            }

            ++i;
            fread(&prod,sizeof(tProducto),1,archMaster);

            if(!feof(archMaster) && fgets(linea,sizeof(linea),archNov))
            {
                trozarArchivoLV(&nov,linea);
            }

        }

        while(fgets(linea,sizeof(linea),archNov)) //esto por si quedan sueltos los de tNoved
        {
            trozarArchivoLV(&nov,linea);
            fwrite(&nov,sizeof(tNovedades),1,archErr);
            printf("\n\n-Error, codigo inexistente del archivo novedades:'%c'\n\n",nov.codProd);
        }

        fseek(archMaster,posOrigMast,SEEK_SET);
    }
    else
    {
        printf("\n\nEl archivo %s no tiene actualizaciones pendientes para hacer\n\n",NOMBRE_ARCHIVO_NOVEDADES);
        return 0;
    }

    return cantAct;
}

int estadoArchivo(FILE * archNov,tProducto *prod,tNovedades *nov,char *linea)
{
    while(fgets(linea,sizeof(linea),archNov))
    {
        trozarArchivoLV(&nov,linea);

        if(prod->codProd == nov->codProd)
        {
            return 1;
        }

        fread(prod,sizeof(tProducto),1,archMaster);
    }

    return 0;
}


int actualizarMercaditoArchDes(FILE * archMaster,FILE * archNov, FILE * sinStock, FILE * archErr)
{
    tProducto prod;
    tNovedades nov;
    long posOrigMast = ftell(archMaster);
    size_t cantAct = 0;
    int i = 0;
    char linea[100];
    rewind(archMaster);
    rewind(archNov);


    fread(&prod,sizeof(tProducto),1,archMaster); //inicialización para la primer pasada
    while(!feof(archMaster))
    {
        while(fgets(linea,sizeof(linea),archNov))
        {
            trozarArchivoLV(&nov,linea);

            if(prod.codProd == nov.codProd)
            {
                if(aMayus(nov.tipoOp) == 'C')
                {
                    prod.cantidad+=nov.cantidad;
                    fseek(archMaster,-1L*(long)sizeof(tProducto),SEEK_CUR);
                    fwrite(&prod,sizeof(tProducto),1,archMaster);
                    fseek(archMaster,0L,SEEK_CUR);
                    ++cantAct;
                }
                else
                {
                    if(aMayus(nov.tipoOp) == 'V')
                    {
                        if(nov.cantidad > prod.cantidad)
                        {
                            fprintf(sinStock,"-Movimiento %d. El producto con ID:%c necesita reponerse. Cantidad solicitada:%d vs disponible:%d\n",i+1,prod.codProd,
                                    nov.cantidad,prod.cantidad); //guardo el producto sin stock -> no sé si está mal pasar ciertos datos, o tengo que pasar todo
                        }
                        else
                        {
                            prod.cantidad-=nov.cantidad;
                            fseek(archMaster,-1L*(long)sizeof(tProducto),SEEK_CUR);
                            fwrite(&prod,sizeof(tProducto),1,archMaster);
                            fseek(archMaster,0L,SEEK_CUR);
                            ++cantAct;
                        }
                    }
                }
            }

            ++i;
        }

        rewind(archNov);
        fread(&prod,sizeof(tProducto),1,archMaster);
    }

    fseek(archMaster,posOrigMast,SEEK_SET);

    if(!i)
    {
        printf("\n\n-%s no tiene archivos que actualizar\n\n",NOMBRE_ARCHIVO_NOVEDADES);
        return 0;
    }

    return cantAct;
}

/*

int actualizarMercaditoArchDes(FILE * archMaster,FILE * archNov, FILE * sinStock, FILE * archErr)
{
    tProducto prod;
    tNovedades nov;
    long posOrigMast = ftell(archMaster);
    size_t cantAct = 0;
    int i = 0,enc;
    char linea[100];
    rewind(archMaster);
    rewind(archNov);

    fread(&prod,sizeof(tProducto),1,archMaster);
    while(fgets(linea,sizeof(linea),archNov))
    {
        trozarArchivoLV(&nov,linea);
        enc = estadoArchivo(archMaster,&prod,&nov); //retorno un estado

        if(!enc)
        {
            fwrite(&nov,sizeof(tNovedades),1,archErr);
        }
        else
        {
            if(aMayus(nov.tipoOp) == 'C')
            {
                prod.cantidad+=nov.cantidad;
                fseek(archMaster,-1L*(long)sizeof(tProducto),SEEK_CUR);
                fwrite(&prod,sizeof(tProducto),1,archMaster);
                fseek(archMaster,0L,SEEK_CUR);
                ++cantAct;
            }
            else
            {
                if(aMayus(nov.tipoOp) == 'V')
                {
                    if(nov.cantidad > prod.cantidad)
                    {
                        fprintf(sinStock,"-Movimiento %d. El producto con ID:%c necesita reponerse. Cantidad solicitada:%d vs disponible:%d\n",i+1,prod.codProd,
                                nov.cantidad,prod.cantidad); //guardo el producto sin stock -> no sé si está mal pasar ciertos datos, o tengo que pasar todo
                    }
                    else
                    {
                        prod.cantidad-=nov.cantidad;
                        fseek(archMaster,-1L*(long)sizeof(tProducto),SEEK_CUR);
                        fwrite(&prod,sizeof(tProducto),1,archMaster);
                        fseek(archMaster,0L,SEEK_CUR);
                        ++cantAct;
                    }
                }
            }

        }
        ++i;
        rewind(archMaster);
    }

    if(!i)
    {
        printf("\n\n-%s no tiene archivos que actualizar\n\n",NOMBRE_ARCHIVO_NOVEDADES);
        return 0;
    }

    fseek(archMaster,posOrigMast,SEEK_SET);
    return cantAct;
}
*/
int pasarTxtABin(char * nombreArchivoTxt,char * nombreArchivoBin,char tipo) //el bin es lo mismo pero al revés con fprintf
{
    /*
        tipo = aMayus(tipo);
        if(tipo != 'V' || tipo != 'F')
        {
            return NO;
        }
    */ //???????????????????????????
    FILE *fpt,*fpb;
    char linea[100];
    tNovedades nov;

    if(!abrirArchivo(&fpt,nombreArchivoTxt,"rt",1))
    {
        printf("\nNo se pudo abrir el archivo %s",nombreArchivoTxt);
        return -11;
    }

    fpb = fopen(nombreArchivoBin,"w+b");

    if(!fpb)
    {
        printf("\nNo se pudo crear el archivo %s",nombreArchivoBin);
        return -12;
    }

    if(aMayusc(tipo) == 'V')
    {
        while(fgets(linea,sizeof(linea),fpt))
        {
            trozarArchivoLV(&nov,linea);
            fwrite(&nov,sizeof(tNovedades),1,fpb);
        }
    }
    else
    {
        while(fgets(linea,sizeof(linea),fpt))
        {
            trozarArchivoLF(&nov,linea);
            fwrite(&nov,sizeof(tNovedades),1,fpb);
        }
    }

    fclose(fpt);
    fclose(fpb);
    return OK;
}

/*
int pasarBinATxt(char * nombreArchivoTxt,char * nombreArchivoBin,char tipo) //el bin es lo mismo pero al revés con fprintf
{

        if(aMayusc(tipo) != 'V' || aMayusc(tipo) != 'F')
        {
            return NO;
        }


    FILE *fpt,*fpb;
    char linea[100];
    tNovedades nov;

    if(!abrirArchivo(&fpt,nombreArchivoTxt,"rt",1))
    {
        printf("\nNo se pudo abrir el archivo %s",nombreArchivoTxt);
        return -11;
    }

    fpb = fopen(nombreArchivoBin,"w+b");

    if(!fpb)
    {
        printf("\nNo se pudo crear el archivo %s",nombreArchivoBin);
        return -12;
    }

    if(aMayusc(tipo) == 'V')
    {
        while(fgets(linea,sizeof(linea),fpt))
        {
            trozarArchivoLV(&nov,linea);
            fwrite(&nov,sizeof(tNovedades),1,fpb);
        }
    }
    else
    {
        while(fgets(linea,sizeof(linea),fpt))
        {
            trozarArchivoLF(&nov,linea);
            fwrite(&nov,sizeof(tNovedades),1,fpb);
        }
    }

    fclose(fpt);
    fclose(fpb);
    return OK;
}
*/
