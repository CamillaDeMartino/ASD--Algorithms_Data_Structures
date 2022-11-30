/* • Individuare il minimo numero di operazioni di editing tra due sequenze
    – S = ATCTGAT
    – T = TGCATA

    RICORDA... vogliamo minimizzare il numero di operazioni di editing è:
             
                 |  delta(S[i],T[j]) + d(i-1, j-1) |        0 + ... se T[i]=S[i]    1 + ... se T[i] != S[j] 
    d(i,j) = min |  1 + d(i-1, j)                  |        cancellazione da  S[i]
                 |  1 + d(i, j-1)                  |        inserimento in T[j]


    delta(S[i], T[j]) = 1 se S[i] != T[j]  caratteri diversi
    delta(S[i], T[j]) = 0 se S[i] = T[j]   caratteri uguali

    sx =  add
    up =  delete
    diag = sost o corrispondenza
*/

#include <iostream>
#include <iomanip>
#include <string.h>
#include "Casella.h"

using namespace std;

int delta(char Si, char Ti)
{
    return (Si == Ti) ? 0 : 1; 
}


int main(){

    Casella matrix[8][7];
    int i, j;
    
    string S = "ATCTGAT";
    string T = "TGCATA";

    matrix[0][0].setValue(0);

    //prima riga
    i = 0;
    for(j = 1; j < 7; j++)
    {
        matrix[i][j].setValue(j);
        matrix[i][j].setDirection(Direction::LEFT);
    }

    //prima colonna
    j = 0;
    for(i = 1; i < 8; i++)
    {
        matrix[i][j].setValue(i);
        matrix[i][j].setDirection(Direction::UP);
    }

    //valori intermedi
    for(i = 1; i < 8; i++)
    {
        for(j = 1; j < 7; j++)
        {
            int a = delta(S[i-1], T[j-1]) + matrix[i-1][j-1].getValue();
            int b = 1 + matrix[i-1][j].getValue();
            int c = 1 + matrix[i][j-1].getValue();

            int m = a;                          //è il minimo 
            Direction dir = Direction::DIAG;

            if(b < m )
            {
                m = b;
                dir = Direction::UP;
            }
            if(c < m)
            {
                m = c;
                dir = Direction::LEFT;
            }

            matrix[i][j].setValue(m);
            matrix[i][j].setDirection(dir);
        }
    }

    //stampa matrice
    for(i = 0; i < 8; i++){
        for(j = 0; j < 7; j++){
            cout<<setw(7)<<matrix[i][j].getValue()<<" ("<<matrix[i][j].getDirection()<<")";
        }
        cout<<endl;
    }


    //stampa percorso
    Direction d;
    i = 7;
    j = 6;
    cout<< i <<" "<< j <<endl;
    while(i != 0 || j !=0){
        d = matrix[i][j].getDirection();
        switch (d)
        {
        case Direction::UP:
            i--;
            cout<<"Cancellazione"<<endl;
            break;
        case Direction::LEFT:
            j--;
            cout<<"Inserimento"<<endl;
            break;
        case Direction::DIAG:
            i--;
            j--;
            cout<<"Sostituzione o Corrispondenza"<<endl;
            break;
        default:
            break;
        }
        cout<<i<< " "<<j<<endl;
    }

    return 0;
}