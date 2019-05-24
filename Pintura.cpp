#include "Pintura.h"

string Pintura::getColor(){
    return color;
}
string Pintura::getAcabado(){
    return acabado;
}
Pintura::Pintura(string Color,string Acabado){
    color=Color;
    acabado=Acabado;
}