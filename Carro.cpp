#include "Carro.h"

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
