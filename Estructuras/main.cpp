#include "ListaDoble.cpp"
#include "Pila.cpp"
#include "ListaCircularSimple.cpp"
#include <stdio.h>

using namespace std;

int main()
{
    ListaDoble* lista = new ListaDoble();
    lista->InsertarLast('a');
    lista->InsertarLast('l');
    lista->InsertarLast('d');
    lista->InsertarLast(' ');
    lista->InsertarLast('H');
    lista->InsertarLast('E');
    lista->InsertarLast('R');
    lista->InsertarLast('N');
    cout<<lista->Buscar("HERN")->dato;
    lista->Imprimir();
    cout<<"FIN";
    cin.get();
    cin.ignore();
    
    

    
}
