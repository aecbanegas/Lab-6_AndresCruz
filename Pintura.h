#ifndef PINTURA_H
#define PINTURA_H
#include <string>
using std::string;
class Pintura{
    private:
        string acabado;
        string color;
    public:
        string getColor();
        string getAcabado();
        Pintura(string,string);
};
#endif