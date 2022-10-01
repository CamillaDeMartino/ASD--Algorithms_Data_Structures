/*  • Classe Contenitore
    – Generico contenitore d'acqua: ha un attributo qt che memorizza
        la quantità d'acqua, un metodo versa(lt) per versare acqua, un
        metodo togli(lt) per togliere acqua ed un metodo getQt() che
        restituisce il valore di qt.

*/

#ifndef Contenitore_h
#define Contenitore_h
#include <iostream>

class Contenitore{

    private:
        int qt;
    
    public:
        Contenitore(int qt);
        //~Contenitore();

        void versa(int lt);
        void togli(int lt);

        void setqt(int qt) {this-> qt = qt;}
        int getqt(){return qt;}
};

Contenitore :: Contenitore(int qt)
{
    this->qt = qt;

}

void Contenitore :: versa(int lt)
{
    this->qt = qt + lt;

}

void Contenitore :: togli(int lt)
{
    this->qt = qt - lt;
} 

#endif