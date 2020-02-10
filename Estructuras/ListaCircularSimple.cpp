#include "ListaCircularSimple.h"

void ListaCircularSimple::Insertar(char c){
    NodoCircular* aux = new NodoCircular();
    aux->dato = c;
    if (First == NULL)
    {
        //LISTA VACIA
        First = aux;
        Last = aux;
        First->Siguiente = aux;
        Last->Siguiente = aux;
    }else{
        aux->Siguiente = First;
        Last->Siguiente = aux;
        First = aux;
    }    
}