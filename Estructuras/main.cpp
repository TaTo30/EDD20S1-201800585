#include "LinkedList.h"
#include "CircleLinkedList.h"
#include "OrderList.h"
#include "Queue.h"
#include "BinaryTree.h"
#include <stdio.h>
#include <string.h>
#include "Matrix.h"

using namespace std;

int main()
{
   Matrix<string> matriz;
   matriz.Add("A",0,0);
   matriz.Add("B",1,4);
   matriz.Add("D",0,8);
   matriz.Add("C",5,0);
   matriz.Add("E",2,0);
   matriz.Add("F",0,2);

   cout<<matriz.ValueAt(0,0)<<'\n';
   cout<<matriz.ValueAt(1,4)<<'\n';
   cout<<matriz.ValueAt(0,8)<<'\n';
   cout<<matriz.ValueAt(5,0)<<'\n';
   cout<<matriz.ValueAt(2,0)<<'\n';
   cout<<matriz.ValueAt(0,2)<<'\n';
   cout<<matriz.ValueAt(7,4)<<endl;

   cout<<matriz.Position(7,4)<<'\n';
   cout<<matriz.Position(0,0)<<'\n';

   matriz.Remove(0,8);
   matriz.Remove(1,4);
   matriz.Remove(5,0);
   matriz.Remove(0,0);
   matriz.Remove(2,0);
   matriz.Remove(0,2);
   matriz.Remove(7,4);
   matriz.Add("C",5,0);
   matriz.Add("E",2,0);

   matriz.Clear();
   cout<<matriz.Contain();


    


    cin.get();
    cin.ignore();
 
}
