#include <iostream>
#include <windows.h>
#include <iomanip>
#include <string>

using namespace std;

#include "main.h"
#include "RegistroUsuario.h"
#include "InicioDeSesion.h"
#include "RaizCuadradaDe2.h"
#include "RaizCuadradaDe10.h"
#include "Kaprekar.h"
#include "BinToDec_Iterativo.h"
#include "BinToDec_Recursivo.h"
#include "Threebonacci.h"
#include "Tablero_Grafico.h"


int main(int argc, char *argv[]) {
	setlocale(LC_ALL,"spanish");
	
	system ("COLOR f0");//cambiamos de color el fondo.
	
	bool salir=false , salir2=false;
	char opcion[100];
	bool usuarioLog = false;
	
	while(!salir){ //este while es el que funciona como menu principal
		salir2=false;
		
		menuPrincipal(); //solo la parte grafica del menu
		gets(opcion);
		if(strlen(opcion)==1){//se valida que solo halla ingresado un unico caracter; de lo contrario mensaje de error
			
			// 1 y 2 llaman a la funcion con el menu correspondiente
			// de ingresar X o x se le pide confirmacion, y se efectua la misma, se muestra mensaje de despedida
			switch(opcion[0]){
			case '1': Registro(usuarioLog);break ;
			case '2': InicioSesion(usuarioLog);break;
			case '3': menuAlgoritmosNumericosFuncional(usuarioLog);break;
			case '4': MenuSuperMarioBrosFuncional(usuarioLog);break;
			case '9':while(!salir and !salir2){	
				cuadro();
				gotoxy(36,14);
				cout<<"Si est� seguro de que quiere salir, ingrese 1:";
				gotoxy(40,16);
				cout<<"Si todav�a no desea salir, ingrese 2: ";
				gets(opcion);
				if(strlen(opcion)==1){
					switch(opcion[0]){
					case '1':salir=true;break ;
					case '2':salir2=true;break;
					default: error();
					}
				}
				else{
					error();
				}
			}break;
			default: error();break;
			}
		}
		else{
			error();
		}
	}
	
	gotoxy(1,28);
	return 0;
}


