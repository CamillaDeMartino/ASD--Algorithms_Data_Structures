#ifndef MANAGER_H
#define MANAGER_H
#include <iostream>
#include "Impiegato.h"

using namespace std;

class Manager:public Impiegato
{
private:
    
    float bonus;

public:
    Manager(float , string , float);

    float getSalario();
    void printInfo();

};

Manager::Manager(float b, string n, float s):Impiegato(n,s), bonus(b){

}


float Manager::getSalario()
{
    return (Impiegato::getSalario()+bonus);
}

void Manager::printInfo()
{
    cout<<"Il manager e': "<<this->getNome()<<endl<<"Il salario con bonus: "<<this->getSalario()<<endl;
}




#endif