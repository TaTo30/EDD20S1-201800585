#include <string.h>
#include <stdio.h>
#include <iostream>

using namespace std;

class Nodo
{
public:
    string nombreCompleto;
    int carnet;
    Nodo* siguiente;

public:
    Nodo();
};

Nodo::Nodo()
{
}
