#include "Motor.h"
#include "Chasis.h"
#include "Carro.h"
#include "Pintura.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <vector>
using std::vector;
#include <string>
using std::string;
Carro*** crearMatriz();
void liberarMatriz(Carro***);
int main(){
    vector<Carro*> producidos;
    vector<Pintura*> pinturas;
    vector<Carro*> prototipos;
    vector<Chasis*> chasiss;
    vector<Motor*> motores;
    int opcm=0,cont=1;
    Carro*** linea=crearMatriz();
    while (opcm!=6){
        cout<<"         Menu"<<endl
            <<"1.Agregar una linea de produccion."<<endl
            <<"2.Ver matriz de lineas de produccion."<<endl
            <<"3.Ver lineas de produccion."<<endl
            <<"4.Ver listado de carros producidos."<<endl
            <<"5.Avanzar ciclo de linea de produccion."<<endl
            <<"6.Salir del Programa."<<endl
            <<"Ingrese una opcion:"<<endl;
        cin>>opcm;
        if (opcm==1){
            if(cont!=5){
                string modelo,ruedas,configuracion,acabado,color;
                int autom,elec;
                bool automatico,electrico;
                cout<<"Ingrese modelo de auto:"<<endl;
                cin>>modelo;
                Carro* prototipo=new Carro(modelo);
                cout<<"Ingrese el tipo de ruedas del vehiculo: "<<endl;
                cin>>ruedas;
                cout<<"Ingrese 1 si es automatico y otro numero si no lo es: "<<endl;
                cin>>autom;
                if (autom==1){
                    automatico=true;
                }else{
                    automatico=false;
                }
                Chasis* chasis=new Chasis(ruedas,automatico);
                cout<<"Ingrese la configuracion del motor: "<<endl;
                cin>>configuracion;
                cout<<"Ingrese 1 si es electrico y otro numero si no lo es: "<<endl;
                cin>>elec;
                if (elec==1){
                    electrico=true;
                }else{
                    electrico=false;
                }
                Motor* motor=new Motor(electrico,configuracion);
                cout<<"Ingrese el color de la pintura: "<<endl;
                cin>>color;
                cout<<"Ingrese el acabado de la pintura: "<<endl;
                cin>>acabado;
                Pintura* pintura=new Pintura(color,acabado);
                prototipos.push_back(prototipo);
                pinturas.push_back(pintura);
                motores.push_back(motor);
                chasiss.push_back(chasis);
                cont++;
            }//end if 5 vehiculos
        }//end if opc1
        
    }
    for (int i = 0; i < prototipos.size(); i++){//liberar vectores de prototipos
        delete chasiss[i];
        delete motores[i];
        delete pinturas[i];
        delete prototipos[i];
    }
    for (int i = 0; i < producidos.size(); i++){//liberar producidos
        delete producidos[i];
    }
    liberarMatriz(linea);
    return 0;
}
Carro*** crearMatriz(){
    Carro*** matriz=new Carro**[5];
    for (int i = 0; i < 5; i++){
        matriz[i]=new Carro*[4];
        for (int j = 0; j < 4; j++){
            matriz[i][j]=NULL;
        }        
    }
    return matriz;
}
void liberarMatriz(Carro*** matriz){
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 4; j++){
            if(matriz!=NULL){
                delete matriz[i][j];
            }
        }
        delete[] matriz[i];
    }
    delete[] matriz;
}
