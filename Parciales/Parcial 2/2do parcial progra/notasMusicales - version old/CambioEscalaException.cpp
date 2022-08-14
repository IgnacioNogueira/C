#include "CambioEscalaException.h"

const char * CambioEscalaException::what() const throw()
{
    return "No permite cambio de escala";
}
