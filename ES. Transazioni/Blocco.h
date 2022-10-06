#ifndef BLOCCO_H
#define BLOCCO_H
#include <iostream>
#include <string>
#include "Lista.h"
#include "Transazione.h"

using namespace std;

class Blocco
{
private:  
    int id;
    Lista<Transazione> *listTrans;
public:
    Blocco(int);
    //~Blocco();

    void insTrans(int );
    int getBloccoT(string );

    int getId(){return id;}
};

Blocco::Blocco(int i)
{
    id = i;
    listTrans = new Lista<Transazione>;
}

/* Blocco::~Blocco()
{
}
*/

void Blocco::insTrans(int ntrans)
{
    string FROM;
    string TO;
    int QT;

    for(int i = 1; i <= ntrans; i++)
    {
        cout<<"Inserisci la transazione n. "<< i << " per il blocco n. "<<getId()<<endl;

        cout<< "Inserisci From: ";
        cin>>FROM;
        cout<<endl;

        cout<< "Inserisci To: ";
        cin>>TO;
        cout<<endl;

        cout<< "Inserisci Qt: ";
        cin>>QT;
        cout<<endl;

    Transazione *temp = new Transazione(FROM, TO, QT);
    listTrans->Inserimento(temp);
    }
}


int Blocco::getBloccoT(string indirizzo )
{
    Nodo<Transazione> *temp = listTrans->getTesta();
    int tot = 0;

    while(temp != nullptr)
    {
        if(indirizzo == temp->getInfo()->getFrom())
        {
            temp->getInfo()->printTransazione();
            tot -= temp->getInfo()->getQt();
        }
        else if(indirizzo == temp->getInfo()->getTo())
        {
            temp->getInfo()->printTransazione();
            tot += temp->getInfo()->getQt();
        }

        temp = temp->getNext();
    }

    return tot;
}

#endif