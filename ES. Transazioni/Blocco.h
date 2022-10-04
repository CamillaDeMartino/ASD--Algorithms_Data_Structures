#ifndef BLOCCO_H
#define BLOCCO_H
#include <iostream>
#include "Lista.h"
#include "Transazione.h"

using namespace std;

class Blocco
{
private:
    Lista<Transazione> *listTrans;
public:
    Blocco( Lista<Transazione> *);
    //~Blocco();

    void setListTrans(Lista<Transazione> *);
    void setTrans();
    void printBlocco();



};

Blocco::Blocco(Lista<Transazione> *ls)
{
    listTrans = ls;
}

/* Blocco::~Blocco()
{
}
*/

void Blocco::setListTrans(Lista<Transazione> *ls)
{
    listTrans = ls;
}

void Blocco::setTrans()
{
    
}


#endif