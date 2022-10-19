/* 
    Riscrivere il quicksort utilizzando il contenitore Vector
    ed gli iteratori
*/

#include <iostream>
#include <vector>
#include "QuickSort.h"
using namespace std;


int main()
{
    vector<int> arr = {2,8,7,1,3,5,6,4};

    QuickSort<int>::quickSort(arr.begin(),arr.end()-1);

    for(auto i:arr)
        cout<<i<<" ";


    return 0;
}