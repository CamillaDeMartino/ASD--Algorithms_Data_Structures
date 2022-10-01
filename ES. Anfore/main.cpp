/*
    Esercizio: indovinello delle due anfore
        Si hanno due anfore, una può contenere al massimo 5 litri
        d’acqua, l’altra 3 litri. Si vuole misurare solo con l’ausilio
        delle due anfore la quantità di 4 litri d’acqua.
        • Classe Contenitore
            – Generico contenitore d'acqua: ha un attributo qt che memorizza
            la quantità d'acqua, un metodo versa(lt) per versare acqua, un
            metodo togli(lt) per togliere acqua ed un metodo getQt() che
            restituisce il valore di qt.
        • Classe Anfora
            – È un Contenitore: ha un attributo capacita che definisce la
            capienza dell'anfora, un metodo getCapacita() che restituisce
            questo valore, un metodo riempi() per riempirla, un metodo
            svuota() per svuotarla, due metodi isVuota() e isPiena() che
            restituiscono lo stato dell'anfora ed un metodo
            spostaContenuto(Anfora) che sposta l'acqua nell'anfora
            passata come argomento.
        Si hanno due anfore, una può contenere al massimo 5 litri
        d’acqua, l’altra 3 litri. Si vuole misurare solo con l’ausilio
        delle due anfore la quantità di 4 litri d’acqua.
        • Classe Indovinello
            – Risolve l'indovinello: ha due attributi anfora una da 3 lt ed una
            da 5 lt ed un metodo risolvi() che risolve l'indovinello mostrando
            a video il contenuto delle due anfore ad ogni passo della
            risoluzione.
            – Es.: Riempi anfora A: A=3 B=0
    Scrivere un main che mostri la soluzione dell'indovinello
*/


#include <iostream>c
#include "Indovinello.h"

using namespace std;

int main(){
    Indovinello a;
    a.risolvi();

    return 0;
}
