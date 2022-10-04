/*
La blockchain è una struttura dati composta da una lista di
blocchi all'interno dei quali è memorizzato un insieme di
transazioni. Una transazione è costituita da un indirizzo
FROM, un indirizzo TO ed un valore intero QT.
- 1. Progettare ed implementare una struttura dati
     LinkedList mediante template ed utilizzarla per
     realizzare una blockchain
 -2. Dato un indirizzo A, stampare a video/salvare su file
     tutte le transazioni in cui compare A ed il suo bilancio finale
*/

#include <iostream>
#include "Transazione.h"

int main(){

    Transazione a("Patata", "carciofi", 2);

    a.getTransazione();

    return 0;
}