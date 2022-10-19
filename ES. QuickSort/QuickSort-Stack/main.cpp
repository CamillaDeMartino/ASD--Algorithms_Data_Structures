/*
     Progettare ed implementare una procedura quicksort
     iterativa
*/
#include <iostream>
#include "QuickSort.h"
#include "Stack.h"
using namespace std;

int main()
{
    int arr [] = {2,8,7,1,3,5,6,4};

    QuickSort<int>::quickSort_iter(arr,0,7);

    for(auto i:arr)
        cout<<i<<" ";
    return 0;
}