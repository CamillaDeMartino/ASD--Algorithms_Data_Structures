/*  
    Dichiariamo i metodi statici in tal modo nel main non sono costretta a dichiarare un oggetto di tipo classe
    per richiamare i metodi, ma fare Algoritmi::nomeMetodo
*/

#ifndef ALGORITMI_H
#define ALGORITMI_H
#include <vector>

using namespace std;
template<class Item>

class Algoritmi
{
private:
    static void merge(vector<Item>, typename vector<Item>::iterator); 
public:
    static void mergeSort(vector<Item>, typename vector<Item>::iterator, typename vector<Item>::iterator );
};


template<class Item> void Algoritmi<Item>::merge(vector<Item> A, typename vector<Item>::iterator mid){

    
    typename vector<Item>::iterator i;
    typename vector<Item>::iterator j;
    typename vector<Item>::iterator k;
    vector<Item> aux(A.size());
    
    //utilizzo center come indice di aux 
    int center = A.size()/2;
    for(i = mid-1; i != A.begin()-1; i--)
    {
        aux.at(center-1) = *i;
        center--; 
    }

    //center è giunto alla fine, poiché la seconda parte dell'array deve essere riempita al contraio lo riporto alla fine
    center = A.size();
    for(j = mid; j != A.end(); j++)
    {   
        aux.at(center-1) = *j;
        center--;
    }

    //riposoziono gli indici 
    //i all'inzio dell'array creato e j alla fine
    i = aux.begin();
    j = aux.end() - 1;


    
    for(k = A.begin(); k != A.end(); k++){
        if(*j < *i)
        {
            *k = *j;
            j--;
        }
        else
        {
            *k = *i;
             i++;
        }
    }
 
}


template<class Item> void Algoritmi<Item> :: mergeSort(vector<Item> A, typename vector<Item>::iterator begin, typename vector<Item>::iterator end)
{
    
    if(A.size() > 1)
    {
        
        int center = (A.size())/2;
        auto a = A.begin();
        advance(a,center);


        mergeSort(A, begin, a-1); 
        mergeSort(A, a, end);
        merge(A, a);
    }
}

#endif
