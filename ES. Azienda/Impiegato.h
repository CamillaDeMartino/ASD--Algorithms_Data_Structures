
#ifndef IMPIEGATO_H
#define IMPIEGATO_H
#include <iostream>
#include <string>

using namespace std;

class Impiegato
{
private:
    string nome;
    float salario;
public:
    Impiegato(string , float );

    void setNome(string);
    string getNome() {return nome;}

    void setSalario(float);
    virtual float getSalario() {return salario;}

    virtual void printInfo();

    Impiegato operator+(Impiegato );
};

Impiegato::Impiegato(string n, float s)
{
    nome = n;
    salario = s;
}


void Impiegato::setNome(string n)
{
    nome = n;
}

void Impiegato::setSalario(float s)
{
    salario = s;
}

void Impiegato::printInfo()
{
    cout<<"Nome impiegato: "<< nome <<endl<< "Salario: "<< salario <<endl;
}


Impiegato Impiegato::operator+(Impiegato a )
{
    Impiegato temp("", 0);
    
    temp.setSalario(this->getSalario() + a.getSalario());
    return temp;
}


#endif 