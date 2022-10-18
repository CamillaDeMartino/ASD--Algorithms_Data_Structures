/*
    • Implementare il Quicksort con doppio pivot
    • Questa variante utilizza un pivot per la parte sinistra dell'array ed
        un pivot per la parte destra con il vincolo che il pivot sinistro sia
        minore del pivot destro
    • Al termine della procedura di partition, l'array sarà diviso in tre parti:
        • La prima in cui gli elementi sono minori del pivot sinistro
        • La seconda in cui gli elementi sono maggiori o uguali deln pivot sinistro e minori uguali del pivot destro
        • La terza in cui gli elementi sono maggiori del pivot destro
        
    • L'algoritmo viene richiamato ricorsivamente sulle tre parti dell'array
*/


#include <iostream>
#include "QuickSort.h"

int main(){

    int A[] = {4,3,1,2,20,11};

    for(auto i : A)
        std::cout<<i<<" ";

    std::cout<<std::endl;

    QuickSort<int>::quickSort(A,0,5);

    for(auto i : A)
        std::cout<<i<<" ";

    return  0;
}