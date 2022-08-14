#include "EdadEmpleadoInvalidaException.h"

const char * EdadEmpleadoInvalidaException:: what() const throw()
{
    return "El empleado debe tener una edad entre 18 y 65 inclusive";
}
