#ifndef HEAPSORT_H
#define HEAPSORT_
#include <iostream>
#include <vector>

using namespace std;

template<class T>
class Heapsort
{
private:
    vector<T> tree;
    int heapsize;

    int parent(int);
    int left(int );
    int right(int );

    void swap(T&, T&);
    void max_Heapify(int );
    void build_Max_Heapify();
    
    void setHeapSize(int);
    int getHeapSize();
    vector<T> getTree();
public:
    Heapsort(vector<T>);
    void heapSort();
    void printArray();
};

template<class T> Heapsort<T>::Heapsort(vector<T> t)
{
    tree = t;
    heapsize = 0;
}

template<class T> int Heapsort<T>::parent(int i)
{
    return (i-1)/2;
}

template<class T> int Heapsort<T>::left(int i)
{
    return (2*i) + 1 ;
}

template<class T> int Heapsort<T>::right(int i)
{
    return (2*i) + 2;
}

template<class T> void Heapsort<T>::swap(T &A, T &B)
{
    T temp;
    temp = A;
    A = B;
    B = temp;
}

template<class T> void Heapsort<T>::setHeapSize(int hpsz)
{
    heapsize = hpsz;
}

template<class T> int Heapsort<T>::getHeapSize()
{
    return heapsize;
}

template<class T> vector<T> Heapsort<T>::getTree()
{
    return tree;
}

template<class T> void Heapsort<T>::max_Heapify(int i)
{
    int max = i;
    int l = left(i);
    int r = right(i);

    if(l < getHeapSize() && getTree().at(max) < getTree().at(l) )
        max = l;
    
    if(r < getHeapSize() && getTree().at(max) < getTree().at(r))
        max = r;
    
    if(max != i)
    {
        swap(tree.at(i), tree.at(max));
        max_Heapify(max);
    }
}

template<class T> void Heapsort<T>::build_Max_Heapify()
{
    setHeapSize((int)getTree().size());
    for(int j = (getHeapSize()/2); j >= 0; j--)
        max_Heapify(j);
    
}


template<class T> void Heapsort<T>::heapSort()
{
    build_Max_Heapify();

    for(int j = getHeapSize()-1; j >= 0; j--)
    {
        swap(tree.at(0), tree.at(j));
        setHeapSize(getHeapSize()- 1);
        max_Heapify(0);
    }
}

template<class T> void Heapsort<T>::printArray()
{
    cout<<endl << "**Alberello***" << endl;
    for (int i = 0; i <tree.size(); i++)
        cout<<tree.at(i)<<" ";

    cout<<endl<<endl;
}





#endif