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

    int center = A.size()/2;

    for(i = mid-1; i != A.begin()-1; i--)
    {
        cout<<"i: "<< *i;
        cout<<"center: "<<center<<endl;
        aux.at(center-1) = *i;
        center--; 
    }
    i = aux.begin();

     for (auto& v : aux){
        cout << v << " ";
    }
    cout << endl;

    center = A.size();
    for(j = mid; j != A.end(); j++)
    {   
        cout<<"j= "<<*j;
        cout<<"center: "<<center<<endl;
        aux.at(center-1) = *j;
        center--;
    }
    j = aux.end() - 1;


    for (auto& v : aux){
    cout << v << " ";
    }
    cout << endl;
    cout << endl;
    
    cout<<"j: " << *j << " "<<endl;
    cout <<"i: "<< *i << " "<<endl;

    
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
    int center = (A.size())/2;

    
    if(A.size()>1)
    {
        auto a = A.begin();
        advance(a,center);

   
      /* vector<Item> Sx;
        vector<Item> Dx;

        Sx.assign(A.begin(), a);
        Dx.assign(a, A.end());
      */

        mergeSort(A, begin, a);  
        mergeSort(A, a, end);
        merge(A, a);
    }
}

#endif
