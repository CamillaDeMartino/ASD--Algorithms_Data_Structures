#ifndef ISHEAP_H
#define ISHEAP_H
#include<vector>
#include <iostream>

using namespace std;

template<class T> 
class IsHeap
{
private:
    int parent(int);
    int left(int);
    int right(int);

    bool isMaxHeap(vector<T>, int, int);
    bool isMinHeap(vector<T>, int, int);

public:
    
    void printIsHeap(vector<T>, int, int);
};

template<class T> int IsHeap<T>::parent(int i)
{
    return (i-1)/2;
}

template<class T> int IsHeap<T>::left(int i)
{
    return (i*2)+1;
}

template<class T> int IsHeap<T>::right(int i)
{
    return (i*2)+2;
}

template<class T> bool IsHeap<T>::isMaxHeap(vector<T> tree, int size, int i)
{
    int l = left(i);
    int r = right(i);

    if(i >= size/2)
        return true;
    
    if(l < size && tree.at(i) < tree.at(l))
        return false;
    if(r < size && tree.at(i) < tree.at(r))
        return false;

    return isMaxHeap(tree, size, l) && isMaxHeap(tree, size, r);
}

template<class T> bool IsHeap<T>::isMinHeap(vector<T> tree, int size, int i)
{
    int l = left(i);
    int r = right(i);

    if(i >= size/2)
        return true;
    
    if(l < size && tree.at(i) > tree.at(l))
        return false;
    if(r < size && tree.at(i) > tree.at(r))
        return false;

    return isMinHeap(tree, size, l) && isMinHeap(tree, size, r);
}


template<class T> void IsHeap<T>::printIsHeap(vector<T> A, int s, int i)
{
    if(isMinHeap(A, s, i) && !isMaxHeap(A, s, i))
        cout<<endl<<"E' un Min Heap!!"<<endl;
    else if(!isMinHeap(A, s, i) && isMaxHeap(A, s, i))
        cout<<endl<<"E' un Max Heap!!"<<endl;
    else 
        cout<<endl<<"Non e' niente"<<endl;
}
#endif