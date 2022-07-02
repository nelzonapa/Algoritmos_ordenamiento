#include "ELIPSE.h"

ELIPSE::ELIPSE(string _color, string _nombre_figura, float _rad_mayor,float _rad_menor):FORMA(_color, _nombre_figura){
    R=_rad_mayor;
    r=_rad_menor;
}

ELIPSE::~ELIPSE(){}

void ELIPSE::area(){
    float area;
    area=(3.1416)*(R*r);
    cout<<"\tEl area de su figura es: "<<area<<endl;
}
void ELIPSE::imprimir(){
    FORMA::imprimir();
}
float ELIPSE::get_area(){
    float area;
    area=(3.1416)*(R*r);
    return area;//devuelve el area
}