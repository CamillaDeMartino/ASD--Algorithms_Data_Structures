#ifndef MINHEAP_H
#define MINHEAP_H
#include <iostream>
#include <vector>

using namespace std;

template<class T>
class MinHeap
{
private:

    int left(int);
    int right(int);

protected:
    int heapSize;
    vector<T> tree;

    int parent(int);
    void swap(T&, T&);
    

    void insert(T);
    void minHeapify(int);

public:
    MinHeap(vector<T>);
    MinHeap();

    vector<T> getTree();
    int getHeapSize();
    void buildMinHeap();
    void printArray();
 
};


template<class T> MinHeap<T>::MinHeap(vector<T> t)
{
    tree = t;
    heapSize = 0;
}

template<class T>MinHeap<T>::MinHeap()
{
    heapSize = 0;
}

template<class T> void MinHeap<T>::swap(T &A, T &B)
{
    T temp = A;
    A = B;
    B = temp;
}


template<class T> int MinHeap<T>::getHeapSize()
{
    return heapSize;
}

template<class T> vector<T> MinHeap<T>::getTree()
{
    return tree;
}

template<class T> int MinHeap<T>::parent(int i)
{
    return(i-1)/2;
}

template<class T> int MinHeap<T>::left(int i)
{
    return (i*2) + 1;
}

template<class T> int MinHeap<T>::right(int i)
{
    return (i*2) + 2; 
}

template<class T> void MinHeap<T>::minHeapify(int i)
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
        swap(tree.at(i), tree.at(min));
        minHeapify(min);
    }
}

template<class T> void MinHeap<T>::buildMinHeap()
{

    for(int j = (getHeapSize()/2); j >= 0; j--)
        minHeapify(j);
        
}

template<class T> void MinHeap<T>::insert(T nodo)
{   
    tree.push_back(nodo);
    heapSize = getHeapSize() + 1;
   
    int i = getHeapSize()-1;

    while(i > 0 && getTree().at(parent(i)) > nodo)
    {
        swap(tree.at(i), tree.at(parent(i)));
        i = parent(i);
    }

}

template<class T> void MinHeap<T>::printArray()
{
    cout<<endl << "**Alberello***" << endl;
    for (int i = 0; i < getHeapSize(); i++) 
        cout << getTree().at(i) <<" ";
    cout<<endl<<endl;
}


#endif