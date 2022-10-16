#include <iostream>
#include "MergeRicorsivo.h"

using namespace std;

int main(){

    int A[5] = {9,7,3,1,4};
    
    MergeRicorsivo<int>::mergeSort(A, 0, 4);

    //Stampa in output il vettore ordinato
    for(int idx = 0; idx < 4; idx++)
        cout<<"Elemento[" << idx << "] = "<<A[idx]<<endl;
    
    
    return 0;
}