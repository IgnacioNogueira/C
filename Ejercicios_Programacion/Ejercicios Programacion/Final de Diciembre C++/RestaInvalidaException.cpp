#include "RestaInvalidaException.h"

const char* RestaInvalidaException::what() const throw()
{
    return "Error en la resta";
}
