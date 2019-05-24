#ifndef MOTOR_H
#define MOTOR_H
#include <string>
using std::string;
class Motor{
    private:
        bool electrico;
        string configuracion;
    public:
        bool isElectrico();
        string getConfiguracion();
        Motor(bool,string);
};
#endif