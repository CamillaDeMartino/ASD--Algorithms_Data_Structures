#ifndef MINPRIORITYQUEUE_H
#define MINPRIORITYQUEUE_H

#include "C:\Users\camil\OneDrive\Desktop\ASD\Lab\ASD\ES. Albero\BinarySearchTree\BinarySearchTree.h"

#include <iostream>
#include <vector>
using namespace std;

template<class T>
class MinPriorityQueue
{
private:
    BinarySearchTree<T> ABR;
public:
   
    void insert(T);
    T getMinimum();
    void extractMin();
    void decreaseKey(T, T);
    void print();
};



template<class T> void MinPriorityQueue<T>::insert(T nodo)
{
    ABR.insert(nodo);
}

template<class T> void MinPriorityQueue<T>::print()
{
    ABR.inorderVisit(ABR.getRoot());
}

template<class T> T MinPriorityQueue<T>::getMinimum()
{
    return ABR.minimumTree(ABR.getRoot())->getInfo();
}

template<class T> void MinPriorityQueue<T>::extractMin()
{
    if(ABR.getRoot() == nullptr)
        exit;
    
    ABR.treeDelete(ABR.minimumTree(ABR.getRoot()));
    
} 

template<class T> void MinPriorityQueue<T>::decreaseKey(T i, T key)     //i = vecchio nodo,  k = nuovo valore del nodo
{
    auto *curr = ABR.treeSearch(ABR.getRoot(), i);
    if(key > curr->getInfo() || curr == nullptr)
    {
        cout<<"Invalid data";
        exit;
    }   

    ABR.treeDelete(curr);
    ABR.insert(key);
}


#endif