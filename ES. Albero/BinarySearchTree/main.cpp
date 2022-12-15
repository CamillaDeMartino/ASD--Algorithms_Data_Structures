/* • Progettare una classe BinarySearchTree che implementi un
     albero binario di ricerca con le seguenti funzioni
        • INSERT
        • SEARCH
        • MINIMUM
        • MAXIMUM
        • PREDECESSOR
        • SUCCESSOR
        • DELETE
*/

#include "BinarySearchTree.h"
#include <iostream>

using namespace std;

int main(){

    BinarySearchTree<int> ABR;
    
    /*
    ABR.insert(13);
    ABR.insert(12);
    ABR.insert(16);
    ABR.insert(10);
    ABR.insert(11);
    ABR.insert(14);
    ABR.insert(17);
    */

    ABR.insert(13);
    ABR.insert(12);
    ABR.insert(16);
    ABR.insert(10);
    ABR.insert(11);
    ABR.insert(14);
    ABR.insert(17);
    
    cout<<"PREORDER: ";
    ABR.preorderVisit(ABR.getRoot());
    cout<<endl<<"INORDER: ";
    ABR.inorderVisit(ABR.getRoot());

    cout<<endl<<endl<<"Elemento minimo: "<<ABR.minimumTree(ABR.getRoot())->getInfo()<<endl;
    cout<<"Elemento massimo: "<<ABR.maximumTree(ABR.getRoot())->getInfo()<<endl;
    
    auto *x = ABR.treeSearch(ABR.getRoot(), 14);
    cout<<endl<<"Il successore di: "<< x->getInfo()<<" e': "<<ABR.successor(x)->getInfo();
    cout<<endl<<"Il Predecessore di: "<< x->getInfo()<<" e': "<<ABR.predecessor(x)->getInfo();
    
    cout<<endl<<endl<<"Cancello il numero 11: ";
    ABR.treeDelete(ABR.treeSearch(ABR.getRoot(), 11));
    cout<<endl<<"PREORDER: ";
    ABR.preorderVisit(ABR.getRoot());
    cout<<endl<<"INORDER: ";
    ABR.inorderVisit(ABR.getRoot());

    return 0;
}
 