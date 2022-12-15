#include "MaxPriority.h"
#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;


int main(){

    MaxPriority<int> tree;
    string file = "Alunni.txt";
    fstream myFile;
    string num;
    map<string, int> amap;
    map<string, int>::iterator it;

    myFile.open(file.c_str(), ios::in);

    while (getline(myFile, num))
    {
        
        string column1; 
        int column2;

        istringstream iss((num));
        iss>>column1>>column2;

        amap.insert(make_pair(column1, column2));
        tree.insertQueue(column2);

    }

 
    
    cout<<endl<<"MAPPA: "<<endl;
    for(it = amap.begin(); it != amap.end(); it++)
        cout<<"Alunno: "<<(*it).first<<"    Voto: "<<(*it).second<<endl;

    cout<<endl<<"Heap voti:"<<endl;
    
    tree.printQueue();
    cout<<endl<<"Voto massimo: "<<tree.getMaximum();

    it = amap.begin();
    while(tree.getMaximum() != (*it).second)
        *it++;
    
    cout<<endl<<"Alunno: "<<(*it).first<<endl;

    return 0;
}