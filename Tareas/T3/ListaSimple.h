#include "Nodo.h"


using namespace std;


class ListaSimple
{    
private:
    Nodo* first;
public:
    void Add(string nombre, int id);
    void Delete(Nodo* n);
    Nodo* Find(int carnet);
    bool Verify();
    void Print();
};
