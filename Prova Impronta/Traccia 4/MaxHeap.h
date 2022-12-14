#ifndef MAXHEAP_H
#define MAXHEAP_H
#include "Heap.h"
#include <iostream>
#include <vector>

using namespace std;

template<class T>
class MaxHeap:private Heap<T>
{
private:
    int heapSize;
    int left(int i)override{return (i*2)+1;}
    int right(int i)override{return (i*2)+2;}
    

protected:
    vector<T> tree;

    vector<T> getTree()override{return tree;}
    int parent(int i)override{return (i-1)/2;}
    void swap(T& , T&)override;
    void setHeapSize(int heapSize)override{this->heapSize = heapSize;}
    int getHeapSize()override{return heapSize;}
    void insertHeap(T)override;
    void buildHeap()override;
    void heapify(int)override;
    void printHeap();

public:
    MaxHeap(vector<T>);
    MaxHeap();
};

template<class T> MaxHeap<T>::MaxHeap()
{
    heapSize = 0;
}

template<class T> MaxHeap<T>::MaxHeap(vector<T> tree)
{
    heapSize = tree.size();
    this->tree = tree;
    buildHeap();
}

template<class T> void MaxHeap<T>::swap(T &A, T &B)
{
    T temp = A;
    A = B;
    B = temp;
}

template<class T> void MaxHeap<T>::insertHeap(T value)
{
    setHeapSize(getHeapSize() + 1);
    tree.push_back(value);

    int i = getHeapSize() - 1;
    while(i > 0 && getTree().at(parent(i)) < value)
    {
        swap(tree.at(parent(i)), tree.at(i));
        i = parent(i);
    }
}


template<class T> void MaxHeap<T>::heapify(int i)
{
    int max = i;
    int l = left(i);
    int r = right(i);

    if(l < getHeapSize() && getTree().at(max) < getTree().at(l))
        max = l;
    if(r < getHeapSize() && getTree().at(max) < getTree().at(r))
        max = r;

    if(max != i)
    { 
        swap(tree.at(max), tree.at(i));
        heapify(max);
    }
}

template<class T> void MaxHeap<T>::buildHeap()
{
    setHeapSize((int)tree.size());

    for(int i = getHeapSize()/2 -1 ; i >= 0; i--)
        heapify(i);
}


template<class T> void MaxHeap<T>::printHeap()
{
    for(int i = 0; i < getHeapSize(); i++)
        cout<<getTree().at(i)<<" ";
    cout<<endl;
}      



#endif