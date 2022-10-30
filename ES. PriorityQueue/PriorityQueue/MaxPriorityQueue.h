#ifndef MAXPRIORITYQUEUE_H
#define MAXPRIORITYQUEUE_H

#include "MaxHeap.h"
#include <iostream>
#include <vector>
using namespace std;

template<class T>
class MaxPriorityQueue:public MaxHeap<T>
{
private:
    /* data */
public:
    MaxPriorityQueue(vector<T>);

    void maxHeapInsert(T);
    T getMaximum();
    T extractMax();
    void increaseKey(int, T);
};

template<class T> MaxPriorityQueue<T>::MaxPriorityQueue(vector<T> tree):MaxHeap<T>(tree){
}

template<class T> void MaxPriorityQueue<T>::maxHeapInsert(T nodo)
{
    this->insert(nodo);
}

template<class T> T MaxPriorityQueue<T>::getMaximum()
{
    return this->getTree().at(0);
}

template<class T> T MaxPriorityQueue<T>::extractMax()
{
    if(this->getHeapSize() == 0)
        return -1;
    
    T max = getMaximum();
    swap(this->tree.at(0), this->tree.at(this->getHeapSize()-1));
    this->setHeapSize(this->getHeapSize()-1);
    this->maxHeapify(0);

    return max;
} 

template<class T> void MaxPriorityQueue<T>::increaseKey(int i, T key)
{
    if(key < this->getTree().at(i))
    {
        cout<<"Invalid data";
        exit;
    }   

    this->tree.at(i) = key;

    while(i > 0 && this->getTree().at(this->parent(i)) < this->getTree().at(i))
    {
        swap(this->tree.at(this->parent(i)), this->tree.at(i));
        i = this->parent(i);
    }
}














#endif