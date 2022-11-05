/*
    Implementare:
    - Counting Sort di Ferone
    - Counting Sort del Cormen
    - Counting Sort reverse
*/


#include "CountingSort.h"
#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector <int> A = {2, 5, 3, 0, 2, 3, 0, 3};
    CountingSort::countingSortF(&A);

    cout<<"Versione di Ferone"<<endl;
    for (auto i : A)
     cout << i << " ";  
    cout << endl;

    vector <int> B = {2, 5, 3, 0, 2, 3, 0, 3};
    CountingSort::reverseF(&B);

    cout<<"Reverse Ferone"<<endl;
    for (auto i : B)
     cout << i << " ";  
    cout << endl;


    vector <int> A1 = {2, 5, 3, 0, 2, 3, 0, 3};
    vector <int> B1(A1.size());
    CountingSort::countingSortC(&A1, &B1);

    cout<<"Versione Cormen"<<endl;
    for (auto i : B1)
     cout << i << " ";  
    cout << endl;



    return 0;
}