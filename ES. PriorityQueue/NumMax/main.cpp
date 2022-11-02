/*
    • Dato un array di n elementi, trovare il massimo numero di
      elementi distinti dopo aver rimosso k elementi (k<=n)
        • Es.: {5,4,4,3,4,6,2,1,2}, 
                per k=2 maxnum= 6(5,4,3,6,2,1), 
                per k=3 maxnum= 5(5,3,6,2,1)
*/

#include "MaxPriorityQueue.h"
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){

  vector<int> arr{5, 4, 4, 3, 4, 6, 2, 1, 2};
  map<int, int> amap;
  map<int,int>::iterator it;
  vector<int>::iterator jt;

  int num, k = 2;

  for(int i = 0; i < arr.size(); i++)
  {
    num = arr.at(i);
    it = amap.find(num);

    if ( it == amap.end())
      amap.insert(make_pair(num,1));
    else   
      amap.at(num)++;
  }


  for(it = amap.begin(); it!=amap.end(); it++)
        cout << (*it).first << " => " << (*it).second << endl;


  MaxPriorityQueue<int> tree = MaxPriorityQueue<int>();
  for(it =amap.begin(); it!=amap.end(); it++)
        tree.maxHeapInsert((*it).second);

  tree.printArray();
  cout<<endl;
  for ( int i=0; i<arr.size(); i++)
    cout << arr.at(i) << " ";
  
  for(int i = 0; i< k; i++)
  {
    it = amap.begin();
    jt = arr.begin();  
     
    while(tree.getMaximum() != (*it).second)
      it++;
    while(*jt != (*it).first)
      jt++;

    arr.erase(jt);
    tree.decreaseKey(0,tree.getMaximum()-1);
    
    cout<<endl;
    for ( int i=0; i<arr.size(); i++)
      cout << arr.at(i) << " " ;


    tree.printArray(); 
  }


  
  return 0;
}