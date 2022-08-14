#ifndef CLASEB_H
#define CLASEB_H

#include "ClaseBase.h"

class ClaseB : public ClaseBase {
public:
    ClaseB(int valor1 = 0) : ClaseBase(valor1) {};

    virtual ~ClaseB() {
        std::cout << "Destructor clase B\n";
    };
};
#endif // CLASEB_H
