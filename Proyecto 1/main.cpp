#include "Estructuras/LinkedList.h"
#include "Estructuras/CircleLinkedList.h"
#include "Estructuras/OrderList.h"
#include "Estructuras/Queue.h"
#include "Estructuras/BinaryTree.h"
#include "Estructuras/Matrix.h"
#include "Clases/Ficha.h"
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <fstream>


using namespace std;

//VARIABLES QUE SE DEFINEN CON ARCHIVO DE CONFIGUARCION
LinkedList<string>* Diccionario = new LinkedList<string>();
/*Matrix<Ficha> Dobles;
Matrix<Ficha> Triples;
Matrix<Ficha> Tablero;*/
//VARIABLES YA DEFINIDAS DEL JUEGO
Queue<Ficha>* Fichas = new Queue<Ficha>();
int DimensionX=0, DimensionY=0;
//DEFINICION DE METODOS
void EstablecerColaFichas();
void MenuPrincipal();
void PintarMarco();
void Gotoxy(int x, int y);

//DESARROLLO DE METODOS
void EstablecerColaFichas(){
    int c;
    LinkedList<int>* numerosSeleccionados = new LinkedList<int>();
    srand(time(NULL));
    for (int i = 0; i < 95; i++)
    {
        c = 1+rand() % (96-1);        
        if (numerosSeleccionados->Find(c) == NULL)
        {
            numerosSeleccionados->AddLast(c);
            if (c >= 1 && c <= 12)
            {
                Ficha* aux = new Ficha('A',1);                
                Fichas->Enqueue(aux);
            }
            else if (c >= 13 && c <= 24)
            {
                Ficha* aux = new Ficha('E',1);
                Fichas->Enqueue(aux);                
            }           
            else if (c >= 25 && c <= 33)
            {
                Ficha* aux = new Ficha('O',1);
                Fichas->Enqueue(aux);                
            }
            else if (c >= 34 && c <= 39)
            {
                Ficha* aux = new Ficha('I',1);
                Fichas->Enqueue(aux);                
            }
            else if (c >= 40 && c <= 45)
            {
                Ficha* aux = new Ficha('S',1);
                Fichas->Enqueue(aux);                
            }
            else if (c >= 46 && c <= 50)
            {
                Ficha* aux = new Ficha('N',1);
                Fichas->Enqueue(aux);                
            }
            else if (c >= 51 && c <= 54)
            {
                Ficha* aux = new Ficha('L',1);
                Fichas->Enqueue(aux);                
            }
            else if (c >= 55 && c <= 59)
            {
                Ficha* aux = new Ficha('R',1);
                Fichas->Enqueue(aux);                
            }
            else if (c >= 60 && c <= 64)
            {
                Ficha* aux = new Ficha('U',1);
                Fichas->Enqueue(aux);                
            }
            else if (c >= 65 && c <= 68)
            {
                Ficha* aux = new Ficha('T',1);
                Fichas->Enqueue(aux);                
            }
            else if (c >= 69 && c <= 73)
            {
                Ficha* aux = new Ficha('D',2);
                Fichas->Enqueue(aux);                
            }
            else if (c >= 74 && c <= 75)
            {
                Ficha* aux = new Ficha('G',2);
                Fichas->Enqueue(aux);                
            }
            else if (c >= 76 && c <= 79)
            {
                Ficha* aux = new Ficha('C',3);
                Fichas->Enqueue(aux);                
            }
            else if (c >= 80 && c <= 81)
            {
                Ficha* aux = new Ficha('B',3);
                Fichas->Enqueue(aux);                
            }
            else if (c >= 82 && c <= 83)
            {
                Ficha* aux = new Ficha('M',3);
                Fichas->Enqueue(aux);                
            }
            else if (c >= 84 && c <= 85)
            {
                Ficha* aux = new Ficha('P',3);
                Fichas->Enqueue(aux);                
            }
            else if (c >= 86 && c <= 87)
            {
                Ficha* aux = new Ficha('H',4);
                Fichas->Enqueue(aux);                
            }
            else if (c == 88)
            {
                Ficha* aux = new Ficha('F',4);
                Fichas->Enqueue(aux);                
            }
            else if (c == 89)
            {
                Ficha* aux = new Ficha('V',4);
                Fichas->Enqueue(aux);                
            }
            else if (c == 90)
            {
                Ficha* aux = new Ficha('Y',4);
                Fichas->Enqueue(aux);                
            }
            else if (c == 91)
            {
                Ficha* aux = new Ficha('Q',5);
                Fichas->Enqueue(aux);                
            }
            else if (c == 92)
            {
                Ficha* aux = new Ficha('J',8);
                Fichas->Enqueue(aux);                
            }
            else if (c == 93)
            {
                Ficha* aux = new Ficha((char)165,8);
                Fichas->Enqueue(aux);                
            }
            else if (c == 94)
            {
                Ficha* aux = new Ficha('X',8);
                Fichas->Enqueue(aux);                
            }
            else if (c == 95)
            {
                Ficha* aux = new Ficha('Z',10);
                Fichas->Enqueue(aux);                
            }
        }else{
            i--;
        }       
    }    
}

void MenuPrincipal(){
    char a;
	PintarMarco();
    Gotoxy(5,3);cout<<"UNIVERSIDAD DE SAN CARLOS DE GUATEMALA";
	Gotoxy(5,4);cout<<"FACULTAD DE INGENIERIA";
	Gotoxy(5,5);cout<<"ESTRUCTURAS DE DATOS";
	Gotoxy(5,6);cout<<"PROYECTO 1";
	Gotoxy(5,7);cout<<"ALDO RIGOBERTO HERNANDEZ AVILA";
	Gotoxy(5,8);cout<<"201800585";
    Gotoxy(5,10);cout<<"MEN"<<(char)233;
	Gotoxy(5,11);cout<<"1. Archivo de Configuracion";
	Gotoxy(5,12);cout<<"2. Jugar";
	Gotoxy(5,13);cout<<"3. Reportes";
	Gotoxy(5,14);cout<<"4. Salir"<<endl;
	Gotoxy(5,15);
    cin >> a;
    if (a == '1')
    {
		system("cls");
		PintarMarco();
		//ControlesEditorTexto();    	
		//ModoEditorTexto();  
	}
	else if (a == '2')
	{
		system("cls");
		PintarMarco();
		//ModoAbrirArchivo();
	}
	else if (a == '3')
	{
		
		system("cls");
		PintarMarco();
		//ModoArchivosRecientes();
	}
	else if(a == '4')
	{
		exit(0);
	}
}

void PintarMarco(){
	Gotoxy(3, 2);cout<<(char)201;
	for (int i = 0; i < 25; i++)
	{
		Gotoxy(3, 3+i);cout<<(char)186;
	}	
}

void Gotoxy(int x,int y){
	HANDLE hCon;
	hCon=GetStdHandle(STD_OUTPUT_HANDLE);	
	COORD dwPos;
	dwPos.X=x;
	dwPos.Y=y;	
	SetConsoleCursorPosition(hCon,dwPos);
}



//METODO PRINCIPAL
int main()
{   
    EstablecerColaFichas();
    MenuPrincipal();
    cin.get();
    cin.ignore();
       
}
