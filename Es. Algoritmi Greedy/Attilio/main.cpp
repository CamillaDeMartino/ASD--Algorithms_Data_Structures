#include <iostream>
#include <string>
#include "Huffman.h"


using namespace std;


int main()
{
    string input = "file.txt";
    string output = "output.txt";

    Huffman<char> prova(input, output);

    prova.codifica();

    cout << prova.getStringDecode() << endl;
    
    cout << prova.decodifica() << endl;
    return 0;
}