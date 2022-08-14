#include "exceptionLlamada.h"

const char * exceptionLlamada::what() const throw()
{
    return "No se puede realizar la operacion solicitada,no coinciden los numeros de origen";
}
