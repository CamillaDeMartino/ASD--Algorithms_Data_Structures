/* 
    Riscrivere il Merge Sort utilizzando il contenitore Vector
    ed un iteratore
*/

#include <iostream>
#include <vector>
#include "MergeSort.h"

using namespace std;
//template <typename Item>

int main(){
    vector<int> A = {9,7,3,1};
    typename vector<int>::iterator it;

    cout<<endl;
    for(it = A.begin(); it != A.end(); it++)
    for(it = A.begin(); it != A.end(); it++)
    {
        cout<<"["<< *it <<"]";
    }
    cout<<endl<<endl;  



    Algoritmi<int> :: mergeSort(A, A.begin(), A.end());




    cout<<endl<<"Dopo merge"<<endl;
    for(it = A.begin(); it != A.end(); it++)
    {
        cout<<"["<< *it <<"]";
    }
    cout<<endl<<endl;

    return 0;
}