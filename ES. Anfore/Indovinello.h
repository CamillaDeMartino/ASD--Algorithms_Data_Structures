/*
• Classe Indovinello
     – Risolve l'indovinello: ha due attributi anfora una da 3 lt ed una
     da 5 lt ed un metodo risolvi() che risolve l'indovinello mostrando
    a video il contenuto delle due anfore ad ogni passo della
     risoluzione.

*/

#ifndef INDOVINELLO_H
#define INDOVINELLO_H
#include <iostream>
#include "Anfore.h"


using namespace std;

class Indovinello{

    private:
        Anfora Tre, Cinque;

        void printInfo();
    
    public:

        Indovinello();
        //~Indovinello();

        void risolvi();
};

Indovinello :: Indovinello():Tre(3,0), Cinque(5,0){

}



void Indovinello ::risolvi(){

    cout << "\n***1- Riempi l'Anfora da 5 litri***" << endl;
    Cinque.riempi();

    printInfo();

    cout << "***2- Svuota Anfora da 5 in quella da 3***" << endl;
    Cinque.spostaContenuto(Tre);

    printInfo();
    
    cout << "***3- Svuota l'Anfora da 3 litri***" << endl;
    Tre.svuota();

    printInfo();

    cout << "***4- Metti i due litri rimanenti dell'Anfora da 5 in quella da 3***" << endl;
    Cinque.spostaContenuto(Tre);

    printInfo();

    cout << "***5- Riempi l'Anfora da 5***" << endl;
    Cinque.riempi();

    printInfo();

    cout << "***6- Sposta il conenuto dell'Anfora di 5 in quella da tre***" << endl;
    Cinque.spostaContenuto(Tre);

    printInfo();

    cout << "Fine... Indovinello risolto!" << endl;
}

void Indovinello::printInfo(){
    cout << "Nell'Anfora Cinque ci sono " << Cinque.getqt() << " litri" << endl;
    cout << "Nell'Anfora Tre ci sono " << Tre.getqt() << " litri" << endl << endl;
}
#endif