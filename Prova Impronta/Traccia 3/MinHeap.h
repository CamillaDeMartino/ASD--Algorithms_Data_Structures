#ifndef MINHEAP_H
#define MINHEAP_H
#include "Heap.h"
#include <iostream>
#include <vector>

using namespace std;

template<class T>
class MinHeap:public Heap<T>
{
private:
    int heapSize;
    

    int left(int i)override{return (i*2)+1;}
    int right(int i)override{return (i*2)+2;}

    
    void buildHeap()override;

protected:
    vector<T> tree;
    vector<T> getTree(){return tree;}
    int parent(int i)override{return (i-1)/2;}

    void swap(T&, T&)override;
    void setHeapSize(int heapSize){this->heapSize = heapSize;}
    int getHeapSize(){return heapSize;}
    void Heapify(int)override;
    void insert(T)override;

public:
    MinHeap(vector<T>);
    MinHeap();

    
    void printArray();
};

template<class T> MinHeap<T>::MinHeap(vector<T> tree)
{
    heapSize = tree.size();
    this->tree = tree;
    buildHeap();
}

template<class T> MinHeap<T>::MinHeap()
{
    heapSize = 0;
}

template<class T> void MinHeap<T>::swap(T &A, T &B)
{
    T temp = A;
    A = B;
    B = temp;
}

template<class T> void MinHeap<T>::Heapify(int i)
{
    int min = i;
    int l = left(i);
    int r = right(i);

    if(l < getHeapSize() && getTree().at(min) > getTree().at(l))
        min = l;
    if(r < getHeapSize() && getTree().at(min) > getTree().at(r))
        min = r;

    if(min != i)
    {
        swap(tree.at(min), tree.at(i));
        Heapify(min);
    }
}

template<class T> void MinHeap<T>::insert(T value)
{
    setHeapSize(getHeapSize() + 1);
    tree.push_back(value);

    int i = getHeapSize()-1;
    while(i > 0 && getTree().at(parent(i)) > value)
    {
        swap(tree.at(parent(i)), tree.at(i));
        i = parent(i);
    }
}

template<class T> void MinHeap<T>::buildHeap()
{
    setHeapSize((int) tree.size());
    for(int i = getHeapSize()/2-1; i >= 0; i--)
        Heapify(i);
}

template<class T> void MinHeap<T>::printArray()
{
    for(int i = 0; i < tree.size(); i++)
        cout<<tree.at(i)<<" ";
    cout<<endl;
}



#endif