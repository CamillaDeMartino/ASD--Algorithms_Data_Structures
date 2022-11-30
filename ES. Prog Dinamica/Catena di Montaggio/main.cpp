/*
    • Implementare l'algoritmo FASTEST-WAY. 
    Progettare ed implementare una procedura che visualizzi il percorso tra le due catene di montaggio dalla stazione 1 alla stazione n.

       7-----9------3----4----- 8----4
      / \  / \    / \  / \    / \  /  \
    2    2/   3  /   1/   1  /   4/    3
         /\    \/    /\    \/    / \
    4   2  \   1\   2  \   2\   1   \   2
     \ /    \ /  \ /    \ /  \ /     \ /
      8------5----6------4----5-------7


    Un'altra soluzione è la seguente: S1,1-S2,2-S1,3-S1,4-S2,5- S1,6 oppure 1-2-1-1-2-1 (non quella evidenziata in figura)
*/


#include <iostream>
#include <vector>
#include "Catena.h"
using namespace std;


int main(){

    vector<vector<int>> catena;
    catena.push_back({7, 9, 3, 4, 8, 4});
    catena.push_back({8, 5, 6, 4, 5, 7});

    struct entry entry{2, 4};
    struct exit exit{3, 2};

    vector<vector<int>> tempoTrasferimento;
    tempoTrasferimento.push_back({2, 3, 1, 1, 4});
    tempoTrasferimento.push_back({2, 1, 2, 2, 1});

    vector<int> scelta = fastestWay(catena, tempoTrasferimento, entry, exit, 6);

    for(int i:scelta)           //otterremo 1 se proveniamo dalla stessa catena
        cout<<i<<" ";           //2 dall'altra catena
    cout<<endl;
    return 0;
}