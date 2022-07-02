#ifndef CUADRADO_H
#define CUADRADO_H
#include "RECTANGULO.h"

class CUADRADO:public RECTANGULO{
    public:
        CUADRADO(string,string, float, float);//solo usaremos los datos de RECTANGULO
        ~CUADRADO();
        void imprimir();
};

#endif