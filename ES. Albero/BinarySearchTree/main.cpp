/* • Progettare una classe BinarySearchTree che implementi un
     albero binario di ricerca con le seguenti funzioni
        • SEARCH
        • MINIMUM
        • MAXIMUM
        • PREDECESSOR
        • SUCCESSOR
        • INSERT
        • DELETE
*/

#include "BinarySearchTree.h"
#include <iostream>

using namespace std;

int main(){

    BinarySearchTree<int> ABR;

    /*ABR.insert(12);
    ABR.insert(9);
    ABR.insert(5);
    ABR.insert(2);
    ABR.insert(13);
    ABR.insert(17);
    ABR.insert(18);
    ABR.insert(19);
    ABR.insert(15);
    */
    
    /*
    ABR.insert(13);
    ABR.insert(12);
    ABR.insert(16);
    ABR.insert(10);
    ABR.insert(11);
    ABR.insert(14);
    ABR.insert(17);
    */

    ABR.insertRic(13, nullptr, ABR.getRoot());
    ABR.insertRic(12, nullptr, ABR.getRoot());
    ABR.insertRic(16, nullptr, ABR.getRoot());
    ABR.insertRic(10, nullptr, ABR.getRoot());
    ABR.insertRic(11, nullptr, ABR.getRoot());
    ABR.insertRic(14, nullptr, ABR.getRoot());
    ABR.insertRic(17, nullptr, ABR.getRoot());

    cout<<"PREORDER: ";
    ABR.preorderVisit(ABR.getRoot());
    cout<<endl<<"INORDER: ";
    ABR.inorderVisit(ABR.getRoot());
    


    return 0;
}
