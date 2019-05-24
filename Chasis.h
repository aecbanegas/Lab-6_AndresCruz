#ifndef CHASIS_H
#define CHASIS_H
#include <string>
using std::string;
class Chasis{
    private:
        string ruedas;
        bool automatico;
    public:
        bool isAutomatico();
        string getRuedas();
        Chasis(string,bool);
};
#endif