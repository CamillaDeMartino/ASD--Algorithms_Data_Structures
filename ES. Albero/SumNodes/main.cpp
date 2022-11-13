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

    for(int i = 1; i < array.size() - 1; i++)
    {
       if(abs(array.at(i) - array.at(i+1)) < diff)
            return i;
    }

    return 0;
}


template<class T>
T  minCoupleRic(vector<T> array ,int i, int diff) 
{   cout<<"i = "<< i << endl;
    cout<<"A[i] = "<<array.at(i)<<endl;
    cout<<"A[i + 1] = "<<array.at(i+1)<<endl;
    cout<<"differenza = "<<abs(array.at(i) - array.at(i+1))<<endl;
    
    int min;
    if(i == array.size() - 2)
        return min;
    
    if(abs(array.at(i) - array.at(i+1)) <= diff)
    {   
        cout<<"if"<<endl;
        
        min = i;
        cout<<"min = "<<min<<endl;
        diff = abs(array.at(i) - array.at(i+1));
        cout<<"diff = "<<diff<<endl;
        return minCoupleRic(array, i+1, diff);
    }    
    else
        cout<<"else"<<endl;
    {   cout<<"diff = "<<diff<<endl;
        return minCoupleRic(array, i+1, diff);
    }
         
    
}

int main(){

    BinarySearchTree<int> ABR;

    ABR.insert(15);
    ABR.insert(13);
    ABR.insert(16);
    ABR.insert(9);
    ABR.insert(11);
    ABR.insert(14);
    ABR.insert(17);

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

    //cout<<endl<<"I nodi minimi sono: "<<arr.at(figlio)<<" e "<<arr.at(figlio+1)<<endl;
    
    int ind = minCoupleRic(arr, 0, UINT16_MAX);
    cout<<endl<<"I nodi minimi sono: "<<arr.at(ind)<<" e "<<arr.at(ind-1)<<endl;
    
    return 0;
}