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

    //RadixSortString::printArray(A, sizeof(A));
    //radixSort(A, sizeof(A), 4);

    int size = sizeof(A) / sizeof(A[0]);
    RadixSortString::radixSortString(A, size, 4);
    
    for (int i = 0; i < size; i++) {
        cout << A[i] <<endl;
    }
    cout<<endl;
    return 0;
}