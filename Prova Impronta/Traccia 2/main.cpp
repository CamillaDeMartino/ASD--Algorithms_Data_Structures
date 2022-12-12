/*
    • Utilizzando il paradigma della programmazione ad oggetti ed il linguaggio C++ 11, progettare ed
      implementare, come classe, una struttura dati albero binario di ricerca che consenta di effettuare l'unione di
      due alberi (senza ripetizioni) i cui valori siano letti dai file ABR_A.txt ed ABR_B.txt, 
      contenti le chiavi dei nodi secondo l'ordine anticipato (preorder).
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "BinaryTree.h"

using namespace std;


void Unione(BinaryTree<int> ABR, Nodo<int> *x)
{
    
    if(x != nullptr)
    {
        if(ABR.treeSearch(ABR.getRoot(), x->getInfo()) == nullptr)
        {   
            ABR.insert(x->getInfo());
            Unione(ABR, x->getLeft());
            Unione(ABR, x->getRight());
        }
    }
}

int Massimo(int x, int y)
{
    
    if(x > y)
        return x;
    else 
        return y;
    
}

int Altezza(Nodo<int> *x)
{
    int l, r, max;

    if(x == nullptr)
        return 0;
    else
        return Massimo(Altezza(x->getLeft()), Altezza(x->getRight())) +1;

        
}




int main(){

    BinaryTree<int> tree1;
    BinaryTree<int> tree2;

    string txt1 = "ABR_A.txt";
    string txt2 = "ABR_B.txt";

    fstream ABR1;
    fstream ABR2;

    string file1;
    string file2;

    ABR1.open(txt1.c_str(), ios::in);
    ABR2.open(txt2.c_str(), ios::in);

    while(getline(ABR1, file1))
        tree1.insert(stof(file1));
    

    while(getline(ABR2, file2))
        tree2.insert(stof(file2));
    


    cout<<"Albero 1: "<<endl;
    tree1.visitPostorder(tree1.getRoot());
    cout<<endl;

    int h1 = Altezza(tree1.getRoot());
    cout<<endl<<"Altezza ABR1: " <<h1<<endl;

    cout<<endl<<"Albero 2: "<<endl;
    tree2.visitPostorder(tree2.getRoot());
    cout<<endl;

    int h2 = Altezza(tree2.getRoot());
    cout<<endl<<"Altezza ABR2: " <<h2<<endl;

    cout<<endl<<"UNIONE: "<<endl;
    if(h2 < h1 )
    {
        Unione(tree1, tree2.getRoot());
        tree1.visitPostorder(tree1.getRoot());
    }
    else
    {
        Unione(tree2, tree1.getRoot());
        tree2.visitPostorder(tree2.getRoot());
    }
    

    return 0;
}


