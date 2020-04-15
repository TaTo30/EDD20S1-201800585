#include<stdio.h>
#include<iostream>

using namespace std;

template <typename T> class BinaryTree
{
    template <typename T> struct Nodo
    {
        T Dato;
        int Key;
        Nodo* HijoDerecho;
        Nodo* HijoIzquierdo;
    };
private:
    Nodo<T>* Raiz;
Nodo<T>* AddRecursive(Nodo<T>* raiz, T dato, int key)
{
    if (raiz == NULL)
    {
        //SI LA RAIZ (O CUALQUIER NODO RAIZ) ESTA VACIA AÑADIR EL NODO
        Nodo<T>* aux = new Nodo<T>();
        aux->Dato = dato;
        aux->Key = key;
        raiz = aux;
    }
    else if (key < raiz->Key)
    {
        //SI LA LLAVE ES MAS PEQUEÑA INSERTAR EN LOS SUBARBOLES IZQUIERDO
        raiz->HijoIzquierdo = AddRecursive(raiz->HijoIzquierdo,dato,key);
    }
    else if (key > raiz->Key)
    {
        //SI LA LLAVE ES MAS PEQUEÑA INSERTAR EN LOS SUBARBOLES DERECHOS
        raiz->HijoDerecho = AddRecursive(raiz->HijoDerecho,dato,key);
    }
    else
    {
        cout<<"Hay un hijo duplicado \n";
    }
    return raiz;
}
Nodo<T>* RemoveRecursive(Nodo<T>* raiz, int key)
{
    if (raiz == NULL)
    {
        //SI LA RAIZ ES NULA DEVOLVEMOS EL DATO
        return raiz;
    }
    else if (key < raiz->Key)
    {
        //SI LA LLAVE ES MENOR A LA LLAVE DEL NODO RAIZ, SEGUIMOS BUSCANDO POR SUBARBOL IZQUIERDO
        raiz->HijoIzquierdo = RemoveRecursive(raiz->HijoIzquierdo,key);
    }
    else if (key > raiz->Key)
    {
        //SI LA LLAVE ES MENOR A LA LLAVE DEL NODO RAIZ, SEGUIMOS BUSCANDO POR SUBARBOL IZQUIERDO
        raiz->HijoDerecho = RemoveRecursive(raiz->HijoDerecho,key);
    }else{
        //SI SON IGUALES ELIMINAMOS EL NODO
        //SI EL NODO TIENE 0 O UN HIJO
        if (raiz->HijoIzquierdo == NULL)
        {
            return raiz->HijoDerecho;
        }else if (raiz->HijoDerecho == NULL)
        {
            return raiz->HijoIzquierdo;
        }else{
            //SI TIENE 2 HIJOS
            raiz->Key = minValue(raiz->HijoDerecho);
            raiz->Dato = MinValueData(raiz->HijoDerecho);
            raiz->HijoDerecho = RemoveRecursive(raiz->HijoDerecho, raiz->Key);
        }
    }
    return raiz;
}
int minValue(Nodo<T>* raiz){
    int min = raiz->Key;
    while (raiz->HijoIzquierdo != NULL)
    {
        min = raiz->HijoIzquierdo->Key;
        raiz = raiz->HijoIzquierdo;
    }
    return min;    
}
T MinValueData(Nodo<T>* raiz){
    T dato = raiz->Dato;
    while (raiz->HijoIzquierdo != NULL)
    {
        dato = raiz->HijoIzquierdo->Dato;
        raiz = raiz->HijoIzquierdo;
    }
    return dato;
}

public:
//CONSTRUCTOR
BinaryTree(){
    Raiz=NULL;
}

//Inserta un dato en el arbol binario
void Add(T dato, int key){
    Raiz = AddRecursive(Raiz,dato,key);
}
//Elimina un dato en el arbol binario
void Remove(int key){
    Raiz = RemoveRecursive(Raiz,key);
}

};