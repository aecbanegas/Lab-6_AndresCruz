#include "Carro.h"
#include <sstream>
using std::stringstream;
Carro::Carro(string Modelo){
    modelo=Modelo;
    num=0;
    chasis=NULL;
    pintura=NULL;
    motor=NULL;
}
string Carro::getModelo(){
    return modelo;
}
int Carro::getNum(){
    return num;
}
void Carro::setNum(int numero){
    num=numero;
}
Chasis* Carro::getChasis(){
    return chasis;
}
void Carro::setChasis(Chasis* chasis1){
    chasis=chasis1;
}
Pintura* Carro::getPintura(){
    return pintura;
}
void Carro::setPintura(Pintura* pintura1){
    pintura=pintura1;
}
Motor* Carro::getMotor(){
    return motor;
}
void Carro::setMotor(Motor* motor1){
    motor=motor1;
}
string Carro::toString(){
    stringstream imprimir;
    imprimir<<"Modelo: "<<modelo<<num;
    if(chasis!=NULL){
        if(chasis->isAutomatico()){
            imprimir<<" Automatico:Si "<<"Tipo de ruedas:"<<chasis->getRuedas()<<" ";
        }else{
            imprimir<<" Automatico:No "<<"Tipo de ruedas:"<<chasis->getRuedas();
        }
    }
    if(motor!=NULL){
        if(motor->isElectrico()){
            imprimir<<" Electrico:Si"<<" Configuracion:"<<motor->getConfiguracion();
        }else{
            imprimir<<" Electrico:No"<<" Configuracion:"<<motor->getConfiguracion();
        }
    }
    if(pintura!=NULL){
        imprimir<<" Color:"<<pintura->getColor()<<" Acabado:"<<pintura->getAcabado();
    }
    string retorna=imprimir.str();
    return retorna;
}