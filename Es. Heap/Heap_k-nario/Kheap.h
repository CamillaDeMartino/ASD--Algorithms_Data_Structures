#ifndef KHEAP_H
#define KHEAP_H
#include<iostream>
#include <vector>

using namespace std;

template<class T>
class Kheap
{
private:
    vector<T> tree;
    int heapSize;
    int kChild;

    void setHeapSize(int);
    int getHeapSize();
    vector<T> getTree();
    
    void swap(T&, T&);
    void buildMaxKheap();
    void maxKHeapify(int);

public:
    Kheap(vector<T>, int);

    void insert(T);
    void printArray(); 
};

template<class T> Kheap<T>::Kheap(vector<T> t, int k)
{
    tree = t;
    kChild = k;
    heapSize = 0;
}

template<class T> void Kheap<T>::swap(T &A, T &B)
{
    T temp = A;
    A = B;
    B = temp;
}

template<class T> void Kheap<T>::setHeapSize(int hpsz)
{
    heapSize = hpsz;
}

template<class T> int Kheap<T>::getHeapSize()
{
    return heapSize;
}

template<class T> vector<T> Kheap<T>::getTree()
{
    return tree;
}

template<class T> void Kheap<T>::buildMaxKheap()
{
    setHeapSize((int)getTree().size());

    for(int j = getHeapSize()/kChild; j >= 0; j--)
        maxKHeapify(j);
}

template<class T> void Kheap<T>::maxKHeapify(int i)
{
    int max = i;

    int last = kChild * (i+1);
    int first = kChild * i + 1;


    for(int j = first; j < last; j++)
    {
        if(j < getHeapSize() && getTree().at(max) < getTree().at(j))
            max = j; 
    }


    if(max != i)
    {
        swap(tree.at(max), tree.at(i));
        maxKHeapify(max);
    }
}

template<class T> void Kheap<T>::insert(T nodo)
{
    setHeapSize(getHeapSize()+1);
    tree.push_back(nodo);
    buildMaxKheap();
}

template<class T> void Kheap<T>::printArray()
{
    cout<<endl << "**Alberello***" << endl;
    for (int i = 0; i <getHeapSize(); i++)
        cout<<getTree().at(i)<<" ";

    cout<<endl<<endl;
}

#endif