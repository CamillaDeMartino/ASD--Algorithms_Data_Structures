/*
    • Progettare ed implementare una classe che implementi un
      heap k-nario (ogni nodo ha k figli)
*/


#include "Kheap.h"
#include <iostream>
#include <ctime>

using namespace std;

int main()
{
  srand(time(NULL));

  vector<int> t;
  Kheap<int> tree = Kheap<int>(t, 3);

  for(int i = 0; i< 13; i++)
  {
    int num = rand()%100;
    tree.insert(num);
  }

  tree.printArray();

  return 0;
}