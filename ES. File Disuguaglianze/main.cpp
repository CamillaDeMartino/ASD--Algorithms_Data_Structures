#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Tester.h"
using namespace std;


int main()
{
    string p = "problema.txt";
    string s = "soluzione.txt";
    string e = "esito.txt";
    Tester tester(p,s,e);
    tester.check();

    return 0;
}
