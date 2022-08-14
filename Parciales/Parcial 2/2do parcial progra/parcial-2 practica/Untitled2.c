void crearIndice(void *info1, const void *info2, unsigned pos)
{
    tIndice *ind = (tIndice *)info1;
    const tCuenta *cue = (tCuenta *)info2;

    ind->clave.nro = cue->nro;
    ind->clave.tipo = cue->tipo;
    ind->clave.secuencia = cue->secuencia;
    ind->indiceRegistro = pos;
}

int leerYasignarEstructura_MIOOOO(void **d,void *vfp,unsigned pos,void *params,void *params2)
{
    FILE *fp = (FILE *)vfp;
    unsigned tamRegArch = (*(unsigned *)params);
    unsigned tamInfoArbol = (*(unsigned *)params2);

    void *reg = malloc(tamRegArch);

    if(!reg)
    {
        return -1;
    }

    *d = malloc(tamInfoArbol);

    if(!*d)
    {
        free(reg);
        return -1;
    }

    fseek(fp,pos*tamRegArch,SEEK_SET);
    fread(fp,tamRegArch,1,SEEK_CUR);
    crearIndice(*d,reg,pos);

    return tamInfoArbol;

}

int cargarArchivoNovedadesEnLista_MIOaa(tArbol *p,void *setDato,
                                        void (*accion)(void **,void *,unsigned,void *,void*),
                                        int li,int ls,void *params,void *params2);

int cargarArchivoNovedadesEnLista_MIOaa(tArbol *p,void *setDato,
                                        void (*accion)(void **,void *,unsigned,void *,void*),
                                        int li,int ls,void *params,void *params2)


{

    int m = (li+ls)/2;
    int r;

    if(li > ls)
        return TODO_BIEN;

    (*p) = (tNodoArbol *)malloc(sizeof(tNodoArbol));

    if(!*p || !((*p)->tamInfo = accion(&(*p)->info,setDato,m,params,params2)))
    {
        free(*p);
        return ERROR_AR;
    }

    (*p)->izq = (*p)->der = NULL;

    if( (r = cargarArchivoNovedadesEnLista_MIOaa(&(*p)->izq,setDato,accion,m-1,ls,params,params2)) != TODO_BIEN)
        return r;

    return cargarArchivoNovedadesEnLista_MIOaa(&(*p)->der,setDato,accion,li,m+1,params,params2);
}


int cargarArchivoBinOrdenadoToArbol_MIO(tArbol *p,const char *nombreArchivo,unsigned tamInfoArbol,unsigned tamRegArch)
{
    int cantReg, r;

    FILE *fp = fopen(nombreArchivo,"rb");

    if(!fp)
        return -1;

    fseek(fp,0L,SEEK_END);
    cantReg = ftell(fp)/tamRegArch;
    r = cargarArchivoNovedadesEnLista_MIOaa(p,fp,leerYasignarEstructura,0,cantReg-1,&tamRegArch,&tamInfoArbol);
    fclose(fp);

    return r;
}

int indexarArchivoCuentas_MIO(char *nombreArchivoCuentas, tArbol *p)
{
    if(cargarArchivoBinOrdenadoToArbol_MIO(p,nombreArchivoCuentas,sizeof(tIndice),sizeof(tCuenta)) == TODO_BIEN)
       return TODO_BIEN;

    return -1;
}

