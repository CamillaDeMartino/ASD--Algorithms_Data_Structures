#ifndef COUNTINGSORT_H
#define COUNTINGSORT_H
#include <vector>
#include <iostream>

using namespace std;

class CountingSort
{
public:
    static void countingSortF(vector<int> *);
    static void countingSortC(vector<int> *, vector<int> *);

    static void reverseF(vector<int>*);
};

void CountingSort::countingSortF(vector <int> *A)
{
    int sizeA = A->size();
    int max = A->at(0), min = A->at(0);
    //Calcolo elementi max e min

    for(int i = 1; i < sizeA; i++)
    {
        if( A->at(i) > max)
            max = A->at(i);
        else if(A->at(i) < min)
            min = A->at(i);
    }

    //Costruzione dell'array C * crea un array C di dimensione max - min 
    int sizeC = max - min + 1;
    int *C = new int[sizeC];

    for(int i = 0; i < sizeC; i++)
    {
       //inizializza a 0 gli elementi di C
        C[i] = 0;
    }

    for(int i = 0; i < sizeA; i++)
    {
        //aumenta il numero di occorrenze del valore
        C[A->at(i) - min]++;
    }


    //Ordinamento in base al contenuto dell'array delle frequenze C
    int k = 0;
    //indice per l'array A
    for(int i = 0; i < sizeC; i++)
    {
        while(C[i] > 0)
        {
            //scrive C[i] volte il valore  i + min nell'array A
            A->at(k) = i + min;
            k++;
            C[i]--;
        }
    }

    delete[]C;

}


void CountingSort::reverseF(vector<int> *A)
{
    int sizeA = A->size();
    int max = A->at(0), min = A->at(0);
    //Calcolo elementi max e min

    for(int i = 1; i < sizeA; i++)
    {
        if( A->at(i) > max)
            max = A->at(i);
        else if(A->at(i) < min)
            min = A->at(i);
    }

    //Costruzione dell'array C * crea un array C di dimensione max - min 
    int sizeC = max - min + 1;
    int *C = new int[sizeC];

    for(int i = 0; i < sizeC; i++)
    {
       //inizializza a 0 gli elementi di C
        C[i] = 0;
    }

    for(int i = 0; i < sizeA; i++)
    {
        //aumenta il numero di occorrenze del valore
        C[A->at(i) - min]++;
    }


    //Ordinamento in base al contenuto dell'array delle frequenze C
    int k = 0;
    //indice per l'array A
    for(int i = sizeC-1; i >= 0; i--)
    {
        while(C[i] > 0)
        {
            //scrive C[i] volte il valore  i + min nell'array A
            A->at(k) = i + min;
            k++;
            C[i]--;
        }
    }

    delete[]C;
}


void CountingSort::countingSortC(vector<int> *A, vector<int> *B)
{
    int sizeA = A->size();
    int max = A->at(0), min = A->at(0);
    //Calcolo elementi max e min

    for(int i = 1; i < sizeA; i++)
    {
        if( A->at(i) > max)
            max = A->at(i);
        else if(A->at(i) < min)
            min = A->at(i);
    }

    //Costruzione dell'array C * crea un array C di dimensione max - min 
    int sizeC = max - min + 1;
    int *C = new int[sizeC];

    for(int i = 0; i < sizeC; i++)
    {
       //inizializza a 0 gli elementi di C
        C[i] = 0;
    }

    for(int j = 0; j < sizeA; j++)
        C[A->at(j)]++;

    for(int i = 1; i < sizeC; i++)
        C[i] += C[i-1];

    for(int j = sizeA-1; j >= 0; j--)
    {
        B->at(C[A->at(j)]-1) = A->at(j);
        C[A->at(j)]--;
    }

    delete[]C;
}

#endif