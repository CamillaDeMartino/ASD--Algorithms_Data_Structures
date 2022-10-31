#ifndef MINPRIORITYQUEUE_H
#define MINPRIORITYQUEUE_H

#include "MinHeap.h"
#include <iostream>
#include <vector>
using namespace std;

template<class T>
class MinPriorityQueue:public MinHeap<T>
{
private:
    /* data */
public:
    MinPriorityQueue(vector<T>);

    void minHeapInsert(T);
    T getMinimum();
    T extractMin();
    void decreaseKey(int, T);
};

template<class T> MinPriorityQueue<T>::MinPriorityQueue(vector<T> tree):MinHeap<T>(tree){
}

template<class T> void MinPriorityQueue<T>::minHeapInsert(T nodo)
{
    this->insert(nodo);
}

template<class T> T MinPriorityQueue<T>::getMinimum()
{
    return this->getTree().at(0);
}

template<class T> T MinPriorityQueue<T>::extractMin()
{
    if(this->getHeapSize() == 0)
        return -1;
    
    T min = getMinimum();
    swap(this->tree.at(0), this->tree.at(this->getHeapSize()-1));
    this->setHeapSize(this->getHeapSize()-1);
    this->minHeapify(0);

    return min;
} 

template<class T> void MinPriorityQueue<T>::decreaseKey(int i, T key)
{
    if(key > this->getTree().at(i))
    {
        cout<<"Invalid data";
        exit;
    }   

    this->tree.at(i) = key;

    while(i > 0 && this->getTree().at(this->parent(i)) > this->getTree().at(i))
    {
        swap(this->tree.at(this->parent(i)), this->tree.at(i));
        i = this->parent(i);
    }
}














#endif