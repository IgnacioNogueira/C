#include "OperacionInvalidaException.h"

const char* OperacionInvalidaException::what() const throw()
{
    return "ERROR: Operacion invalida";
}
