#include <stdio.h>

using namespace std;

template <typename T> class Matrix
{
    template <typename T> struct Nodo
    {
        T Dato;
        int X, Y;
        Nodo* Siguiente;
        Nodo* Anterior;
        Nodo* Abajo;
        Nodo* Arriba;
    };
private:
    Nodo<T>* Raiz;
    Nodo<T>* CabezaColumn;
    Nodo<T>* CabezaFila;

    Nodo<T>* BuscarColumna(int x){
        Nodo<T>* temp = CabezaColumn;
        Nodo<T>* encontrado = NULL;
        while (temp != NULL)
        {
            if (temp->X == x)
            {
                encontrado = temp;
                break;
            }else{
                temp = temp->Siguiente;
            }           
        }
        return encontrado;
    }
    Nodo<T>* BuscarFila(int y){
        Nodo<T>* temp = CabezaFila;
        Nodo<T>* encontrado = NULL;
        while (temp != NULL)
        {
            if (temp->Y == y)
            {
                encontrado = temp;
                break;
            }else{
                temp = temp->Abajo;
            }           
        }
        return encontrado;
    }
    void InsertarColumna(int x){
        Nodo<T>* nuevo = new Nodo<T>();
        nuevo->X = x;
        nuevo->Y = -1;
        Nodo<T>* temp;
        //SI NO HAY COLUMNAS SE INSETA DESPUES DE RAIZ
        if (CabezaColumn == NULL)
        {
            Raiz->Siguiente = nuevo;
            nuevo->Anterior = Raiz;
            nuevo->Siguiente = NULL;
            CabezaColumn = nuevo;
        }else{
            //AÑADIR DE MENOR A MAYOR
            //SI ES MENOR QUE LA CABEZA
            if (nuevo->X < CabezaColumn->X)
            {
                nuevo->Siguiente = CabezaColumn;
                nuevo->Anterior = Raiz;
                Raiz->Siguiente = nuevo;
                CabezaColumn->Anterior = nuevo;
                CabezaColumn = nuevo;
            }else{
                temp = CabezaColumn;
                while (temp != NULL)
                {
                    if (temp->Siguiente == NULL)
                    {
                        //SE INSERTA DE ULTIMO
                        nuevo->Siguiente = NULL;
                        nuevo->Anterior = temp;
                        temp->Siguiente = nuevo;
                        break;
                    }
                    else if (nuevo->X > temp->X && nuevo->X < temp->Siguiente->X)
                    {
                        //SE INSERTA ENTRE NODOS
                        nuevo->Anterior = temp;
                        nuevo->Siguiente = temp->Siguiente;
                        temp->Siguiente->Anterior = nuevo;
                        temp->Siguiente = nuevo;
                        break;
                    }
                    else
                    {
                        temp = temp->Siguiente;
                    }
                }
            }
        }
    }
    void InsertarFila(int y){
        Nodo<T>* nuevo = new Nodo<T>();
        nuevo->X = -1;
        nuevo->Y = y;
        Nodo<T>* temp;
        //SI NO HAY COLUMNAS SE INSETA DESPUES DE RAIZ
        if (CabezaFila == NULL)
        {
            Raiz->Abajo = nuevo;
            nuevo->Arriba = Raiz;
            nuevo->Abajo = NULL;
            CabezaFila = nuevo;
        }else{
            //AÑADIR DE MENOR A MAYOR
            //SI ES MENOR QUE LA CABEZ
            if (nuevo->Y < CabezaFila->Y)
            {
                nuevo->Abajo = CabezaFila;
                nuevo->Arriba = Raiz;
                Raiz->Abajo = nuevo;
                CabezaFila->Arriba = nuevo;
                CabezaFila = nuevo;
            }else{
                temp = CabezaFila;
                while (temp != NULL)
                {
                    if (temp->Abajo == NULL)
                    {
                        //SE INSERTA DE ULTIMO
                        nuevo->Abajo = NULL;
                        nuevo->Arriba = temp;
                        temp->Abajo = nuevo;
                        break;
                    }
                    else if (nuevo->Y > temp->Y && nuevo->Y < temp->Abajo->Y)
                    {
                        //SE INSERTA ENTRE NODOS
                        nuevo->Arriba = temp;
                        nuevo->Abajo = temp->Abajo;
                        temp->Abajo->Arriba = nuevo;
                        temp->Abajo = nuevo;
                        break;
                    }
                    else
                    {
                        temp = temp->Abajo;
                    }
                }
            }
        }
    }
    Nodo<T>* GetPosition(int X, int Y){
        Nodo<T>* toReturn = NULL;
        Nodo<T>* aux = CabezaColumn;
        while (aux != NULL)
        {
            if (aux->X == X)
            {
                Nodo<T>* aux2 = aux;
                while (aux2 != NULL)
                {
                    if (aux2->Y == Y)
                    {
                        toReturn = aux2;
                        break;
                    }else{
                        aux2 = aux2->Abajo;
                    }              
                }
                break;           
            }else{
                aux = aux->Siguiente;
            }       
        }
        return toReturn;
    }
    void AfterRemove(){
        if (Raiz->Siguiente == NULL && Raiz->Abajo == NULL)
        {
            CabezaColumn = NULL;
            CabezaFila = NULL;
        }else{
            if (Raiz->Siguiente == NULL)
            {
                CabezaColumn = NULL;
            }else if (Raiz->Abajo == NULL)
            {
                CabezaFila = NULL;
            }
        }
    }


public:
Matrix(){
    Nodo<T>* init = new Nodo<T>();
    init->X = -1;
    init->Y = -1;
    Raiz = init;
    CabezaColumn = NULL;
    CabezaFila = NULL;
}

//Añade un dato a la matriz en la posicion especificada por el usuario
void Add(T Value, int X, int Y){
    Nodo<T>* nuevo = new Nodo<T>();
    nuevo->X = X;
    nuevo->Y = Y;
    nuevo->Dato = Value;
    //VERIFICAMOS QUE EXISTAN COLUMNAS O FILAS SI NO SE AGREGAN
    if (BuscarColumna(X) == NULL)
    {
        //LA COLUMNA NO EXISTE ASI QUE SE LA AGREGAMOS
        InsertarColumna(X);
        Nodo<T>* tempoColumna = BuscarColumna(X);
        tempoColumna->Abajo = nuevo;
        nuevo->Arriba = tempoColumna;
    }else{
        Nodo<T>* tempoCol = BuscarColumna(X)->Abajo;
        if (nuevo->Y < tempoCol->Y)
        {
            //SI ES MENOR SE CONECTA CON LA
            nuevo->Abajo = tempoCol;
            nuevo->Arriba = tempoCol->Arriba;
            tempoCol->Arriba->Abajo = nuevo;
            tempoCol->Arriba = nuevo;
        }else{
            while (tempoCol != NULL)
            {
                if (tempoCol->Abajo == NULL)
                {
                    //SE INSERTA DE ULTIMO
                    nuevo->Abajo = NULL;
                    nuevo->Arriba = tempoCol;
                    tempoCol->Abajo = nuevo;
                    break;
                }
                else if (nuevo->Y > tempoCol->Y && nuevo->Y < tempoCol->Abajo->Y)
                {
                    //SE INSERTA ENTRE NODOS
                    nuevo->Arriba = tempoCol;
                    nuevo->Abajo = tempoCol->Abajo;
                    tempoCol->Abajo->Arriba = nuevo;
                    tempoCol->Abajo = nuevo;
                    break;
                }
                else
                {
                    tempoCol = tempoCol->Abajo;
                }
            }            
        }     
    }

    if (BuscarFila(Y) == NULL)
    {
        InsertarFila(Y);
        Nodo<T>* tempoFila = BuscarFila(Y);
        tempoFila->Siguiente = nuevo;
        nuevo->Anterior = tempoFila;
    }else{
        Nodo<T>* tempoFIL = BuscarFila(Y);
        if (nuevo->X < tempoFIL->X)
        {
            //SI ES MENOR SE CONECTA CON LA
            nuevo->Siguiente = tempoFIL;
            nuevo->Anterior = tempoFIL->Anterior;
            tempoFIL->Anterior->Siguiente = nuevo;
            tempoFIL->Anterior = nuevo;
        }else{
            while (tempoFIL != NULL)
            {
                if (tempoFIL->Siguiente == NULL)
                {
                    //SE INSERTA DE ULTIMO
                    nuevo->Siguiente = NULL;
                    nuevo->Anterior = tempoFIL;
                    tempoFIL->Siguiente = nuevo;
                    break;
                }
                else if (nuevo->X > tempoFIL->X && nuevo->X < tempoFIL->Siguiente->X)
                {
                    //SE INSERTA ENTRE NODOS
                    nuevo->Anterior = tempoFIL;
                    nuevo->Siguiente = tempoFIL->Siguiente;
                    tempoFIL->Siguiente->Anterior = nuevo;
                    tempoFIL->Siguiente = nuevo;
                    break;
                }
                else
                {
                    tempoFIL = tempoFIL->Siguiente;
                }
            }            
        }
    }
    
       
}
//Retorna true si el valor existe en la posicion especificada por el usuario
bool Position(int X, int Y){
    bool toReturn = false;
    Nodo<T>* aux = CabezaColumn;
    while (aux != NULL)
    {
        if (aux->X == X)
        {
            Nodo<T>* aux2 = CabezaFila;
            while (aux2 != NULL)
            {
                if (aux2->Y == Y)
                {
                    toReturn = true;
                    break;
                }else{
                    aux2 = aux2->Abajo;
                }              
            }
            break;          
        }else{
            aux = aux->Siguiente;
        }       
    }
    return toReturn;
    
}
//Retorna el valor en la posicion especificada por el usuario
T ValueAt(int X, int Y){
    Nodo<T>* toReturn = NULL;
    Nodo<T>* aux = CabezaColumn;
    while (aux != NULL)
    {
        if (aux->X == X)
        {
            Nodo<T>* aux2 = aux;
            while (aux2 != NULL)
            {
                if (aux2->Y == Y)
                {
                    toReturn = aux2;
                    break;
                }else{
                    aux2 = aux2->Abajo;
                }              
            }
            break;           
        }else{
            aux = aux->Siguiente;
        }       
    }
    
    if (toReturn == NULL)
    {
        return Raiz->Dato;
    }else{
        return toReturn->Dato;
    }
      
}
//Elimina el valor en la posicion especificada por el usuario
void Remove(int X, int Y){
    Nodo<T>* node = GetPosition(X, Y);
    //Eliminamos en columna
    if (node != NULL)
    {
    if (node->Abajo == NULL && node->Arriba->Y == -1 && node->Arriba->Siguiente == NULL)
    {
        //si el de abajo es nulo y el de arriba es la cabeza de la columna entonces eliminamos la columna
        //CASO DE ELIMINAR LA ULTIMA COLUMNA CON EL DATO
        node->Arriba->Anterior->Siguiente = NULL;
    }else if (node->Abajo == NULL && node->Arriba == CabezaColumn)
    {
       //si el de abajo es nulo y el de arrbia es la cabeza de la columna principal, eliminaos la columna con el dat
       //CASO DE ELIMINAR LA PRIMERA COLUMNA CON EL DATO
       if (CabezaColumn->Siguiente == NULL)
       {
           //SI LA CABEZA ES LA ULTIMA COLUMNA
            CabezaColumn = NULL;
            Raiz->Siguiente = NULL;
       }else{
           //CASO CONTRARIO
            CabezaColumn = CabezaColumn->Siguiente;
            Raiz->Siguiente = CabezaColumn;
            CabezaColumn->Anterior = Raiz;
       }      
    }else if (node->Abajo == NULL && node->Arriba->Y == -1 && node->Arriba->Siguiente != NULL)
    {
        //si el de abajo es nulo y el de arriba es la cabeza de la columna no final y no inicial, se elimina con el dato
        //CASO DE ELIMINAR CUALQUIER COLUMNA CON EL DATO
        node->Arriba->Anterior->Siguiente = node->Arriba->Siguiente;
        node->Arriba->Siguiente->Anterior = node->Arriba->Anterior;
    }else{
        //CASO DE ELIMINAR SOLO EL DATO
        if (node->Abajo == NULL)
        {
            node->Arriba->Abajo = NULL;
        }else{
            node->Arriba->Abajo = node->Abajo;
            node->Abajo->Arriba = node->Arriba;
        }       
    }

    //Eliminamos en Fila
    if (node->Siguiente == NULL && node->Anterior->X == -1 && node->Anterior->Abajo == NULL)
    {
        //si el de abajo es nulo y el de arriba es la cabeza de la fila entonces eliminamos la fila con el dato
        //CASO DE ELIMINAR LA ULTIMA FILA CON EL DATO
        node->Anterior->Arriba->Abajo = NULL;
        //Nodo<T>* tempColumna = node->Arriba;
    }else if (node->Siguiente == NULL && node->Anterior == CabezaFila)
    {
       //si el de abajo es nulo y el de arrbia es la cabeza de la fila principal, eliminaos la fila con el dat
       //CASO DE ELIMINAR LA PRIMERA FILA CON EL DATO
       if (CabezaFila->Abajo == NULL)
       {
           //SI LA CABEZA ES LA ULTIMA FILA
            CabezaFila = NULL; 
            Raiz->Abajo = NULL;                       
       }else{
           //CASO CONTRARIO
            CabezaFila = CabezaFila->Abajo;
            Raiz->Abajo = CabezaFila;
            CabezaFila->Arriba = Raiz;
       }      
    }else if (node->Siguiente == NULL && node->Anterior->X == -1 && node->Anterior->Abajo != NULL)
    {
        //si el de abajo es nulo y el de arriba es la cabeza de la fila no final y no inicial, se elimina con el dato
        //CASO DE ELIMINAR CUALQUIER FILA CON EL DATO
        node->Anterior->Arriba->Abajo = node->Anterior->Abajo;
        node->Anterior->Abajo->Arriba = node->Anterior->Arriba;
    }else{
        //CASO DE ELIMINAR SOLO EL DATO
        if (node->Siguiente == NULL)
        {
            node->Anterior->Siguiente = NULL;
        }else{
            node->Anterior->Siguiente = node->Siguiente;
            node->Siguiente->Anterior = node->Anterior;
        }       
    }
    AfterRemove(); 
    }else{
    cout<<"No existe valores en la posicion especificada";
    }     
}
//Vacia la matriz dispersa
void Clear(){
    Raiz->Siguiente = NULL;
    Raiz->Abajo = NULL;
    CabezaColumn = NULL;
    CabezaFila = NULL;
}
//Retorna un valor booleano, true si tiene datos, false si no tiene datos
bool Contain(){
    if (CabezaColumn == NULL && CabezaFila == NULL)
    {
        return false;
    }else{
        return true;
    }
    
}
};