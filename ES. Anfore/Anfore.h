/*
• Classe Anfora
    – È un Contenitore: ha un attributo capacita che definisce la
    capienza dell'anfora, un metodo getCapacita() che restituisce
    questo valore, un metodo riempi() per riempirla, un metodo
    svuota() per svuotarla, due metodi isVuota() e isPiena() che
    restituiscono lo stato dell'anfora ed un metodo
    spostaContenuto(Anfora) che sposta l'acqua nell'anfora
    passata come argomento.
*/

#ifndef ANFORA_H
#define ANFORA_H
#include <iostream>
#include "Contenitore.h"

class Anfora : public Contenitore{

    private:
        int const capacita;

        bool isPiena();
        bool isVuota();
    
    public:
        Anfora(int capacita, int qt);
        //virtual ~Anfora();

        int getCapacita() {return this->capacita;}
        void riempi();
        void svuota();
        void spostaContenuto(Anfora &a);
};



Anfora :: Anfora(int capacita, int qt) : Contenitore(qt), capacita(capacita){

}

void Anfora :: riempi(){
    this->versa(this->capacita - this->getqt());
}

void Anfora :: svuota(){
    this->togli(this->getqt());
}

bool Anfora :: isPiena(){

    if(this -> getqt() == this -> getCapacita())
        return true;
    else
        return false;

}


bool Anfora :: isVuota(){

    if(this->getqt() == 0)
        return true;
    else
        return false;
}


void Anfora :: spostaContenuto(Anfora &a){

    if(this->getqt() > a.getCapacita() - a.getqt())
    {
        this->togli(a.getCapacita() - a.getqt());
        a.versa(a.getCapacita() - a.getqt());
    }

    else if(this->getqt() <= a.getCapacita() - a.getqt())
    {
        a.versa(this->getqt());
        this->togli(this->getqt());
    }

}


#endif


