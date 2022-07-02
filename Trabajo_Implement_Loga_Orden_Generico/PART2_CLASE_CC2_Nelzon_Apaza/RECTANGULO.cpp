#include "RECTANGULO.h"
#include "FORMA.h"

RECTANGULO::RECTANGULO(string _color, string _nombre_figura, float _menor, float _mayor):FORMA(_color,_nombre_figura){
    lado_menor=_menor;
    lado_mayor=_mayor;
}
RECTANGULO::~RECTANGULO(){}

void RECTANGULO::imprimir(){
    int opcion;
    FORMA::imprimir();//USAMOS LA FUNCION IMPRIMIR de la clase FORMA (Virtual)
    cout<<"\tSus lados son los siguientes: "<<endl;
    cout<<"\tLado menor: "<<lado_menor<<endl;
    cout<<"\tLado mayor: "<<lado_mayor<<endl;
    perimetro();
}

void RECTANGULO::area(){
    float area;
    area=lado_menor*lado_mayor;
    cout<<"\tEl area de su figura es: "<<area<<endl;
}

void RECTANGULO::perimetro(){
    float perimetro;
    perimetro=2*lado_menor + 2*lado_mayor;
    cout<<"\tEl perimetro de su figura es: "<<perimetro<<endl;
}

float RECTANGULO::get_area(){//devuelve el area
    float area;
    area=lado_menor*lado_mayor;
    return area;
}