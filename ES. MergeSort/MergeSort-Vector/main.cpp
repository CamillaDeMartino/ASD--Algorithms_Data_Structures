/* 
    Riscrivere il Merge Sort utilizzando il contenitore Vector
    ed un iteratore
*/

#include <iostream>
#include <vector>
#include "MergeSort.h"

using namespace std;


int main(){
    vector<int> A = {9,7,3,1};
    //typename vector<int>::iterator it;

    Algoritmi<int> :: mergeSort(A.begin(), A.end());

    for(auto &v:A)
        cout<<v<<" ";
    

    return 0;
}