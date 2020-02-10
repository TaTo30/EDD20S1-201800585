#include "NodoPila.h"

class Pila
{
private:
    NodoPila* Header;
public:
    void Push(char c);
    char Pop();
};
