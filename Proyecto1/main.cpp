#include "Estructuras/LinkedList.h"
#include "Estructuras/CircleLinkedList.h"
//#include "Estructuras/OrderList.h"
#include "Estructuras/Queue.h"
#include "Estructuras/BinaryTree.h"
#include "Estructuras/Matrix.h"
//#include "Clases/Ficha.h"
#include "Clases/Jugador.h"
#include "Paquetes/json.hpp"
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#define ENTER 13



using namespace std;
using json = nlohmann::json;

//VARIABLES QUE SE DEFINEN CON ARCHIVO DE CONFIGUARCION
LinkedList<string>* Diccionario = new LinkedList<string>();
Matrix<Ficha>* CasillasDobles = new Matrix<Ficha>();
Matrix<Ficha>* CasillasTriples = new Matrix<Ficha>();  
Matrix<Ficha>* Tablero = new Matrix<Ficha>();
BinaryTree<Jugador>* Jugadores = new BinaryTree<Jugador>();
//VARIABLES YA DEFINIDAS DEL JUEGO
Queue<Ficha>* Fichas = new Queue<Ficha>();
int DimensionX=0, DimensionY=0;
//DEFINICION DE METODOS
void EstablecerColaFichas();
void MenuPrincipal();
void PintarMarco();
void Gotoxy(int x, int y);
void ModoAbrirArchivoJson();
void ModoAgregarUsuario();
void MenuReportes();
string ArbolJugadores(BinaryTree<Jugador>::Nodo<Jugador>* raiz);

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

void ModoAgregarUsuario(){
    string username;
    Gotoxy(5,1);cout<<"[Nombre de Usuario]: ";cin>>username;
    if (!Jugadores->Find((int)username[0]))
    {
        Jugador* aux = new Jugador(username);
        Jugadores->Add(aux,(int)username[0]);
        Gotoxy(5,2);cout<<(char)173<<(char)173<<"Usuario Agregado con Exito!!";
        char tecla =' ';
        while (tecla != ENTER)
        {
            if (kbhit())
            {
                tecla = getch();
            }       
        }
        system("cls");
        MenuPrincipal();
    }
    else
    {
        Gotoxy(5,2);cout<<(char)173<<(char)173<<"Nombre de Usuario no permitido!!";
        char tecla =' ';
        while (tecla != ENTER)
        {
            if (kbhit())
            {
                tecla = getch();
            }       
        }
        system("cls");
        PintarMarco();
        ModoAgregarUsuario();
    }
}

void MenuReportes(){
    char a;
    Gotoxy(5,2);cout<<"SELECCIONE EL REPORTE QUE DESEA VER";
    Gotoxy(5,3);cout<<"0> Regresar al menu anterior";
    Gotoxy(5,4);cout<<"1> Diccionario";
    Gotoxy(5,5);cout<<"2> Cola de Fichas";
    Gotoxy(5,6);cout<<"3> Usuarios";
    Gotoxy(5,7);cout<<"4> Usuarios <PreOrden>";
    Gotoxy(5,8);cout<<"5> Usuarios <InOrden>";
    Gotoxy(5,9);cout<<"6> Usuarios <PostOrden>";
    Gotoxy(5,10);cout<<"7> Tablero";
    Gotoxy(5,11);cout<<"8> Diccionario";
    Gotoxy(5,12);cout<<"SELECT> ";cin>>a;
    if (a == '1')
    {
        //REPORTE DICCIONARIO
        string graph = "digraph g { rankdir=LR; node [shape=box];\n";
        for (int i = 0; i < Diccionario->Size(); i++)
        {
            if (Diccionario->Index(i) == Diccionario->GetFirst())
            {
                graph += Diccionario->Index(i)->dato+"->"+Diccionario->Index(i+1)->dato+"\n";
                graph += Diccionario->Index(i)->dato+"->"+Diccionario->GetLast()->dato+"\n";
            }
            else if (Diccionario->Index(i) == Diccionario->GetLast())
            {
                graph += Diccionario->Index(i)->dato+"->"+Diccionario->GetFirst()->dato+"\n";
                graph += Diccionario->Index(i)->dato+"->"+Diccionario->Index(i-1)->dato+"\n";
            }
            else
            {
                graph += Diccionario->Index(i)->dato+"->"+Diccionario->Index(i+1)->dato+"\n";
                graph += Diccionario->Index(i)->dato+"->"+Diccionario->Index(i-1)->dato+"\n";
            }
        }
        graph += "}";
        ofstream o;
        o.open("Dot\\Diccionario.dot");
        o<<graph;
        o.close();
        system("dot -Tpng Dot\\Diccionario.dot -o PNG\\Diccionario.png");
        system("PNG\\Diccionario.png");
        system("cls");
        PintarMarco();
        MenuReportes();        
    }
    else if (a == '2')
    {
        ofstream file;
        file.open("Dot\\ColaFichas.dot");
        file<<"digraph g{ rankdir = LR; node [shape = record]; struct1 [label=\"";
        Queue<Ficha>* temp = Fichas->Clonar();
        int QueueSize = temp->Size();
        for (int i = 0; i < QueueSize; i++)
        {
            Ficha* aux = temp->Dequeue()->dato;
            file<<"<f"<<i<<">"<<aux->GetLetra()<<" x"<<aux->GetPuntaje()<<"|";
        }
        file<<"\"]; }";
        file.close();
        system("dot -Tpng Dot\\ColaFichas.dot -o PNG\\ColaFichas.png");
        system("PNG\\ColaFichas.png");
        system("cls");
        PintarMarco();
        MenuReportes();        
    }
    else if (a == '3')
    {

        BinaryTree<Jugador>::Nodo<Jugador>* temp = Jugadores->GetRoot();
        ;
        string graph = "digraph g{ node [shape = circle];";
        graph += temp->Dato->GetNombre()+";\n";
        graph += ArbolJugadores(temp) +"}";
        ofstream file;
        file.open("Dot\\Jugadores.dot");
        file<<graph;
        file.close();
        system("dot -Tpng Dot\\Jugadores.dot -o PNG\\Jugadores.png");
        system("PNG\\Jugadores.png");
        system("cls");
        PintarMarco();
        MenuReportes();
    }   
}

