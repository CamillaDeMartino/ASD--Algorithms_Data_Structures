/*
    • Implementare radix sort su un array di parole di 4 caratteri
*/


#include "RadixSortString.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){

    string A[] = {
        "zzzz",
        "bbbb",
        "aabb",
        "bbaa",
        "cccc",
        "dddd",
        "ccaa",
        "ddaa" };

    int size = sizeof(A) / sizeof(A[0]);

    RadixSortString::printArray(A, size);
    RadixSortString::radixSortString(A, size, 4);
    RadixSortString::printArray(A, size);
    
    return 0;
}