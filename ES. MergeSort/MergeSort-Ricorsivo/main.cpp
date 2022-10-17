/*
    Progettare ed implementare una procedura Merge ricorsivo
*/



#include <iostream>
#include "MergeRicorsivo.h"

using namespace std;

int main(){

    int A[6] = {4,3,1,2,20,11};
    
    MergeRicorsivo<int>::mergeSort(A, 0, 5);

    for(auto i : A)
        cout<<i<<" ";


    return 0;
}