string ArbolJugadores(BinaryTree<Jugador>::Nodo<Jugador>* raiz){
    if (raiz != NULL)
    {
        string temp="";
        if(raiz->HijoIzquierdo != NULL)
        {
            temp += raiz->Dato->GetNombre()+"->"+raiz->HijoIzquierdo->Dato->GetNombre()+";\n";
        } 
        if (raiz->HijoDerecho != NULL)
        {
            temp += raiz->Dato->GetNombre()+"->"+raiz->HijoDerecho->Dato->GetNombre()+";\n";
        }
               
        temp += ArbolJugadores(raiz->HijoIzquierdo);
        temp += ArbolJugadores(raiz->HijoDerecho);
        return temp;
    }
    else
    {
        return "";
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
    Gotoxy(5,13);cout<<"3. A"<<(char)164<<"adir Usuario";
	Gotoxy(5,14);cout<<"4. Reportes";
    Gotoxy(5,15);cout<<"5. ScoreBoard";
	Gotoxy(5,16);cout<<"6. Salir"<<endl;
	Gotoxy(5,18);cout<<"P1> ";cin >> a;
    if (a == '1')
    {		
        ModoAbrirArchivoJson();		  
	}
	else if (a == '2')
	{
		/*system("cls");
		PintarMarco();
		//ModoAbrirArchivo();*/
	}
	else if (a == '3')
	{	
		system("cls");
        PintarMarco();
		ModoAgregarUsuario();
	}
	else if(a == '4')
	{
        system("cls");
        PintarMarco();
		MenuReportes();
	}
    else if(a == '5')
    {
        
    }
    else if(a == '6')
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

void ModoAbrirArchivoJson(){
    
    string path;
    Gotoxy(5,17);cout<<"[Directorio]: ";cin>>path;
    //cout<<path;
    ifstream ArchivoConfiguracion(path);
    json config;
    json JsonDiccionario;
    json Casillas;
    json Triples;
    json Dobles;
    ArchivoConfiguracion >> config;
    for (json::iterator i = config.begin(); i != config.end(); ++i)
    {
        if (i.key() == config.find("diccionario").key())
        {
            JsonDiccionario = i.value();
        }
        else if (i.key() == config.find("casillas").key())
        {
            Casillas = i.value();
            for (json::iterator j = Casillas.begin(); j != Casillas.end(); ++j)
            {
                if (j.key() == Casillas.find("dobles").key())
                {
                    Dobles = j.value();
                }
                else if (j.key() == Casillas.find("triples").key())
                {
                    Triples = j.value();
                }
            }
        }
    }
    for (size_t i = 0; i < JsonDiccionario.size(); i++)
    {
        json temp = JsonDiccionario[i].get<json>();
        Diccionario->AddLast(temp["palabra"]);
        
    }
    for (size_t i = 0; i < Triples.size(); i++)
    {
        json temp = Triples[i].get<json>();
        Ficha *aux = new Ficha('#',3);
        CasillasTriples->Add(aux,temp["x"],temp["y"]);   
    }
    for (size_t i = 0; i < Dobles.size(); i++)
    {
        json temp = Dobles[i].get<json>();
        Ficha *aux = new Ficha('#',2);
        CasillasDobles->Add(aux,temp["x"],temp["y"]);        
    }  

    Gotoxy(5,18);cout<<"Terminada la lectura de archivo...";
    Gotoxy(5,19);cout<<"Pulse ENTER para regresar al menu anterior";
    char tecla =' ';
    while (tecla != ENTER)
    {
        if (kbhit())
        {
            tecla = getch();
        }
                
    }
    system("cls");
    MenuPrincipal();
    
}


//METODO PRINCIPAL
int main()
{   
    EstablecerColaFichas();
    MenuPrincipal();
    cin.get();
    cin.ignore();
       
}
