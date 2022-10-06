/*
La blockchain è una struttura dati composta da una lista di
blocchi all'interno dei quali è memorizzato un insieme di
transazioni. Una transazione è costituita da un indirizzo
FROM, un indirizzo TO ed un valore intero QT.
- 1. Progettare ed implementare una struttura dati
     LinkedList mediante template ed utilizzarla per
     realizzare una blockchain
 -2. Dato un indirizzo A, stampare a video/salvare su file
     tutte le transazioni in cui compare A ed il suo bilancio finale
*/

#include <iostream>
#include <string>
#include "Transazione.h"
#include "Lista.h"
#include "Blocco.h"

using namespace std;

int main(){

    string address;
    int tot = 0; 

    Lista<Blocco> *blockchain = new Lista<Blocco>();
    Blocco *blocco1 = new Blocco(1);
    Blocco *blocco2 = new Blocco(2);
    //Blocco *blocco3 = new Blocco(3);

    blocco1->insTrans(2);
    blocco2->insTrans(3);
    //blocco3->insTrans();

    blockchain->Inserimento(blocco1);
    blockchain->Inserimento(blocco2);
    //blockchain->Inserimento(blocco3);

    Nodo<Blocco> *stamp = blockchain ->getTesta();

    cout<<"Inserisci l'indirizzo: "<<endl;
    cin>>address;

    while( stamp != nullptr)
    {
        int balance = 0;
        cout<<"Blocco n. "<< stamp->getInfo()->getId()<<endl;
        balance += stamp->getInfo()->getBloccoT(address);

        cout<<"Bilancio per questo blocco = " << balance << endl;

        stamp = stamp ->getNext();
    }

    
    return 0;
}