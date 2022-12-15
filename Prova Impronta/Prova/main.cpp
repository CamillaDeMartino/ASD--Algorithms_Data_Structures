#include "MaxHeap.h"
#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;


int main(){

    MaxHeap<int> tree;
    string file = "Alunni.txt";
    fstream myFile;
    string num;
    map<string, int> amap;
    map<string, int>::iterator it;
    vector<string> alunni;
    vector<int> voti;

    myFile.open(file.c_str(), ios::in);

    while (getline(myFile, num))
    {
        
        string column1; 
        int column2;

        istringstream iss((num));
        iss>>column1>>column2;

        alunni.push_back(column1);
        voti.push_back(column2);
        amap.insert(make_pair(column1, column2));
        tree.insert(column2);

    }

    cout<<endl<<"ALUNNI: "<<endl;
    for(auto i:alunni)
        cout<<i<<" ";
    cout<<endl;


    cout<<endl<<"VOTI: "<<endl;
    for(auto i:voti)
        cout<<i<<" ";
    cout<<endl;
    
    cout<<endl<<"MAPPA: "<<endl;
    for(it = amap.begin(); it != amap.end(); it++)
        cout<<"Alunno: "<<(*it).first<<"    Voto: "<<(*it).second<<endl;

    cout<<endl<<"Heap voti:"<<endl;
    tree.print();
    cout<<endl<<"Voto massimo: "<<tree.getTree().at(0);

    it = amap.begin();
    while(tree.getTree().at(0) != (*it).second)
    {
        *it++;
    }   
    
    
    cout<<endl<<"Alunno: "<<(*it).first<<endl;

    return 0;
}