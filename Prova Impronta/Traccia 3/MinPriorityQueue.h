#ifndef MINPRIORITYQUEUE_H
#define MINPRIORITUQUEUE_H
#include <iostream>
#include <vector>
#include "PriorityQueue.h"
#include "MinHeap.h"

using namespace std;

template<class T>
class MinPriorityQueue:private PriorityQueue<T>, MinHeap<T>
{
public:

    void insertHeap(T) override; 
    T getRoot() override;
    T extractRoot() override;
    void changePriority(int , T) override;

    void print();

    MinPriorityQueue(/* args */);

};

template<class T> MinPriorityQueue <T>::MinPriorityQueue():MinHeap<T>()
{
}

template<class T> void MinPriorityQueue<T>::insertHeap(T value)
{
    
    this->insert(value);
}

template<class T> T MinPriorityQueue<T>::getRoot()
{
    return this->getTree().at(0);
}


template<class T> T MinPriorityQueue<T>::extractRoot()
{
    if(this->getHeapSize() == 0)
        return 0;
    
    T min = this->getRoot();
    int i = this->getHeapSize() - 1;
    this->tree.erase(this->tree.begin());
    this->setHeapSize(this->getHeapSize() -1 );
    this->Heapify(0);

    return min;
}

template<class T> void MinPriorityQueue<T>::changePriority(int i, T key)
{
    //decrease
    if(key < this->getTree().at(i))
        cout<<"error"<<endl;
    
    this->tree.at(i) = key;
    while(i > 0 && this->getTree().at(this->parent(i)) > this->getTree().at(i))
    {
        this->swap(this->tree.at(this->parent(i)), this->tree.at(i));
        i = this->parent(i);
    }
}

template<class T> void MinPriorityQueue<T>::print()
{
    this->printArray();
    
}


#endif