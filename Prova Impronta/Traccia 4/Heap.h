#ifndef MEAP_H
#define HEAP_H
#include <iostream>
#include <vector>

using namespace std;

template<class T>
class Heap
{
protected:
    virtual vector<T> getTree() = 0;
    virtual int parent(int) = 0;
    virtual int left(int ) = 0;
    virtual int right(int ) = 0;

    virtual void swap(T& , T&) = 0;
    virtual void setHeapSize(int ) = 0;
    virtual int getHeapSize() = 0;
    virtual void insertHeap(T) = 0;
    virtual void buildHeap() = 0;
    virtual void heapify(int) = 0;
    
};





#endif