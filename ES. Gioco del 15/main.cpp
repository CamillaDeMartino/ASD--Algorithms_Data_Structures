/*
    Il gioco del 15 consiste nel disporre le celle da 1 a 15 per riga in una matrice
    4x4. Avendo a disposizione una sola cella vuota, è possibile spostare solo le
    celle adiacianti alla cella vuota, in orizzontale ed in verticale.

    Progettare ed implementare un programma che legga da file una
    configurazione del gioco e verifichi se rappresenta la soluzione, usando un
    contenitore della STL.
*/


#include <iostream>
#include "Soluzione.h"

using namespace std;

int main()
{
    string m = "matrice.txt";

    Soluzione sol(m);
    sol.check();
      
    return 0;
}