/*
Progettare ed implementare una lista (linked list) di
impiegati di un'azienda. Un impiegato ha un nome ed un
salario. Un manager è un impiegato cui viene corrisposto
un bonus oltre al salario.
  1. Creare una lista di impiegati e stamparla a video
     sfruttando il principio del polimorfismo
  2. Implementare l'overload dell'operatore + in modo da
     sommare i salari di tutti gli impiegati
*/



#include <iostream>

#include "Impiegato.h"
#include "Manager.h"
#include "Lista.h"

using namespace std;

int main()
{
    Lista *a = new Lista();

    a->Inserimento(new Manager(20, "Camilla", 200));
    a->Inserimento(new Manager(30, "Carmen", 200));
    a->Inserimento(new Impiegato("Carmela", 200));
    a->Inserimento(new Impiegato("Cam", 200));
    

    a->printList();
    a->sum();

    return 0;
}


