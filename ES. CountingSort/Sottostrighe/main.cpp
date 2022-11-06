/*
    Progettare ed implementare un algoritmo che dato in input un array di stringhe
    le ordini in modo che ogni stringa sia una sottostringa delle successive
    Es.: [palmare, re, spalmare, mare]
        re
        mare
        palmare
        spalmare
 */

#include "CountingSortString.h"
#include <iostream>
#include <vector>
#include <string>

int main(){

    vector<string> A = {"mare", "spalmare", "re", "palmare"};

    CountingSortString::printArr(A);
    CountingSortString::countingSortString(&A);
    CountingSortString::printArr(A);
    return 0;
}