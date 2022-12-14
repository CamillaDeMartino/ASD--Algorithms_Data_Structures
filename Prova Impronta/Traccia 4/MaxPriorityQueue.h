#ifndef MAXPRIORITYQUEUE_H
#define MAXPRIORITYQUEUE_H
#include "PriorityQueue.h"
#include "MaxHeap.h"
#include <iostream>

using namespace std;

template<class T>
class MaxPriorityQueue:private MaxHeap<T>, PriorityQueue<T>
{

public:
    MaxPriorityQueue(/* args */);

    void insert(T) override;
    T getRoot() override;
    T extractRoot() override;
    void changePriority(int, T)override;
    void print() override;
};

template<class T> MaxPriorityQueue<T>::MaxPriorityQueue():MaxHeap<T>()
{
}

template<class T> void MaxPriorityQueue<T>::insert(T value)
{
    this->insertHeap(value);
}

template<class T> T MaxPriorityQueue<T>::getRoot()
{
    return this->getTree().at(0);
}

template<class T> T MaxPriorityQueue<T>::extractRoot()
{
    if(this->getHeapSize() == 0)
        return -1;

    T max = this->getRoot();
    int i = this->getHeapSize() - 1;
    this->swap(this->tree.at(0), this->tree.at(i));
    this->setHeapSize(this->getHeapSize() - 1);
    this->heapify(0);

    return max;

}

template<class T> void MaxPriorityQueue<T>::changePriority(int i, T key)
{
    //decrease
    if(this->getTree().at(i) < key)
        cout<<"error"<<endl;
    
    this->tree.at(i) = key;
    this->buildHeap();
}

template<class T> void MaxPriorityQueue<T>::print()
{
    this->printHeap();
}


#endif