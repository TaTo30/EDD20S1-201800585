#include "LinkedList.h"
#include "CircleLinkedList.h"
#include "OrderList.h"
#include "Queue.h"
#include "BinaryTree.h"
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
    /*CircleLinkedList<int> lista;
    lista.AddFirst(0);
    lista.AddLast(1);
    lista.AddLast(2);
    lista.AddBeforeAt(lista.Find(2),3);
    lista.AddAfterAt(lista.Find(2),4);
    lista.Remove(lista.GetFirst());
    lista.Remove(lista.GetLast());
    lista.Remove(lista.Index(0));
    cout<<lista.Size()<<'\n';
    lista.Imprimir();*/

   /* OrderList<string> lista;
    lista.Add("Joseph",50);
    lista.Add("Ricardo",25);
    lista.Add("Mavin",24);
    lista.Add("Daniel",5);
    lista.Add("Chirs",22);
    lista.Add("Eva",12);
    lista.Add("Tato",100);
    cout<<lista.Min()->dato<<'\n';
    cout<<lista.Max()->dato<<'\n';
    lista.Remove(lista.Find("Chris"));
    lista.RemoveAt(0);*/

    /*Queue<int> cola;
    cola.Enqueue(0);
    cola.Enqueue(1);
    cola.Enqueue(2);
    cola.Enqueue(3);
    cout<<cola.Dequeue()->dato<<endl;
    cout<<cola.Dequeue()->dato<<endl;
    cout<<cola.Dequeue()->dato<<endl;
    cout<<cola.Dequeue()->dato<<endl;
    cout<<cola.Size()<<endl;
    cout<<cola.Contain()<<endl;

    Queue<string> colaString;
    colaString.Enqueue("Aldo");
    colaString.Enqueue("Rigoberto");
    colaString.Enqueue("Hernandez");
    cout<<colaString.Dequeue()->dato<<endl;*/

    /*BinaryTree<int> arbol;
    arbol.Add(3,3);
    arbol.Add(7,7);
    arbol.Add(4,4);
    arbol.Add(10,10);
    arbol.Add(5,5);
    arbol.Add(16,16);
    arbol.Add(6,6);
    arbol.Add(1,1);

    arbol.Remove(6);
    arbol.Remove(4);
    arbol.Remove(7);*/
    /*
    BinaryTree<string> jugadores;
    jugadores.Add("Heidy", (int)'H');
    jugadores.Add("Carlos", (int)'C');
    jugadores.Add("Rodrigo", (int)'R');
    jugadores.Add("Antonio", (int)'A');
    jugadores.Add("Eduardo", (int)'E');
    

    jugadores.Remove((int)'C');
    */
    


    cin.get();
    cin.ignore();
 
}
