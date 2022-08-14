#include "excepcionValorNegativoException.h"

const char * excepcionValorNegativoException::what() const throw()
{
    return "NO SE PUEDE TENER UN VALOR NEGATIVO EN LOS ATRIBUTOS";
}
