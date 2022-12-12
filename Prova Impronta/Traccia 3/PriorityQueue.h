#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include <iostream>

using namespace std;

template<class T>
class PriorityQueue
{
private:
    
public:
    PriorityQueue();
    virtual ~PriorityQueue();

    virtual void insertHeap(T);
    //virtual T getMinimum();
    //virtual T getMaximum();
    //virtual T extractMin();
    //virtual T extractMax();
    //virtual void increaseKey(int , T);
    //virtual void decreseKey(int , T);

    //virtual void printQueue();   
};

template<class T> PriorityQueue<T>::PriorityQueue()
{
}




#endif