/*
    • Utilizzando il paradigma della programmazione ad oggetti ed il linguaggio C++ 11, progettare ed
    implementare, come classe, una struttura dati max-heap che consenta di ordinare, mediante algoritmo heapsort,
    un insieme di valori numerici letti dal file heap.txt
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "HeapSort.h"

using namespace std;

int main(){

    string heap = "heap.txt";
    fstream myfile;
    string file;
    vector<float> vect;

    myfile.open(heap.c_str(), ios::in);

    while(getline(myfile, file))
        vect.push_back(stof(file));     //stof mi permette di convertire le stringhe in numeri
    

    for(auto i:vect)
        cout<<i<<endl;


    cout<<endl<<"***File ordinato***"<<endl;
    HeapSort<float> tree = HeapSort<float>(vect);
    tree.heapSort();
    tree.printArray();
    
    
    myfile.close();
    
    return 0;
}