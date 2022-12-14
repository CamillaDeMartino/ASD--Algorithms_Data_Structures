#ifndef HEAP_H
#define HEAP_H
#include <iostream>

using namespace std;

template<class T>
class Heap
{
   
protected:
    virtual int parent(int) = 0;
    virtual int left(int) = 0;
    virtual int right(int) = 0;

    virtual void swap(T &, T&) = 0;
    virtual void Heapify(int) = 0;
    virtual void insert(T) = 0;
    virtual void buildHeap() = 0;

};





#endif