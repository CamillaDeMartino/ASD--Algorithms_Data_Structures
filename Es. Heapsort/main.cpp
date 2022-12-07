/*
    • Aggiungere il metodo heapsort alla classe Heap
*/

#include "Heapsort.h"
#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<int> tree{30, 25, 20, 3, 2, 4};
    Heapsort<int> t = Heapsort<int>(tree);
    t.printArray();
    
    t.heapSort();
    cout<<"Albero ordinato";
    t.printArray();
    return 0;
}