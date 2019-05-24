#include "Motor.h"

bool Motor::isElectrico(){
    return electrico;
}
string Motor::getConfiguracion(){
    return configuracion;
}
Motor::Motor(bool Electrico,string Configuracion){
    electrico=electrico;
    configuracion=configuracion;
}