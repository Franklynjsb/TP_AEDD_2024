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
				cout<<"Si está seguro de que quiere salir, ingrese 1:";
				gotoxy(40,16);
				cout<<"Si todavía no desea salir, ingrese 2: ";
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
void error(){//Mensaje de error para los ingresos no válidos
	cuadro();
	gotoxy(43,13);
	cout<<"¡¡¡LA OPCION ELEGIDA NO ES VALIDA!!!"<<endl;
	gotoxy(46,14);
	cout<<"Por favor vuelva a intentar"<<endl;
	gotoxy(28,23);
	system("pause");
}
void menuPrincipal(){//Parte Grafica del menú principal
	cuadro();
	gotoxy(52,8);
	cout<<"Menú Principal"<<endl;
	gotoxy(29,9);
	cout<<"=============================================================";
	gotoxy(47,12);
	cout<<"1.- Registro"<<endl;
	gotoxy(47,14);
	cout<<"2.- Iniciar Sesión"<<endl;
	gotoxy(47,16);
	cout<<"3.- Algoritmos Numéricos"<<endl;
	gotoxy(47,18);
	cout<<"4.- Juego Super Mario Bros"<<endl;
	gotoxy(47,20);
	cout<<"9.- Salir de la aplicacion"<<endl;
	gotoxy(50,22);
	cout<<"Ingrese una opción: ";
}
void menuAlgoritmosNumericos(){//Parte Grafica del menú de algoritmos numericos
	cuadro();
	gotoxy(47,6);
	cout<<"Menú Algoritmos Numéricos"<<endl;
	gotoxy(29,7);
	cout<<"=============================================================";
	gotoxy(38,9);
	cout<<"1.- Binario a Decimal (Solución iterativa)"<<endl;
	gotoxy(38,11);
	cout<<"2.- Binario a Decimal (Solución recursiva)"<<endl;
	gotoxy(38,13);
	cout<<"3.- Threebonacci (Solución iterativa)"<<endl;
	gotoxy(38,15);
	cout<<"4.- Kaprekar"<<endl;
	gotoxy(38,17);
	cout<<"5.- Raiz Cuadrada De 2"<<endl;
	gotoxy(38,19);
	cout<<"6.- Raiz Cuadrada De 10"<<endl;
	gotoxy(38,21);
	cout<<"9.- Volver al menu principal"<<endl;
	gotoxy(50,23);
	cout<<"Ingrese una opción: ";
}	
void menuAlgoritmosNumericosFuncional(bool usuarioLog){//Parte Funcional del menú de algoritmos numericos
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
		gotoxy(35,14);cout<<"Para acceder a este menú debe haber iniciado sesión";
		gotoxy(29,15);cout<<"Si no tiene usuario, debe registrarse para ingresar a su sesión";
		gotoxy(23,24);
		system("pause");
	}
}	
void MenuSuperMarioBros(){//Parte Grafica del menú del Super Mario Bros
	cuadro();	
	gotoxy(45,8);
	cout<<"Menú de Juego Super Mario Bros"<<endl;
	gotoxy(29,9);
	cout<<"=============================================================";
	gotoxy(35,14);
	cout<<"A.- Simulación de encuentro entre Mario y Luigi"<<endl;
	gotoxy(35,16);
	cout<<"B.- Simulación de búsqueda de Princesa Peach"<<endl;
	gotoxy(35,20);
	cout<<"9.- Volver al menú anterior"<<endl;
	gotoxy(50,22);
	cout<<"Ingrese una opción: ";
}
void MenuSuperMarioBrosFuncional(bool usuarioLog){//Parte Funcional del menú del Super Mario Bros
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
		gotoxy(35,14);cout<<"Para acceder a este menú debe haber iniciado sesión";
		gotoxy(29,15);cout<<"Si no tiene usuario, debe registrarse para ingresar a su sesión";
		gotoxy(23,24);
		system("pause");
		}
	}
