#include <iostream>
class NodoCircular
{
public:
    NodoCircular();
    NodoCircular* Siguiente;
    char dato;

};

NodoCircular::NodoCircular()
{
    this->dato = NULL;
    this->Siguiente = NULL;
}
