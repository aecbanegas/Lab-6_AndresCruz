#ifndef CARRO_H
#define CARRO_H
#include "Chasis.h"
#include "Motor.h"
#include "Pintura.h"
#include <string>
using std::string;
class Carro{
    private:
        string modelo;
        int num;
        Chasis* chasis;
        Pintura* pintura;
        Motor* motor;
    public:
        string getModelo();
        int getNum();
        void setNum(int);
        Chasis* getChasis();
        void setChasis(Chasis*);
        Pintura* getPintura();
        void setPintura(Pintura*);
        Motor* getMotor();
        void setMotor(Motor*);
        Carro(string);

};
#endif