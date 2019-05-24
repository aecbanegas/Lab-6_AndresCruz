#include "Chasis.h"

Chasis::Chasis(string Ruedas,bool Automatico){
    ruedas=Ruedas;
    automatico=Automatico;
}
bool Chasis::isAutomatico(){
    return automatico;
}
string Chasis::getRuedas(){
    return ruedas;
}