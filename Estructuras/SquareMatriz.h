#include <stdio.h>

using namespace std;

template <typename T> class Matrix
{
    template <typename T> struct Nodo
    {
        T Dato;
        int X, Y;
        Nodo* Siguiente, Anterior, Arriba, Abajo;
    };
private:
    Nodo<T>* FirstX;
    Nodo<T>* LastX;
    Nodo<T>* FirstY;
    Nodo<T>* LastY;
public:
Matrix(){
    FirstX = NULL;
    LastX = NULL;
    FirstY = NULL;
    LastY = NULL;
}

void Add(T Value, int X, int Y){
    Nodo<T>* aux = new Nodo<T>();
    aux->Dato = Value;
    aux->X = X;
    aux->Y = Y;
    if (FirstX == NULL)
    {
       //LISTA VACIA
       FirstX = aux;
       LastX = aux;
       FirstY = aux;
       LastY = aux;
    }
    else
    {
        //PARA X
        if (X < FirstX->X)
        {
            FirstX->Anterior = aux;
            aux->Siguiente = FirstX;
            FirstX = aux;
        }else if (X > LastX->X)
        {
            LastX->Siguiente = aux;
            aux->Anterior = LastX;
            LastX = aux;
        }else{
            Nodo<T>* busqueda = First;
            while (busqueda != NULL)
            {
                if ((OrderIndex > busqueda->orderIndex) && (OrderIndex <= busqueda->siguiente->orderIndex) )
                {
                    aux->siguiente = busqueda->siguiente;
                    busqueda->siguiente = aux;
                    busqueda = NULL;
                
                }else{
                    busqueda = busqueda->siguiente;
                }            
            } 
        }
        
        
        
    }     
}

/***************************************************************************
    METODOS PARA LA ELIMINACION DE DATOS EN LA LISTA SIMPLE ORDENADA
***************************************************************************/
void Remove(Nodo<T>* n){
    if (n !=NULL && Contain())
    {
        if (n == First)
        {
            //SI SE ELIMINA EL PRIMER NODO
            First = First->Siguiente;
        }
        else if (n == Last)
        {
            //SI SE ELIMINA EL ULTIMO NODO
            Nodo<T>* busqueda = First;
            while (busqueda != NULL)
            {
                if (busqueda->Siguiente == Last)
                {
                    busqueda->Siguiente = NULL;
                    Last = busqueda;
                }else{
                    busqueda = busqueda->Siguiente;
                }                
            }
        }
        else
        {
            //SI SE ELIMINA CUALQUIER NODO
            Nodo<T>* busqueda = First;
            while (busqueda != NULL)
            {
                if (busqueda->Siguiente == n)
                {
                    busqueda->Siguiente = n->Siguiente;                    
                }else{
                    busqueda = busqueda->Siguiente;
                }                
            }
        }        
    }    
}
//Metodo para eliminar un nodo segun su posicion
void RemoveAt(int index){
    Remove(Index(index));
}

/***********************************************************************
    METODOS PARA LA COMPROBACION DE DATOS Y DESPLIEGE EN PANTALLA
***********************************************************************/
bool Contain(){
    bool toReturn = true;
    if (First == NULL)
    {
        toReturn = false;
    }
    return toReturn;
}

int Size(){
    Nodo<T>* aux = First;
    int contador=0;
    while (aux != NULL)
    {
        contador++;
        aux=aux->Siguiente;
    }
    return contador;
}
/***********************************************************************
    METODOS PARA LA BUSCAR DE DATOS EN LA LISTA SIMPLE ORDENADA
            TODOS LOS METODOS DE BUSCAR DEVUELVEN UN NODO
***********************************************************************/
//Metodo publico para buscar un nodo SEGUN: Su contenido
Nodo<T>* Find(T dato){
    Nodo<T>* aux = First;
    Nodo<T>* encontrado=NULL;
    while (aux != NULL)
    {
        if (aux->Dato == dato)
        {
            encontrado = aux;
            aux=NULL;
        }else{
            aux=aux->Siguiente;
        }        
    }
    return encontrado;
}
//Metodo publico para buscar un nodo SEGUN: su posicion
Nodo<T>* Index(int index){
    Nodo<T>* aux = First;
    Nodo<T>* encontrado = NULL;
    int contadorIndex = 0;
    if (index > Size())
    {
        cout<<"El indice introducido es mayor a la longitud de la lista"<<endl;
    }else{
        while (aux != NULL)
        {
            if (contadorIndex == index)
            {
                encontrado = aux;
                aux=NULL;
            }else{
                contadorIndex++;
                aux = aux->Siguiente;
            }        
        }
    }    
    return encontrado;
}
};