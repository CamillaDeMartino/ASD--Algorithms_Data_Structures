#include "MaxPriority.h"
#include <iostream>

using namespace std;

int main(){

    MaxPriority<int> ABR;

    ABR.insertMax(11);
    ABR.insertMax(12);
    ABR.insertMax(16);
    ABR.insertMax(10);
    ABR.insertMax(13);
    ABR.insertMax(14);
    ABR.insertMax(17);


    ABR.print();
    cout<<endl<<"Massimo: "<<ABR.getMaximum()<<endl;


    return 0;
}
