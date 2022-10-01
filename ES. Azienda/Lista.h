#ifndef LISTA_H
#define LISRA_H
#include <iostream>
#include "Nodo.h"
#include "Impiegato.h"

using namespace std;


class Lista
{
private:
    Nodo *testa;
    Nodo *coda;

public:
    Lista();
    ~Lista();

    void Inserimento(Impiegato *);
    void printList();

    Nodo *getTesta(){return testa;}
    Nodo *getcoda(){return coda;}

    bool isVuota();
    void sum();
};

Lista::Lista()
{
    testa = nullptr;
    coda = nullptr;
}

/*Lista::~Lista()
{

}*/

bool Lista::isVuota()
{
    if (this->testa == nullptr)
        return true;
    
    return false;
}

void Lista::Inserimento(Impiegato *imp)
{
    Nodo *newNodo = new Nodo(imp);

    if(!this->isVuota())
    {
        coda->setNext(newNodo);
        coda = newNodo;
    }
    else
    {
        testa = coda = newNodo;
    }
}

void Lista::printList()
{
     Nodo *pers = testa;

     while( pers != nullptr)
     {
        pers->getInfo()->printInfo();
        pers = pers->getNext();
        cout<<endl;
     }
}


void Lista::sum()
{
    Nodo *i = testa;
    Impiegato somma("",0);


    while( i != nullptr)
    {
       Impiegato temp("", i->getInfo()->getSalario());

        somma = somma +temp;
        i = i ->getNext();
    }

    cout << "La somma dei salari: "<<somma.getSalario()<<endl;
}


#endif 