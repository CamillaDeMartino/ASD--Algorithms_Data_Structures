#include "RadixSort.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){

    vector<int> A = {170, 45, 75, 90, 802, 24, 2, 66};

    RadixSort<int>::printArr(A);
    RadixSort<int>::radixSort(&A);
    RadixSort<int>::printArr(A);


    return 0;
}