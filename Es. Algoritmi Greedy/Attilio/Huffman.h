#ifndef HUFFAMN_H
#define HUFFMAN_H
#include "C:\Users\camil\OneDrive\Desktop\ASD\Lab\ASD\ES. PriorityQueue\K-esimoNumero\MinPriorityQueue.h"
#include "Occorrenza.h"
#include "Nodo.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

template<class T>
class Huffman
{
private:
    fstream input;
    fstream output;

    MinPriorityQueue<Occorrenza<T>> minQueue;
    map<T, int> mapFrequenze;
    string stringDecode;
    map<T, string> codice;
    
public:
    Huffman(string, string);
    ~Huffman();

    string getStringDecode(){return this->stringDecode;}

    void letturaFile();
    void codifica();
    void memorizzaCodici(Nodo<Occorrenza<T>> *root);
    string decodifica();
};

template<class T> Huffman<T>::Huffman(string file1, string file2)
{
    input.open(file1.c_str(), ios::in);
    output.open(file2.c_str(), ios::out);
    stringDecode = "";
}

template<class T> Huffman<T>::~Huffman()
{
    input.close();
    output.close();
}

template<class T> void Huffman<T>::letturaFile()
{
    vector<T> vect;
    T line;
    typename map<T, int>::iterator it;

    while(input>>line)
        vect.push_back(line);


    for(int i = 0; i < vect.size(); i++)
    {
        T num = vect.at(i);
        it = mapFrequenze.find(num);

        if(it == mapFrequenze.end())
            mapFrequenze.insert(make_pair(num, 1));
        else
            mapFrequenze.at(num)++;
    }

    for(it = mapFrequenze.begin(); it != mapFrequenze.end(); it++)
        cout<<(*it).first<<" -> "<<(*it).second<<endl;

}


template<class T> void Huffman<T>::codifica()
{
    this->letturaFile();
    typename map<T, int>::iterator it;

    for(it = mapFrequenze.begin(); it != mapFrequenze.end(); it++){
        Occorrenza<T> o(it->first,it->second);
        minQueue.minHeapInsert(o);
    }

    minQueue.print();

    Nodo<Occorrenza<T>> *nodePadre;
    Nodo<Occorrenza<T>> *nodeA;
    Nodo<Occorrenza<T>> *nodeB;
    while(minQueue.getHeapSize() > 1)
    {
        nodeA = new Nodo<Occorrenza<T>>(minQueue.extractMin());
        nodeB = new Nodo<Occorrenza<T>>(minQueue.extractMin());

        Occorrenza<T> nuovo(' ',nodeA->getInfo().getFrequenza()+nodeB->getInfo().getFrequenza());
        nodePadre = new Nodo<Occorrenza<T>>(nuovo);
        
        //setti parent e figli
        nodePadre->setLeft(nodeA);
        nodePadre->setRight(nodeB);
        //nodeA->setParent(nodePadre);
        //nodeB->setParent(nodePadre);

        //inserisci nuovo in coda priorità
        minQueue.minHeapInsert(nuovo);
    }

    Nodo<Occorrenza<T>> *root = new Nodo<Occorrenza<T>>(minQueue.getMinimum());
    root->setLeft(nodeA);
    root->setRight(nodeB);
    root->setParent(nullptr);
    minQueue.print();
    this->memorizzaCodici(root);
    
}


template<class T> void Huffman<T>::memorizzaCodici(Nodo<Occorrenza<T>> *root )
{
    //Nodo<Occorrenza<T>> *root = minQueue.extractMin();
    
   //cout<<stringa;
    if(!root)
        return;
    else if(root->getInfo().getData() != 'X') codice[root->getInfo().getData()] = stringDecode;
    stringDecode += "0";
    memorizzaCodici(root->getLeft());
    stringDecode += "1";
    memorizzaCodici(root->getRight());

}


template<class T> string Huffman<T>::decodifica()
{
    string temp = "";
    Nodo<Occorrenza<T>>* curr = new Nodo<Occorrenza<T>>(minQueue.getMinimum());


    for (int i=0; i<stringDecode.size(); i++)
    {
        if (stringDecode.at(i) == '0')
            curr = curr->getLeft();
        else
            curr = curr->getRight();
        if ( curr->getLeft() == nullptr && curr->getRight() == nullptr )
        {
            temp += curr->getInfo().getData();
            curr = new Nodo<Occorrenza<T>>(minQueue.getMinimum());
        }
    }
    return temp;
}

#endif