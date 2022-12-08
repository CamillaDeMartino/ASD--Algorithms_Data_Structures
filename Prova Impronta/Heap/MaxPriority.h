#include "C:\Users\camil\OneDrive\Desktop\ASD\Lab\ASD\Prova Impronta\Heap\HeapSort.h"
#include <iostream>
#include <vector>

using namespace std;

template<class T>
class MaxPriority:public HeapSort<T>
{
private:
    /* data */
public:
    MaxPriority(vector<T>);

    void insertMax(T);
    T getMaximum();
    T extractMax();
    void increaseKey(int , T);
    void print();
    
};

template<class T> MaxPriority<T>::MaxPriority(vector<T> tree):HeapSort<T>(tree)
{
}

template<class T> void MaxPriority<T>::insertMax(T nodo)
{
    this->insert(nodo);
}

template<class T> T MaxPriority<T>::getMaximum()
{
    return this->getTree().at(0);
}

template<class T> T MaxPriority<T>::extractMax()
{
   
    if(this->getHeapsize() == 0)
        return -1;

    T max = getMaximum();
    int i = this->getHeapsize()-1;
    this->swap(this->tree.at(0), this->tree.at(i));
    this->setHeapsize(this->getHeapsize() -1);
    this->maxHeapify(0);

    return max;
    
}


template<class T> void MaxPriority<T>::increaseKey(int i, T key)
{
    if(this->getTree().at(i) > key)
    {
        cout<<"error"<<endl;
        exit;
    }

    this->tree.at(i) = key;
    while(i > 0 && this->getTree().at(this->parent(i)) < this->getTree().at(i))
    {
        this->swap(this->tree.at(this->parent(i)), this->tree.at(i));
        i = this->parent(i);
    }
}

template<class T> void MaxPriority<T>::print()
{
    cout<<endl << "**Alberello***" << endl;
    for (int i = 0; i < this->getHeapsize(); i++) 
        cout << this->getTree().at(i) <<" ";
    cout<<endl<<endl;
}
