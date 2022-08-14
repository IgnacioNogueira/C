#ifndef CLASEA_H
#define CLASEA_H

#include "ClaseBase.h"


class ClaseA : public ClaseBase {
public:
    ClaseA(int valor1 = 0) : ClaseBase(valor1) {};

    virtual ~ClaseA() {
        std::cout << "Destructor clase A\n";
    };
};

#endif // CLASEA_H
