/*
    Progettare ed implementare un programma che utilizzando una Map, conti il
    numero di occorrenze di ogni parola contenuta in un file

*/

#include <iostream>
#include "Map.h"

using namespace std;

int main()
{
    string m = "file.txt";

    Map sol(m);
    sol.occorrenze();
      
    return 0;
}