#include "ListaSimple.h"



void::ListaSimple::Add(string nombre, int id){
    Nodo* aux = new Nodo();
    aux->nombreCompleto = nombre;
    aux->carnet = id;
    aux->siguiente = first;
    first = aux;
    cout<<"Se ha agregado a la lista a "<<aux->nombreCompleto<<" con carnet: "<<aux->carnet;
}

void::ListaSimple::Delete(Nodo* n){
    if (n == NULL)
    {
        cout<<"Error amigo";
    }else{
        first = n->siguiente;
        cout<<"se han borrado los nodos a partir"<<endl;
    }
    
}

Nodo*::ListaSimple::Find(int carnet){
    Nodo* aux = new Nodo();
    aux = first;
    bool loop = true;
    while (loop)
    {
        if(aux->carnet == carnet){
            return aux;
            loop = false;
        }else{
            aux = aux->siguiente;
        }
    }
    
    
}

bool::ListaSimple::Verify(){
    if (first == NULL)
    {
        return true;
    }else{
        return false;
    }    
}

void::ListaSimple::Print(){
    Nodo* aux = new Nodo();
    aux = first;
    while (aux != NULL)
    {
        cout<<aux->nombreCompleto<<" "<<aux->carnet<<endl;
        aux = aux->siguiente;
    }
    
}