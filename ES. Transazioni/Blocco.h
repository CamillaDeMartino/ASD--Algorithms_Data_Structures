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
    Blocco(Lista<Transazione> *, int);
    //~Blocco();

    void insTrans();
    int getBloccoT(string );
    int getId(){return id;}
};

Blocco::Blocco(Lista<Transazione> *ls, int i)
{
    id = i;
    listTrans = ls;
}

/* Blocco::~Blocco()
{
}
*/

void Blocco::insTrans()
{
    string FROM;
    string TO;
    int QT;

    Transazione *temp = new Transazione(FROM, TO, QT);

    cout<< "Inserisci From: "<<endl;
    cin>>FROM;

    cout<< "Inserisci To: "<<endl;
    cin>>TO;

    cout<< "Inserisci Qt: "<<endl;
    cin>>QT;

    listTrans->Inserimento(temp);
}


int Blocco::getBloccoT(string indirizzo )
{
    Nodo<Transazione> *temp = listTrans->getTesta();
    int tot = 0;

    while(temp != nullptr)
    {
        if(indirizzo == temp->getInfo()->getFrom())
        {
            //cout<<"From: "<< temp->getInfo()->getFrom()<<endl;

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