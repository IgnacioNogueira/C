#ifndef SUMAINVALIDAEXCEPTION_H_INCLUDED
#define SUMAINVALIDAEXCEPTION_H_INCLUDED

#include <exception>

class RestaInvalidaException : public std::exception
{
    public:
        const char* what() const throw();
};

#endif // SUMAINVALIDAEXCEPTION_H_INCLUDED
