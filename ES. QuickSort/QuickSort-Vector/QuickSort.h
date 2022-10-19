#ifndef QUICKSORT_H
#define QUICKSORT_H
#include <vector>

using namespace std;

template<class Item>
class QuickSort
{
private:
    static typename vector<Item>::iterator partition(typename vector<Item>::iterator, typename vector<Item>::iterator);
    static void swap (Item &, Item&);
public:
    static void quickSort(typename vector<Item>::iterator, typename vector<Item>::iterator);
    
};

template<class Item> void QuickSort<Item>::swap(Item &A, Item &B)
{
    Item temp = A;
    A = B;
    B = temp;
}

template<class Item> 
typename vector<Item>::iterator QuickSort<Item>::partition(typename vector<Item>::iterator begin, typename vector<Item>::iterator end)
{
    Item pivot = *end;

    typename vector<int>::iterator i;
    typename vector<int>::iterator j;

    i = begin-1;
    j = end;

     for(;;)
    {
        while (*(++i) < pivot );
        while (pivot < *(--j))
            if(j == begin)
                break;
        if (i >= j)
            break;
        swap (*i,*j);
    }
    swap(*i, *end);

    return i;
    
}


template<class Item> void QuickSort<Item>::quickSort(typename vector<Item>::iterator begin, typename vector<Item>::iterator end)
{
    if (end <= begin)
        return;
    auto i = partition(begin,end);

    quickSort(begin,i-1);
    quickSort(i+1,end);
}

#endif