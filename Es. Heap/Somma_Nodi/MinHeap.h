#ifndef MINHEAP_H
#define MINHEAP_H
#include <iostream>
#include <vector>

using namespace std;

template<class T>
class MinHeap
{
private:
    vector<T> tree;
    int heapsize;

    int parent(int);
    int left(int);
    int right(int);

    void setHeapSize(int);
    int getHeapSize();
    vector<T> getTree();

    void swap(T&, T&);
    void min_Heapify(int);
    void build_Min_Heap();

public:
    MinHeap(vector<T>);

    void printArray();
    void insert(T);

    int sum(int, int);
    
};

template <class T> MinHeap<T>::MinHeap(vector<T> t)
{
    tree = t;
    heapsize = 0;
}

template<class T> int MinHeap<T>::parent(int i)
{
    return (i-1)/2;
}

template<class T> int MinHeap<T>::left(int i)
{
    return (i*2)+1;
}

template<class T> int MinHeap<T>::right(int i)
{
    return (i*2)+2;
}

template<class T> void MinHeap<T>::setHeapSize(int hpsz)
{
    heapsize = hpsz;
}

template<class T> int MinHeap<T>::getHeapSize()
{
    return heapsize;
}

template<class T> vector<T> MinHeap<T>::getTree()
{
    return tree;
}

template<class T> void MinHeap<T>::swap(T &A, T &B)
{
    T temp = A;
    A = B;
    B = temp;
}

template<class T> void MinHeap<T>::min_Heapify(int i)
{
    int min = i;
    int l = left(i);
    int r = right(i);

    if(l < getHeapSize() && getTree().at(min) > getTree().at(l) )
        min = l;
    
    if(r < getHeapSize() && getTree().at(min) > getTree().at(r))
        min = r;
    
    if(min != i)
    {
        swap(tree.at(i), tree.at(min));
        min_Heapify(min);
    }
}

template<class T> void MinHeap<T>::build_Min_Heap()
{
    setHeapSize((int)getTree().size());
    for(int j = (getHeapSize()/2); j >= 0; j--)
        min_Heapify(j);
}

template<class T> void MinHeap<T>::insert(T nodo)
{
    setHeapSize(getHeapSize() + 1);
    tree.push_back(nodo);
    build_Min_Heap();
    
}

template<class T> void MinHeap<T>::printArray()
{
    cout<<endl << "**Alberello***" << endl;
    for (int i = 0; i <getHeapSize(); i++)
        cout<<getTree().at(i)<<" ";

    cout<<endl<<endl;
}

template<class T> int MinHeap<T>::sum(int num, int x)
{
    if(x >= getHeapSize())
        return 0;
    if(getTree().at(x) >= num)
        return 0;

    return getTree().at(x) + sum(num, left(x)) + sum(num, right(x));
}


#endif