void SubMenuAlgoritmosNumericos(string nombre){////Parte Grafica del sub menú de algoritmos numericos
	system("cls");
	cuadro();
	gotoxy(29,8);
	cout<<"Algoritmo "<<nombre<<endl;
	gotoxy(29,9);
	cout<<"=============================================================";
	gotoxy(46,12);
	cout<<"1.- Ver definición"<<endl;
	gotoxy(46,14);
	cout<<"2.- Ejecutar"<<endl;
	gotoxy(46,20);
	cout<<"9.- Volver al menú anterior"<<endl;
	gotoxy(50,22);
	cout<<"Ingrese una opción: ";
}
void SubMenuAlgoritmosNumericosFuncional(char opcionAlgoritmo, string nombre){//Parte Funcional del sub menú de algoritmos numericos
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
		gotoxy(32,12);cout<<"Este algoritmo toma un número binario como entrada ";
		gotoxy(32,13);cout<<"(es decir, una secuencia de 0 y 1)";
		gotoxy(32,14);cout<<"y calcula su equivalente en el sistema decimal.";
		gotoxy(32,15);cout<<"El programa utiliza la base matemática del sistema binario";
		gotoxy(32,16);cout<<"(potencias de 2) para realizar la conversión";
		gotoxy(32,17);cout<<"y devolver el valor decimal correspondiente";
		break;
	case '2'://Binario a Decimal recursivo
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),241);
		gotoxy(40,7);cout<<"Algoritmo Binario a Decimal recursivo:";
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),243);
		gotoxy(32,12);cout<<"Este algoritmo toma un número binario como entrada ";
		gotoxy(32,13);cout<<"(es decir, una secuencia de 0 y 1)";
		gotoxy(32,14);cout<<"y calcula su equivalente en el sistema decimal.";
		gotoxy(32,15);cout<<"El programa utiliza la base matemática del sistema binario";
		gotoxy(32,16);cout<<"(potencias de 2) para realizar la conversión";
		gotoxy(32,17);cout<<"y devolver el valor decimal correspondiente";
		
		break;
	case '3'://Theebonaci
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),241);
		gotoxy(45,7);cout<<"Algoritmo Threebonacci Sequence:";
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),243);
		gotoxy(26,11);cout<<"En este algoritmo, usamos la secuencia de Fibonacci como base. ";
		gotoxy(26,12);cout<<"Esta secuencia está compuesta por números enteros que son resultado de";
		gotoxy(26,13);cout<<"la suma de los dos anteriores números pertenecientes a la secuencia. ";
		gotoxy(26,14);cout<<"En este caso, Threbonacci está compuesta por los números de";
		gotoxy(26,15);cout<<"la secuencia de Fibonacci tales que:";
		gotoxy(26,16);cout<<"1) Al menos uno de sus dígitos sea 3.";
		gotoxy(26,17);cout<<"2) O que sea múltiplo de 3.";
		gotoxy(26,18);cout<<"Con este algoritmo podemos obtener el valor correspondiente a la " ;
		gotoxy(26,19);cout<<"posición de la secuencia de Threbonacci que ingresemos.";
		break;
	case '4'://Kaprekar
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),241);
		gotoxy(50,7);cout<<"Algoritmo Kaprekar:";
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),243);
		gotoxy(26,9);cout<<"El matemático indio Dattatreya Ramachandra Kaprekar descubrió";
		gotoxy(26,10);cout<<"la constante de Kaprekar, el número 6174.";
		gotoxy(26,11);cout<<"Este número se obtiene al realizar repeticiones del siguiente proceso:";
		gotoxy(26,12);cout<<"1) Se toma un número de hasta 4 dígitos.";
		gotoxy(26,13);cout<<"Si el número tiene menos dígitos se completa con ceros a la derecha.";
		gotoxy(26,14);cout<<"2) Se realiza una reorganización del número de manera";
		gotoxy(26,15);cout<<"   ascendente y descendente.";
		gotoxy(26,16);cout<<"3) Se le resta el menor número obtenido en la reorganización";
		gotoxy(26,17);cout<<"   al mayor conseguido en la misma.";
		gotoxy(26,18);cout<<"Al ingresar un número, este algoritmo informa la cantidad de veces que" ;
		gotoxy(26,19);cout<<"se realizó la secuencia de pasos anterior, aunque si el número que";
		gotoxy(26,20);cout<<"se muestra en pantalla es -1, indica que la secuencia es infinita,";
		gotoxy(26,21);cout<<"por lo que, la teoría no se cumple.";
		break;
	case '5'://Raiz cuadrada de 2
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),241);
		gotoxy(47,9);cout<<"Algoritmo Raíz cuadrada de 2:";
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),243);
		gotoxy(26,13);cout<<"Con este algoritmo somos capaces de calcular aproximadamente";
		gotoxy(26,14);cout<<"la raíz cuadrada de dos, a través de fracciones continuas periódicas.";
		gotoxy(26,15);cout<<"Este método consta de utilizar como denominador";
		gotoxy(26,16);cout<<"una repetición de fracciones.";
		gotoxy(26,17);cout<<"En este problema, la cantidad de repeticiones de";
		gotoxy(26,18);cout<<"fracciones es fija e ingresada por el usuario.";
		break;
	case '6'://Raiz cuadrada de 10
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),241);
		gotoxy(47,9);cout<<"Algoritmo Raíz cuadrada de 10:";
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),243);
		gotoxy(26,13);cout<<"Con este algoritmo somos capaces de calcular aproximadamente";
		gotoxy(26,14);cout<<"la raíz cuadrada de diez, a través de fracciones continuas periódicas.";
		gotoxy(26,15);cout<<"Este método consta de utilizar como denominador una";
		gotoxy(26,16);cout<<"repetición de fracciones.";
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
