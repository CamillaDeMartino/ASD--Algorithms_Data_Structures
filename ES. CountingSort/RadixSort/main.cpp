#include "RadixSort.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){

    vector<int> A = {170, 45, 75, 90, 802, 24, 2, 66};

    RadixSort::printArr(A);
    RadixSort::radixSort(&A);
    RadixSort::printArr(A);


    return 0;
}