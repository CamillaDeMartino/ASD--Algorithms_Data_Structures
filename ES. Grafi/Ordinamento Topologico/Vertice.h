#ifndef VERTICE_H
#define VERTICE_H
#include <iostream>
#include <string> 

using namespace std;

enum class Color{
    BLACK, WHITE, GRAY
};


template<class T>
class Vertice
{
private:
    T value;
    Vertice<T> *predecessor;
    Color colore;

    int tempInizio;
    int tempFine;

public:
    Vertice(T);

    void setValue(T value){this->value = value;}
    void setPredecessor(Vertice<T> *predecessor){this->predecessor = predecessor;}
    void setColor(Color colore){this->colore = colore;}
    void setTempInzio(int tempInizo){this->tempInizio = tempInizio;}
    void setTempFine(int tempFine){this->tempFine = tempFine;}

    T getValue(){return value;}
    Vertice<T> *getPredecessor(){return predecessor;}
    Color getColor(){return colore;}
    int getTempInzio(){return tempInizio;}
    int getTempFine(){return tempFine;}


    friend ostream& operator<<(ostream& out, const Vertice<T> &obj)
    {
        string c;
        switch (obj.colore)
        {
        case Color::WHITE:
            c = "WHITE";
            break;
        case Color::GRAY:
            c = "GRAY";
            break;
        case Color::BLACK:
            c = "BLACK";
            break;
        default:
            break;
        }

        cout<<"Valore "<<obj.value<<" Colore: "<<c;
        return out;
    }


    friend bool operator== (const Vertice<T> &a, const Vertice<T> &b)
    {
        return a.value == b.value;
    }
};

template<class T> Vertice<T>::Vertice(T value)
{
    this->value = value;
    colore = Color::WHITE;
    predecessor = nullptr;
    tempInizio = 0;
    tempFine = 0;
}




#endif