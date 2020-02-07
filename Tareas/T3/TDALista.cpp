#include <iostream>
#include <string>
#include "ListaSimple.cpp"

using namespace std;

int main()
{
    cout<<"Bienvenido";
    ListaSimple* listado = new ListaSimple();
    listado->Add("Aldo",201800585);
    listado->Add("Jorge",201766650);
    listado->Add("Alfredo",20487995);
    listado->Print();
    listado->Delete(listado->Find(20487995));
    listado->Add("Juan", 44550540);
    listado->Print();
    cin.ignore();
    cin.get();

}