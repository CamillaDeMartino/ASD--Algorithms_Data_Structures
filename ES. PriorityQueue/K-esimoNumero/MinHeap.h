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
    int getHeapSize();
    vector<T> getTree();

    void insert(T);
    void minHeapify(int);

public:
    MinHeap(vector<T>, int);

    void buildMinHeap();
    void printArray();
 
};


template<class T> MinHeap<T>::MinHeap(vector<T> t, int hpsz)
{
    tree = t;
    heapSize = hpsz;
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
    cout<<"Inserito: "<<nodo<<endl;
    if (nodo > getTree().at(0))
    {
        cout<<nodo<<" > "<<getTree().at(0)<<endl;
        tree.at(0) = nodo;
        buildMinHeap();
    }
    else 
    {
        cout<<"Elemento inserito piu' piccolo della radice"<<endl;
    } 

}

template<class T> void MinHeap<T>::printArray()
{
    cout<<endl << "**Alberello***" << endl;
    for (int i = 0; i < tree.size(); i++) 
        cout << tree.at(i) <<" ";
    cout<<endl<<endl;
}


#endif