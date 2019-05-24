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
    vector<Chasis*> chasiss;
    vector<Motor*> motores;
    int opcm=0,cont=1;
    Carro*** linea=crearMatriz();//matriz de linea de produccion
    char** matriz=new char*[5];//matriz que se muestra a usuario
    for (int i = 0; i < 5; i++){//crear matriz que se muestra a usuario
        matriz[i]=new char[4];
    }
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
            if(cont!=6){
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
                pinturas.push_back(pintura);
                motores.push_back(motor);
                chasiss.push_back(chasis);
                linea[cont-1][0]=prototipo;
                cont++;
            }else{
                cout<<"El limite de prototipos para la linea de produccion fue alcanzado!!!"<<endl;
            }//end if 5 vehiculos
        }//end if opc1
        if (opcm==2){//muestra la matriz
            for (int i = 0; i < 5; i++){
                for (int j = 0; j < 4; j++){
                    if(linea[i][j]!=NULL&&j==0){
                        matriz[i][j]='P';
                    }else if(linea[i][j]!=NULL&&j!=0){
                        matriz[i][j]='C';
                    }else{
                        matriz[i][j]=' ';
                    }
                    cout<<"["<<matriz[i][j]<<"] ";
                }
                cout<<endl;
            }
        }
        if(opcm==3){
            for (int i = 0; i < 5; i++){
                for (int j = 1; j < 4; j++){
                    if(linea[i][j]!=NULL){
                        cout<<"Carro: "<<linea[i][j]->toString()<<endl;
                    }
                }
            }//fin for            
        }//fin if
        if(opcm==4){
            for (int i = 0; i < producidos.size(); i++){
                cout<<"Carro Terminado: "<<producidos[i]->toString()<<endl;
            }
        }
        if(opcm==5){
            for (int i = 0; i < 5; i++){
                if(linea[i][0]!=NULL){
                    for (int j = 3; j >=0; j--){
                        if(j==3){
                            if(linea[i][j]!=NULL){
                                producidos.push_back(linea[i][j]);
                            }
                        }
                        if(j==2){
                            linea[i][j+1]=linea[i][j];
                            if(linea[i][j+1]!=NULL){
                                linea[i][j+1]->setPintura(pinturas[i]);
                            }
                        }
                        if(j==1){
                            linea[i][j+1]=linea[i][j];
                            if(linea[i][j+1]!=NULL){
                                linea[i][j+1]->setMotor(motores[i]);
                            }
                        }
                        if(j==0){
                            linea[i][j+1]=new Carro(linea[i][0]->getModelo());
                            linea[i][j+1]->setNum(linea[i][0]->getNum());
                            linea[i][0]->setNum((linea[i][0]->getNum()+1));
                            linea[i][j+1]->setChasis(chasiss[i]);
                        }
                    }//fin for
                }//fin if
            }//fin for
        }
    }//fin while menu
    for (int i = 0; i < pinturas.size(); i++){//liberar vectores de prototipos
        delete chasiss[i];
        delete motores[i];
        delete pinturas[i];
    }
    for (int i = 0; i < producidos.size(); i++){//liberar producidos
        delete producidos[i];
    }
    for (int i = 0; i < 5; i++){//borrar matriz que se muestra a usuario
        delete[] matriz[i];
    }
    delete[] matriz;
    liberarMatriz(linea);
    return 0;
}
Carro*** crearMatriz(){//crear matriz
    Carro*** matriz=new Carro**[5];
    for (int i = 0; i < 5; i++){
        matriz[i]=new Carro*[4];
        for (int j = 0; j < 4; j++){
            matriz[i][j]=NULL;
        }        
    }
    return matriz;
}
void liberarMatriz(Carro*** matriz){//liberar matriz
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
