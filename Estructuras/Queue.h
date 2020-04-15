#include <stdio.h>
#include <iostream>

using namespace std;

template <typename T> class Queue
{
    template <typename T> struct Nodo
    {
        T* dato;
        Nodo* siguiente;
    };

private:
    Nodo<T>* First;
    Nodo<T>* Last;
public:

//Constructor
Queue(){
    First = NULL;
    Last = NULL;
}
//Inserta un valor en la cola
void Enqueue(T* dato)
{
    Nodo<T>* aux = new Nodo<T>();
    aux->dato = dato;
    if (First == NULL)
    {
        //LISTA VACIA INSERTAR DATOS
        First = aux;
        Last = aux;
    }else{
        //ENCOLAR DATO SIEMPRE APUNTANTOD A FIRST
        aux->siguiente = First;
        First = aux;
    }    
}
//Retorna un valor de la cola
T* Dequeue(){
    Nodo<T>* aux = First;
    Nodo<T>* toReturn = NULL;
    if (First == Last)
    {
        toReturn = First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        while (aux != NULL)
        {
            if (aux->siguiente == Last)
            {
                toReturn = Last;
                Last = aux;
                Last->siguiente = NULL;
                aux = NULL;
            }
            else
            {
                aux = aux->siguiente;
            }        
        }
    }    
    return toReturn->dato;
}

//Retorna un valor booleano, true si la cola tiene datos, false si no tiene datos
bool Contain(){
    bool toReturn = true;
    if (First ==NULL)
    {
        toReturn = false;
    }
    return toReturn;
}
//Retorna el tamaño de la cola
int Size(){
    Nodo<T>* aux = First;
    int contador=0;
    while (aux != NULL)
    {
        contador++;
        aux=aux->siguiente;
    }
    return contador;
}
//Vacia toda la cola
void Clear(){
    while (Contain())
    {
        delete Dequeue();
    }    
}

};