/*
    • Si supponga di avere una scacchiera nxn, contenente in ogni casella un numero intero, su cui si può muovere una pedina. 
      Ogni volta che la pedina passa su una casella accumula il valore contenuto nella casella.
    
    • La pedina parte dall'ultima casella in basso a destra e deve raggiungere la prima casella in alto a sinistra potendosi muovere
     solo di una casella alla volta verso l'alto, verso sinistra o in diagonale (alto-sinistra)
    
    • Si vuole calcolare un percorso che massimizzi il valore accumulato dalla pedina
*/

#include <iomanip>
#include <iostream>
#include "Casella.h"
#define N 5
using namespace std;


int main(){

    int S[N][N] = {6, 7, 4, 7, 8,
                   7, 6, 1, 1, 4,
                   3, 5, 7, 8, 2,
                   2, 6, 7, 0, 2,
                   7, 3, 5, 6, 1};
    

    Casella S2[N][N];
    int i,j;    //i righe, j colonne
    int m;      //è il massimo dei sottoproblemi

    //azzerare
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++)
            S2[i][j].setValue(0);
    }

    //prima casella(6)
    S2[0][0].setValue(S[0][0]);
    
    //prima riga
    i = 0;
    for(j = 1; j < N; j++){
        S2[i][j].setValue(S2[i][j-1].getValue() + S[i][j]);
        S2[i][j].setDirection(Direction::LEFT);
    }

    //prima colonna
    j = 0;
    for(i = 1; i < N; i++){
        S2[i][j].setValue(S2[i-1][j].getValue() + S[i][j]);
        S2[i][j].setDirection(Direction::UP);
    }

    //valori intermedi
    Direction d;
    for(i = 1; i < N; i++){
        for(j = 1; j < N; j++){
            m = S2[i-1][j-1].getValue();     //imposto come massimo l'elemento in diagonale
            d = Direction::DIAG;

            if(S2[i-1][j].getValue() > m)    //se il massimo è l'elemento in alto (prima riga seconda colonna)
            {
                m = S2[i-1][j].getValue();
                d = Direction::UP;
            }

            if(S2[i][j-1].getValue() > m)   //se il massimo è l'elemento a sinistra (prima colonna seconda riga)
            {
                m = S2[i][j-1].getValue();
                Direction::LEFT;
            }

            S2[i][j].setValue(m + S[i][j]);
            S2[i][j].setDirection(d);
        }
    }

    //stampa matrice
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            cout<<setw(7)<<S2[i][j].getValue()<<" ("<<S2[i][j].getDirection()<<")";
        }
        cout<<endl;
    }


    //stampa percorso
    i = N-1;
    j = N-1;
    cout<< i <<" "<< j <<endl;
    while(i != 0 or j !=0){
        d = S2[i][j].getDirection();
        switch (d)
        {
        case Direction::UP:
            i--;
            break;
        case Direction::LEFT:
            j--;
            break;
        case Direction::DIAG:
            i--;
            j--;
            break;
        default:
            break;
        }
        cout<<i<< " "<<j<<endl;
    }

    return 0;
}