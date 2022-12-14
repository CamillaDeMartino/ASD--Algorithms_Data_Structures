/*
    • Utilizzando il paradigma della programmazione ad oggetti ed il linguaggio C++ 11, progettare ed implementare una classe coda di minima 
      priorità minQ che erediti da una classe virtuale coda di priorità Q, in modo che gli oggetti di classe minQ non possano accedere agli
      attributi ed ai metodi della classe Q.
      La struttura dati verrà popolata leggendo il contenuto del file priorita.txt.
      Dato un array di n elementi, trovare il massimo numero di elementi distinti dopo aver rimosso k elementi (k<=n)
        • Es.: {5,4,4,3,4,6,2,1,2}, 
                per k=2 maxnum= 6(5,4,3,6,2,1), 
                per k=3 maxnum= 6(5,3,4,6,2,1)


*/

#include "MaxPriorityQueue.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main(){

  MaxPriorityQueue<int> *heap = new MaxPriorityQueue<int>();
  string file = "priorita.txt";
  string num;
  fstream myfile;

  vector<int> vect;
  map<int, int> amap;
  vector<int>::iterator it;
  map<int,int>::iterator jt;

  myfile.open(file.c_str(), ios::in);

  while(getline(myfile, num))
      vect.push_back(stof(num));

  
  for(int i = 0; i < vect.size(); i++)
  { 
      int num = vect.at(i);
      jt = amap.find(num);

      if(jt == amap.end())
        amap.insert(make_pair(num, 1));
      else
        amap.at(num)++;
  }

  cout<<endl<<"MAPPA"<<endl;
  for(jt = amap.begin(); jt != amap.end(); jt++)
  {
    cout<<"Numero: "<<(*jt).first<<" Occorrenza: "<<(*jt).second<<endl;
    heap->insert((*jt).second);
  }

  cout<<endl<<"HEAP"<<endl;
  heap->print();
  cout<<endl<<"VETTORE"<<endl;
  for(auto i:vect)
    cout<<i<<" ";
  cout<<endl;

  int k = 3;
  for(int i = 0; i < k; i++)
  {
    jt = amap.begin();
    it = vect.begin();

    while((*jt).second != heap->getRoot())
        *jt++;

    while((*jt).first != *it)
        *it++;

  
    vect.erase(it);
    (*jt).second--;
    heap->changePriority(0, heap->getRoot() - 1);
    heap->print();
  }
  cout<<endl;

  cout<<"Vettore risultante: "<<endl;
  for(auto i:vect)
    cout<<i<<" ";
  cout<<endl;


  cout<<endl<<"Risultato"<<endl;
  cout<<amap.size()<< " = ";
  for(jt = amap.begin(); jt != amap.end(); jt++)
    cout<<(*jt).first<<" ";


  myfile.close();
  return 0;
}