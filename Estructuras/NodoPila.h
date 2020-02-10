class NodoPila
{
public:
    NodoPila();
    NodoPila* Siguiente;
    char dato;

};

NodoPila::NodoPila()
{
    this->dato = NULL;
    this->Siguiente = NULL;
}
