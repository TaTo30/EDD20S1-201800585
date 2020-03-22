#include <stdio.h>
#include <string>
#include "../Estructuras/OrderList.h"
#include "../Estructuras/LinkedList.h"
#include "Ficha.h"

using namespace std;

class Jugador
{
private:
    string Nombre;
    OrderList<int> Puntajes;
    LinkedList<Ficha> Fichas;
public:
    Jugador(string Nombre);
    void AgregarFicha(Ficha F);
    void AgregarPuntaje(int P);  
    LinkedList<Ficha> GetFichas();
    OrderList<int> GetPuntajes(); 
};

Jugador::Jugador(string Nombre)
{
    this->Nombre = Nombre;
    
}

void Jugador::AgregarFicha(Ficha F){
    Fichas.AddLast(F);
}

void Jugador::AgregarPuntaje(int P){
    Puntajes.Add(P,P);
}

LinkedList<Ficha> Jugador::GetFichas(){
    return Fichas;
}

OrderList<int> Jugador::GetPuntajes(){
    return Puntajes;
}
