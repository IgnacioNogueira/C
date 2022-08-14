#include "cadena.h"
#include "string.h"
#define tam 100

int main()
{
    printf("\nNormalizar Cadena:\n");
    char alumno[tam] = {" ,    jU###?=?221An     ,,     pE1!l22otaS  , "};

    printf("\n1-nombre:%s",alumno);

    sacarCaracteresYnum(alumno);
    printf("\n2- nombre:%s",alumno);

    eliminarEspacioPrincipioFin(alumno);
    printf("\n3 - nombre:%s",alumno);

    moverEspacios(alumno);
    printf("\n4 - nombre:%s",alumno);

    comaNombre(alumno);
    printf("\n5 - nombre:%s",alumno);

    CamelCase(alumno);
    printf("\n6 - nombre:%s",alumno);


    return 0;
}
