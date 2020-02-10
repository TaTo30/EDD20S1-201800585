#include "Pila.h"

void Pila::Push(char c){
    NodoPila* aux = new NodoPila();
    aux->dato = c;
    if (Header == NULL)
    {
        //PILA VACIA
        Header = aux;
    }else{
        //PILA CON DATOS
        aux->Siguiente = Header;
        Header = aux;
    }   
}

char Pila::Pop(){
    char c = Header->dato;
    Header = Header->Siguiente;
    return c;
}