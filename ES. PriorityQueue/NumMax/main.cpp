/*
    • Dato un array di n elementi, trovare il massimo numero di
      elementi distinti dopo aver rimosso k elementi (k<=n)
        • Es.: {5,4,4,3,4,6,2,1,2}, 
                per k=2 maxnum=5(5,3,6,2,1), 
                per k=3 maxnum=6(5,4,3,6,2,1)
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

  /*vector<int> a;

  for(it =amap.begin(); it!=amap.end(); it++)
        a.push_back((*it).second);
  

  MaxPriorityQueue<int> tree = MaxPriorityQueue<int>(a);
  tree.buildMaxHeap();
  tree.printArray();

  for(int i = 0; i< k; i++)
  {
    cout<<tree.getMaximum();
    tree.decreaseKey(0,tree.getMaximum()-1);

    //tree.buildMaxHeap();
    tree.printArray(); 
  }*/


  
  return 0;
}