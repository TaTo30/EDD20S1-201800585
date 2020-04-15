#include <stdio.h>

using namespace std;
template <typename T> class LinkedList
{   
    template <typename T> struct Nodo
    {   
        T* dato;
        Nodo* Anterior;
        Nodo* Siguiente;        
    };
private:   
    Nodo<T>* First;
    Nodo<T>* Last;
    //Metodo privado general para insertar datos
void Add(Nodo<T>* n, T* dato_, bool pos){
    Nodo<T>* aux = new Nodo<T>();
    aux->dato = dato_;    
    if (Verificar() && n == NULL)
    {
        cout<<"Error: esta intentado agregar un Nodo vacio, verifique la lista"<<endl;
    }else{    
        if (First == NULL)
        {
            //LISTA VACIA
            First = aux;
            Last = aux;
        }else if(n == First && pos){
            //INSERTAR INICIO DE LA LISTA
            aux->Siguiente = First;
            First->Anterior = aux;
            First = aux;
        }else if(n == Last && !pos){
            //INSERTAR FINAL DE LA LISTA
            aux->Anterior = Last;
            Last->Siguiente = aux;
            Last = aux;
        }else if(pos){
            //INSERTAR ANTES DE UN NODO
            aux->Anterior = n->Anterior;
            n->Anterior->Siguiente = aux;
            n->Anterior = aux;
            aux->Siguiente = n;
        }else{
            //INSERTAR DESPUES DE UN NODO
            aux->Siguiente = n->Siguiente;
            n->Siguiente->Anterior = aux;
            n->Siguiente = aux;
            aux->Anterior = n;     
        }  
    }
}

    //Metodo privado para la ubicacion de nodos por datos
Nodo<T>* Find(T* dato){
    Nodo<T>* aux = First;
    Nodo<T>* encontrado=NULL;
    while (aux != NULL)
    {
        if (aux->dato == dato)
        {
            encontrado = aux;
            aux=NULL;
        }else{
            aux=aux->Siguiente;
        }        
    }
    return encontrado;    
}

    //Metodo privado para la ubicacion de nodos por indicie
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

    //Metodo privado general para eliminar datos
void Remove(Nodo<T>* n){
    if (!Verificar() || n != NULL)
    {   
        if (n == First && n == Last)
        {
            //ELIMINA EL ULTIMO NODO: LISTA VACIA
            First = NULL;
            Last = NULL;
            delete n;
        }        
        else if (n == First)
        {
            //ELIMINAR EL PRIMER NODO
            First = First->Siguiente;
            First->Anterior = NULL;
            delete n;
        }
        else if (n == Last)
        {
            //ELIMINAR EL SEGUNDO NODO
            Last = Last->Anterior;
            Last->Siguiente = NULL;
            delete n;
        }
        else
        {
            //ELIMINAR CUALQUIER NODO
            n->Anterior->Siguiente = n->Siguiente;
            n->Siguiente->Anterior = n->Anterior;
            delete n;
        }        
    }else{
        cout<<"Error: el nodo no se encuentra en la lista"<<endl;
    }    
}
public:  

//Constructor de Lista
LinkedList(){
    First = NULL;
    Last = NULL;
}

/*************************************************************************
    METODOS PARA LA INSERSION DE DATOS EN LA LISTA DOBLEMENTE ENLAZADA
*************************************************************************/

//Inserta un valor al inicio de la lista
void AddFirst(T* data){
    Add(First, data, true);
}
//Inserta un valor al final de la lista
void AddLast(T* data){
    Add(Last, data, false);
}
//Inserta un valor antes de un valor especificado por el usuario
void AddBeforeAt(T* reference, T* data){
    Add(Find(reference),data, true);
}
//Inserta un valor despues de un valor especificado por el usuario
void AddAfterAt(T* reference, T* data){
    Add(Find(reference), data, false);
}


/***************************************************************************
    METODOS PARA LA ELIMINACION DE DATOS EN LA LISTA DOBLEMENTE ENLAZADA
***************************************************************************/

//Eliminar un valor en el indice establecido
void RemoveAt(int index){
    Remove(Index(index));
}
//Elimina el ultimo valor de la lista
void RemoveLast(){
    Remove(Last);
}
//Elimina el primer valor de la lista
void RemoveFirst(){
    Remove(First);
}
//Elimina un valor por elemento especificado por el usuario
void RemoveElement(T* data){
    Remove(Find(data));
}


/***********************************************************************
    METODOS PARA LA BUSCAR DE DATOS EN LA LISTA DOBLEMENTE ENLAZADA
            TODOS LOS METODOS DE BUSCAR DEVUELVEN UN NODO
***********************************************************************/

//Devuelve el valor del dato en el indice especificado por el usuario
T* ElementAt(int index){
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
    return encontrado->dato;
}
//Devuelve el primer dato de la lista
T* GetFirst(){
    return First->dato;
}
//Devuelve el ultimo dato de la lista
T* GetLast(){
    return Last->dato;
}


/***********************************************************************
    METODOS PARA LA COMPROBACION DE DATOS Y DESPLIEGE EN PANTALLA
***********************************************************************/

//Devuelve un valor bool, true si la lista contiene datos, false si no contiene datos
bool Contain(){
    if (First == NULL)
    {
        return false;
    }else{
        return true;
    }
    
}
//Devuelve el valor correspondiente al tamaño de la lista
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
//Vacia la lista
void Clear(){    
    Nodo<T>* aux = First;
    while (aux!=NULL)
    {
        Remove(aux);
        aux = First;
    }
    First = NULL;
    Last = NULL;
}
};
