#ifndef RADIXSORT_H
#define RADIXSORT_H
#include<iostream>
#include<vector>

using namespace std;

template<class T>
class RadixSort
{
private:
    static T getMax(vector<T> *);
    static void countingRadix(vector<T> *, int);     //variante del counting sort
public:
    static void radixSort(vector<T> *);
    static void printArr(vector<T>);
    
};

template<class T> T RadixSort<T>::getMax(vector<T> *A)
{
    T max = A->at(0);
    for(int i = 1; i < A->size(); i++)
    {
        if(A->at(i) > max)
            max = A->at(i);
    }

    return max;
}


//procede come il counting sort, ma non prendiamo l'intero numero ma prima la cifra meno significativa
//fino a quella più significativa
//la cifra da considerare sarà data da div(divisore) passato da main
template<class T> void RadixSort<T>::countingRadix(vector<T> *A, int div)
{
    int sizeA = A->size();
    T *output = new T[sizeA];    //array di output
    T count[10] = {0};           //array delle occorrenze
    

    //salviamo le occorrenze delle singole cifre in count
    for(int i = 0; i < sizeA; i++)                           //es. A[0] = 170   div = 1
        count[(A->at(i) / div) % 10]++;                       //    count[170/1 % 10]++   =>   count[0]++;

    // Modifica count[i] in modo che count[i] ora contenga l'effettiva
    // posizione di questa cifra nell'output[]
    for(int i = 1; i < 10; i++)                                //es. C = 2 0 2 0 1 2 1 0 0 0
        count[i] += count[i - 1];                              //    C = 2 2 4 4 5 7 8 8 8 8

    //costrusci l'array di output
    for(int i = sizeA-1; i >= 0; i--)
    {
        output[count[(A->at(i) / div) % 10] - 1] = A->at(i);
        count[(A->at(i) / div) % 10]--;
    }

    //copia l'array di output in A
    for(int i = 0; i < sizeA; i++)
        A->at(i) = output[i];

}


template<class T> void RadixSort<T>::radixSort(vector<T> *A)
{
    T max = getMax(A);                         //es. A = 170 45 75 90 802 24 2 66    
                                                //max = 802

    for(int div = 1; max/div > 0; div *= 10)    //div = 1;  802/1 => 802 > 0 V
        countingRadix(A,div);                  //div = 10; 802/10 => 80 > 0 V
                                                //div = 100 802/100 => 8 > 0 V
                                                //div = 1000 802/1000 => 0. > 0 X
}

template<class T> void RadixSort<T>::printArr(vector<T> A)
{
    cout<<endl;

    for(auto i:A)
        cout<<i<<" ";
    cout<<endl<<endl;
}


#endif