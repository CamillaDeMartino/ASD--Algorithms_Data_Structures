/*
    • Dato un ABR, trovare la minima differenza tra le chiavi di due nodi
*/

#include "C:\Users\camil\OneDrive\Desktop\ASD\Lab\ASD\ES. Albero\BinarySearchTree\BinarySearchTree.h"
#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

template<class T>
void arrayVisit(Nodo<T> *current, vector<T> *array)
{   
  
    if(current != nullptr)
    {
        arrayVisit(current->getLeft(), array);
        array->push_back(current->getInfo());
        arrayVisit(current->getRight(), array);
    }
    
}

template<class T>
T  minCouple(vector<T> array)
{

    T diff = abs(array.at(0) - array.at(1));
    int ind = 0;
    for(int i = 1; i < array.size() - 1; i++)
    {
        if(abs(array.at(i) - array.at(i+1)) <= diff)
        {
            diff  = abs(array.at(i) - array.at(i+1));
            ind = i;
        }
    }

    return ind;
}


template<class T>
T  minCoupleRic(vector<T> array ,int i, int diff, int min) 
{   
    if(i == array.size() - 1)
        return min;

    if(abs(array.at(i) - array.at(i+1)) <= diff)
    {   
        diff = abs(array.at(i) - array.at(i+1));
        return minCoupleRic(array, i+1, diff, i);
    }    
    else
        return minCoupleRic(array, i+1, diff, min);
         
    
}

int main(){

    BinarySearchTree<int> ABR;

    ABR.insert(9);
    ABR.insert(13);
    ABR.insert(16);
    ABR.insert(12);
    ABR.insert(11);
    ABR.insert(14);
    ABR.insert(18);


    cout<<endl<<"INORDER: ";
    ABR.inorderVisit(ABR.getRoot());
    cout<<endl;


    vector<int> arr;
    arrayVisit(ABR.getRoot(), &arr);


    cout<<endl<<"Vector: ";
    for(auto i:arr)
        cout<<i<<" ";
    cout<<endl;

    int figlio = minCouple(arr);
    cout<<endl<<"VERSIONE ITERATIVA: ";
    cout<<endl<<"I nodi minimi sono: "<<arr.at(figlio)<<" e "<<arr.at(figlio+1)<<endl;
    
    int ind = minCoupleRic(arr, 0, UINT16_MAX, 0);
    cout<<endl<<"VERSIONE RICORSIVA: ";
    cout<<endl<<"I nodi minimi sono: "<<arr.at(ind)<<" e "<<arr.at(ind+1)<<endl;
    
    return 0;
}