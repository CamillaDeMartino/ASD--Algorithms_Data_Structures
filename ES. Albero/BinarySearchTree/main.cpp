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

    ABR.insert(12);
    ABR.insert(9);
    ABR.insert(5);
    ABR.insert(2);
    ABR.insert(13);
    ABR.insert(17);
    ABR.insert(18);
    ABR.insert(19);
    ABR.insert(15);

    ABR.preorderVisit(ABR.getRoot());
    
    cout<<"radice: "<<ABR.getRoot()->getInfo();
    ABR.printAsciiTree();


    return 0;
}