void gotoxy(SHORT x, SHORT y){//Funcion para posicionar elementos en pantalla
	COORD cp = {x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cp);
}
void cuadro(){	//Imprime el cuadro que se usa en casi todas las interfaces graficas de de nuestro programa
	system("cls");
	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),243);
	for(int i=5;i<25;i++){
		gotoxy(20,i);
		cout<<"|"<<endl;//Interio Izquierda
	}
	for(int i=6;i<25;i++){
		gotoxy(100,i);
		cout<<"|"<<endl;//Interior Derecha
	}
	gotoxy(20,5);
	for(int i=0;i<=80;i++){
		cout<<"~";//Interior Arriba
	}
	gotoxy(20,25);
	for(int i=0;i<=80;i++){
		cout<<"~";//Interio Abajo
	}
	for(int i=5;i<=28;i++){
		gotoxy(104,i-1);
		cout<<"*"<<endl;//Exterior Derecha
	}
	for(int i=5;i<=28;i++){
		gotoxy(16,i-1);
		cout<<"*"<<endl;//Exterior Izquierda
	}
	gotoxy(16,3);
	for(int i=0;i<=88;i++){
		cout<<"*";//Exterior Arriba
	}
	gotoxy(16,27);
	for(int i=0;i<=88;i++){
		cout<<"*";//Exterio Abajo
	}
	gotoxy(87,4);
	gotoxy(92,26);
	cout<<"UTN_FRSF"<<endl;
	gotoxy(20,4);
	cout<<"Grupo 1 AEDD"<<endl;
}
void error(){//Mensaje de error para los ingresos no v�lidos
	cuadro();
	gotoxy(43,13);
	cout<<"���LA OPCION ELEGIDA NO ES VALIDA!!!"<<endl;
	gotoxy(46,14);
	cout<<"Por favor vuelva a intentar"<<endl;
	gotoxy(28,23);
	system("pause");
}
void menuPrincipal(){//Parte Grafica del men� principal
	cuadro();
	gotoxy(52,8);
	cout<<"Men� Principal"<<endl;
	gotoxy(29,9);
	cout<<"=============================================================";
	gotoxy(47,12);
	cout<<"1.- Registro"<<endl;
	gotoxy(47,14);
	cout<<"2.- Iniciar Sesi�n"<<endl;
	gotoxy(47,16);
	cout<<"3.- Algoritmos Num�ricos"<<endl;
	gotoxy(47,18);
	cout<<"4.- Juego Super Mario Bros"<<endl;
	gotoxy(47,20);
	cout<<"9.- Salir de la aplicacion"<<endl;
	gotoxy(50,22);
	cout<<"Ingrese una opci�n: ";
}
void menuAlgoritmosNumericos(){//Parte Grafica del men� de algoritmos numericos
	cuadro();
	gotoxy(47,6);
	cout<<"Men� Algoritmos Num�ricos"<<endl;
	gotoxy(29,7);
	cout<<"=============================================================";
	gotoxy(38,9);
	cout<<"1.- Binario a Decimal (Soluci�n iterativa)"<<endl;
	gotoxy(38,11);
	cout<<"2.- Binario a Decimal (Soluci�n recursiva)"<<endl;
	gotoxy(38,13);
	cout<<"3.- Threebonacci (Soluci�n iterativa)"<<endl;
	gotoxy(38,15);
	cout<<"4.- Kaprekar"<<endl;
	gotoxy(38,17);
	cout<<"5.- Raiz Cuadrada De 2"<<endl;
	gotoxy(38,19);
	cout<<"6.- Raiz Cuadrada De 10"<<endl;
	gotoxy(38,21);
	cout<<"9.- Volver al menu principal"<<endl;
	gotoxy(50,23);
	cout<<"Ingrese una opci�n: ";
}	
void menuAlgoritmosNumericosFuncional(bool usuarioLog){//Parte Funcional del men� de algoritmos numericos
	string nombre;
	bool salir=false;
	char opcion[100] ;	
	if(usuarioLog){
		while(!salir){
			menuAlgoritmosNumericos();
			gets(opcion);
			if(strlen(opcion)==1){
				switch(opcion[0]){
				case '1': cuadro(); gotoxy(42,12);nombre="Binario a Decimal (iterativo)";SubMenuAlgoritmosNumericosFuncional(opcion[0],nombre);cout<<endl;gotoxy(23,24);break;
				case '2': cuadro(); gotoxy(42,12);nombre="Binario a Decimal (recursivo)";SubMenuAlgoritmosNumericosFuncional(opcion[0],nombre);cout<<endl;gotoxy(23,24);break;
				case '3': cuadro(); gotoxy(42,12);nombre="Threebonacci Sequence";SubMenuAlgoritmosNumericosFuncional(opcion[0],nombre);cout<<endl;gotoxy(23,24);break;
				case '4': cuadro(); gotoxy(42,12);nombre="Kaprekar";SubMenuAlgoritmosNumericosFuncional(opcion[0],nombre);cout<<endl;gotoxy(23,24);break;
				case '5': cuadro(); gotoxy(42,12);nombre="Raiz Cuadrada de 2";SubMenuAlgoritmosNumericosFuncional(opcion[0],nombre);cout<<endl;gotoxy(23,24);break;
				case '6': cuadro(); gotoxy(42,12);nombre="Raiz Cuadrada de 10";SubMenuAlgoritmosNumericosFuncional(opcion[0],nombre);cout<<endl;gotoxy(23,24);break;
				case '9': salir=true;break;
				default: error(); break;
				}
			}else{
				error();
			}
		}
	}else{
		system("cls");
		cuadro();
		gotoxy(35,14);cout<<"Para acceder a este men� debe haber iniciado sesi�n";
		gotoxy(29,15);cout<<"Si no tiene usuario, debe registrarse para ingresar a su sesi�n";
		gotoxy(23,24);
		system("pause");
	}
}	
void MenuSuperMarioBros(){//Parte Grafica del men� del Super Mario Bros
	cuadro();	
	gotoxy(45,8);
	cout<<"Men� de Juego Super Mario Bros"<<endl;
	gotoxy(29,9);
	cout<<"=============================================================";
	gotoxy(35,14);
	cout<<"A.- Simulaci�n de encuentro entre Mario y Luigi"<<endl;
	gotoxy(35,16);
	cout<<"B.- Simulaci�n de b�squeda de Princesa Peach"<<endl;
	gotoxy(35,20);
	cout<<"9.- Volver al men� anterior"<<endl;
	gotoxy(50,22);
	cout<<"Ingrese una opci�n: ";
}
void MenuSuperMarioBrosFuncional(bool usuarioLog){//Parte Funcional del men� del Super Mario Bros
	bool salir=false;
	char opcion[100] ;	
	if(usuarioLog){
		while(!salir){
			MenuSuperMarioBros();
			gets(opcion);
			if(strlen(opcion)==1){
				switch(opcion[0]){
				case 'A': 
				case 'a': cuadro(); gotoxy(42,12);SimEncuentroMarioLuigi();cout<<endl;gotoxy(23,24);system("pause");break;
				case 'B': 
				case 'b': cuadro(); gotoxy(42,12);SimBusquedaPeach();cout<<endl;gotoxy(23,24);system("pause");break;
				case '9': salir=true;break;
				default: error(); break;
				}
			}else{
				error();
			}
		}
	}else{
		system("cls");
		cuadro();
		gotoxy(35,14);cout<<"Para acceder a este men� debe haber iniciado sesi�n";
		gotoxy(29,15);cout<<"Si no tiene usuario, debe registrarse para ingresar a su sesi�n";
		gotoxy(23,24);
		system("pause");
		}
	}
