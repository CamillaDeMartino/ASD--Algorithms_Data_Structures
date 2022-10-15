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
    static void merge(typename vector<Item>::iterator, typename vector<Item>::iterator, typename vector<Item>::iterator); 
public:
    static void mergeSort(typename vector<Item>::iterator, typename vector<Item>::iterator );
};


template<class Item> void Algoritmi<Item>::merge(typename vector<Item>::iterator begin, typename vector<Item>::iterator mid, typename vector<Item>::iterator end){

    auto size = end - begin;
    typename vector<Item>::iterator i;
    typename vector<Item>::iterator j;
    typename vector<Item>::iterator k;
    vector<Item> aux(size);
    
    //utilizzo center come indice di aux poiché gli iteratori punteranno all'elemento stesso
    //non alla posizione
    //size/2 - 1 perché in caso di numeri di dispari si approssima per difetto
    int center = (size/2) -1 ;

    for(i = mid-1; i != begin-1; i--)
    {
        aux.at(center) = *i;
        center--; 
    }

    //center è giunto alla fine, poiché la seconda parte dell'array deve essere riempita al contraio lo riporto alla fine
    center = size;
    for(j = mid; j != end; j++)
    {   
        aux.at(center-1) = *j;
        center--;
    }

    //riposoziono gli indici 
    //i all'inzio dell'array creato e j alla fine
    i = aux.begin();
    j = aux.end() - 1;


    
    for(k = begin; k != end; k++){
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


template<class Item> void Algoritmi<Item> :: mergeSort(typename vector<Item>::iterator begin, typename vector<Item>::iterator end)
{
    //non posso passare come parametro l'array intero perché non si aggiorna
    //si preferisce dunque lavorare unicamente con gli itreratori
    auto size = end-begin;
   
    if(size >= 2)
    {   
        auto mid = begin;
        advance(mid,size/2);

        mergeSort(begin, mid); 
        mergeSort(mid, end);
        merge(begin,mid,end);
    }
}

#endif
