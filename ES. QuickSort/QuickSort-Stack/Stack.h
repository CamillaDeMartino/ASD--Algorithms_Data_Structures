#ifndef STACK_H
#define STACK_H

template <typename T>

class Stack
{
private:
    int Dim, Top;     //massima occupazione della pila
                      //ultimo elemento inserito
    T *Vet;
public:
    Stack()
    {
        Vet = nullptr;  //pila vuota
        Dim = 0;
        Top = -1;
    }
    
    void Push(T Elm);
    bool Pop(T &Elm);
    T Pop();
    bool isEmpty();
};

template <typename T> void Stack<T>::Push (T Elm)
{
    if (Top == Dim-1) // se lo Stack è pieno
    { 
        T *App;
        App = new T[Dim+10]; // trasloca lo stack
        for (int i=0; i<Dim; i++) 
            App[i] = Vet[i];
        
        Dim += 10; 
        delete [] Vet; 
        Vet = App; // allunga lo stack
    }
    Vet[ ++Top ] = Elm;
}


template <typename T> bool Stack<T>::Pop (T &Elm)
{ 
    bool Risp;
    if (Top >= 0) Risp = true, Elm = Vet[Top--];
    else          Risp = false; // stack vuoto
    
    return Risp;
}

template <typename T> T Stack<T>::Pop()
{
    if(Top >= 0)
        return Vet[Top--];
    return Vet[0];
}

template <typename T> bool Stack<T>::isEmpty()
{
    return Top==-1;
}
#endif