void SubMenuAlgoritmosNumericos(string nombre){////Parte Grafica del sub men� de algoritmos numericos
	system("cls");
	cuadro();
	gotoxy(29,8);
	cout<<"Algoritmo "<<nombre<<endl;
	gotoxy(29,9);
	cout<<"=============================================================";
	gotoxy(46,12);
	cout<<"1.- Ver definici�n"<<endl;
	gotoxy(46,14);
	cout<<"2.- Ejecutar"<<endl;
	gotoxy(46,20);
	cout<<"9.- Volver al men� anterior"<<endl;
	gotoxy(50,22);
	cout<<"Ingrese una opci�n: ";
}
void SubMenuAlgoritmosNumericosFuncional(char opcionAlgoritmo, string nombre){//Parte Funcional del sub men� de algoritmos numericos
	bool salir=false;
	char opcion[100] ;	
	while(!salir){
		SubMenuAlgoritmosNumericos(nombre);
		gets(opcion);
		if(strlen(opcion)==1){
			switch(opcion[0]){
			case '1': gotoxy(42,12);Definiciones(opcionAlgoritmo);cout<<endl;gotoxy(23,24);system("pause");break;
			case '2': gotoxy(42,12);Ejecuciones(opcionAlgoritmo);cout<<endl;gotoxy(23,24);system("pause");break;
			case '9': salir=true;break;
			default: error(); break;
			}
		}else{
			error();
		}
	}
}
void Registro(bool & usuarioLog){
	system("cls");
	cuadro();
	FuncionRegistroUsuario(usuarioLog);
	gotoxy(23,24);
	system("pause");
}
void InicioSesion(bool & usuarioLog){
	system("cls");
	cuadro();
	FuncionInicioDeSesion(usuarioLog);
	gotoxy(23,24);
	system("pause");
}
void Definiciones(char op){
	system("cls");
	cuadro();
	switch(op){
	case '1'://Binario a Decimal iterativa
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),241);
		gotoxy(40,7);cout<<"Algoritmo Binario a Decimal iterativo:";
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),243);
		gotoxy(32,12);cout<<"Este algoritmo toma un n�mero binario como entrada ";
		gotoxy(32,13);cout<<"(es decir, una secuencia de 0 y 1)";
		gotoxy(32,14);cout<<"y calcula su equivalente en el sistema decimal.";
		gotoxy(32,15);cout<<"El programa utiliza la base matem�tica del sistema binario";
		gotoxy(32,16);cout<<"(potencias de 2) para realizar la conversi�n";
		gotoxy(32,17);cout<<"y devolver el valor decimal correspondiente";
		break;
	case '2'://Binario a Decimal recursivo
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),241);
		gotoxy(40,7);cout<<"Algoritmo Binario a Decimal recursivo:";
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),243);
		gotoxy(32,12);cout<<"Este algoritmo toma un n�mero binario como entrada ";
		gotoxy(32,13);cout<<"(es decir, una secuencia de 0 y 1)";
		gotoxy(32,14);cout<<"y calcula su equivalente en el sistema decimal.";
		gotoxy(32,15);cout<<"El programa utiliza la base matem�tica del sistema binario";
		gotoxy(32,16);cout<<"(potencias de 2) para realizar la conversi�n";
		gotoxy(32,17);cout<<"y devolver el valor decimal correspondiente";
		
		break;
	case '3'://Theebonaci
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),241);
		gotoxy(45,7);cout<<"Algoritmo Threebonacci Sequence:";
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),243);
		gotoxy(26,11);cout<<"En este algoritmo, usamos la secuencia de Fibonacci como base. ";
		gotoxy(26,12);cout<<"Esta secuencia est� compuesta por n�meros enteros que son resultado de";
		gotoxy(26,13);cout<<"la suma de los dos anteriores n�meros pertenecientes a la secuencia. ";
		gotoxy(26,14);cout<<"En este caso, Threbonacci est� compuesta por los n�meros de";
		gotoxy(26,15);cout<<"la secuencia de Fibonacci tales que:";
		gotoxy(26,16);cout<<"1) Al menos uno de sus d�gitos sea 3.";
		gotoxy(26,17);cout<<"2) O que sea m�ltiplo de 3.";
		gotoxy(26,18);cout<<"Con este algoritmo podemos obtener el valor correspondiente a la " ;
		gotoxy(26,19);cout<<"posici�n de la secuencia de Threbonacci que ingresemos.";
		break;
	case '4'://Kaprekar
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),241);
		gotoxy(50,7);cout<<"Algoritmo Kaprekar:";
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),243);
		gotoxy(26,9);cout<<"El matem�tico indio Dattatreya Ramachandra Kaprekar descubri�";
		gotoxy(26,10);cout<<"la constante de Kaprekar, el n�mero 6174.";
		gotoxy(26,11);cout<<"Este n�mero se obtiene al realizar repeticiones del siguiente proceso:";
		gotoxy(26,12);cout<<"1) Se toma un n�mero de hasta 4 d�gitos.";
		gotoxy(26,13);cout<<"Si el n�mero tiene menos d�gitos se completa con ceros a la derecha.";
		gotoxy(26,14);cout<<"2) Se realiza una reorganizaci�n del n�mero de manera";
		gotoxy(26,15);cout<<"   ascendente y descendente.";
		gotoxy(26,16);cout<<"3) Se le resta el menor n�mero obtenido en la reorganizaci�n";
		gotoxy(26,17);cout<<"   al mayor conseguido en la misma.";
		gotoxy(26,18);cout<<"Al ingresar un n�mero, este algoritmo informa la cantidad de veces que" ;
		gotoxy(26,19);cout<<"se realiz� la secuencia de pasos anterior, aunque si el n�mero que";
		gotoxy(26,20);cout<<"se muestra en pantalla es -1, indica que la secuencia es infinita,";
		gotoxy(26,21);cout<<"por lo que, la teor�a no se cumple.";
		break;
	case '5'://Raiz cuadrada de 2
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),241);
		gotoxy(47,9);cout<<"Algoritmo Ra�z cuadrada de 2:";
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),243);
		gotoxy(26,13);cout<<"Con este algoritmo somos capaces de calcular aproximadamente";
		gotoxy(26,14);cout<<"la ra�z cuadrada de dos, a trav�s de fracciones continuas peri�dicas.";
		gotoxy(26,15);cout<<"Este m�todo consta de utilizar como denominador";
		gotoxy(26,16);cout<<"una repetici�n de fracciones.";
		gotoxy(26,17);cout<<"En este problema, la cantidad de repeticiones de";
		gotoxy(26,18);cout<<"fracciones es fija e ingresada por el usuario.";
		break;
	case '6'://Raiz cuadrada de 10
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),241);
		gotoxy(47,9);cout<<"Algoritmo Ra�z cuadrada de 10:";
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),243);
		gotoxy(26,13);cout<<"Con este algoritmo somos capaces de calcular aproximadamente";
		gotoxy(26,14);cout<<"la ra�z cuadrada de diez, a trav�s de fracciones continuas peri�dicas.";
		gotoxy(26,15);cout<<"Este m�todo consta de utilizar como denominador una";
		gotoxy(26,16);cout<<"repetici�n de fracciones.";
		gotoxy(26,17);cout<<"En este problema, la cantidad de repeticiones de";
		gotoxy(26,18);cout<<"fracciones es fija e ingresada por el usuario.";
		break;
	}
}
void Ejecuciones(char op){
	system("cls");
	cuadro();
	switch(op){
	case '1'://Binario a Decimal iterativa
	FuncionBinToDec_Iterativa();
		cin.ignore();
		break;
	case '2'://Binario a Decimal recursivo
		FuncionBinToDec_Recursiva();
		cin.ignore();
		break;
	case '3'://Theebinaci
		FuncionThreebonacci();
		break;
	case '4'://Kaprekar
		FuncionKaprekar();
		cin.ignore();
		break;
	case '5'://Raiz cuadrada de 2
		FuncionRaizCuadradaDe2();
		cin.ignore();
		break;
	case '6'://Raiz cuadrada de 10
		FuncionRaizCuadradaDe10();
		cin.ignore();
		break;
	}
}
void SimEncuentroMarioLuigi(){
	system("cls");
	cuadro();
	Simulacion();
	cin.ignore();
	
}
void SimBusquedaPeach(){	
	system("cls");
	cuadro();
	gotoxy(52,13);
	cout<<"Juego en proceso";
	gotoxy(42,17);
	for(int i=0;i<20;i++){
		cout<<"# ";
		Sleep(50);
	}
	gotoxy(23,24);
}
