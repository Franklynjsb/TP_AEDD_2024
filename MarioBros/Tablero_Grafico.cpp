#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <ctime>
#include <string>

using namespace std;
#include "main.h"
#include "Tablero_Grafico.h"


void Simulacion() {

	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),243);
	srand(time(NULL));
	personaje Mario;
	Mario.inicial = 'M';
	Mario.direccion = rand()%2; //0-> DERECHA 1->IZQUIERDA
	Mario.saludo = "Hola, soy Mario!";

	personaje Luigi;
	Luigi.inicial = 'L';
	Luigi.direccion = rand()%2; //0-> DERECHA 1->IZQUIERDA
	Luigi.saludo = "Hola, soy Luigi!";

	char tablero[10][20], tableroVISUAL[10][20];
	int filas = 10, fila, col, puntaje=0;
	cargarTablero(tablero, filas, MAXIMO); //CREA tablero con piedras y aves
	RellenarVacios (tablero);
	vaciarTablero (tableroVISUAL);
	gotoxy(45,9);
	cout<<"¡Bienvenid@ al Reino Champiñón!";
	gotoxy(26,13);
	cout<<"Antes de visualizar la simulación, ¿podrías ayudarnos a ";
	gotoxy(26,14);
	cout<<"encontrar todas las aves y piedras?";
	gotoxy(26,15);
	cout<<"Si no quieres o te rindes sólo deberás ingresas el número 99";
	gotoxy(26,16);
	cout<<"y la simulación va a comenzar.";
	gotoxy(26,17);
	cout<<"En caso de que quieras ayudarnos, debes ingresar la coordenada (x e y)";
	gotoxy(26,18);
	cout<<"donde crees que se encuntra. Para esto, indica primero el valor de y";
	gotoxy(26,19);
	cout<<"(entre 0 y 9, incluidos) y luego la x (entre 0 y 19, incluidos)";
	
	
	gotoxy(23,24);
	system("pause");
	mostrarMatriz(tableroVISUAL);
	gotoxy(23,24);
	system("pause");
	system("cls");
	cuadro();
	gotoxy(25,11);
	cout<<"Ingrese un número de fila (entre 0 y 9) o, para ver la simulación, 99:";
	gotoxy(59,12);
	while (cin >> fila, fila!=99 && puntaje!=15){
		gotoxy(25,14);
		cout<<"Ingrese un número de columna (entre 0 y 19):";
		gotoxy(59,15);
		cin >> col;
		if ((fila>=0 && fila<10) && (col>=0 && col<20)){
			tableroVISUAL[fila][col] = tablero[fila][col];
			if (tablero[fila][col] == '^' || tablero[fila][col] == 'X'){
				gotoxy(56,18);
				cout << "Acierto" << endl;
				puntaje++;
				gotoxy(23,24);
				Sleep(2000);
			} else {
				gotoxy(54,18);
				cout << "Aire o Tierra" << endl;
				gotoxy(23,24);
				Sleep(2000);
			}
			mostrarMatriz (tableroVISUAL);
			gotoxy(23,24);
			system("pause");
		}else{
			error();
		}
		system("cls");
		cuadro();
		gotoxy(25,11);
		cout<<"Ingrese un número de fila (entre 0 y 9) o, para ver la simulación, 99:";
		gotoxy(59,12);
	}
	gotoxy(50,14);
	cout << "Puntaje obtenido:" << puntaje << endl;
	gotoxy(23,24);
	system("pause");
	PersonajesTablero(tablero, Mario.inicial);
	PersonajesTablero(tablero, Luigi.inicial);
	mostrarMatriz (tablero);
	gotoxy(23,24);
	system("pause");
	SimulacionHermanos(tablero, Mario, Luigi);
}

void mostrarMatriz (char tablero[][MAXIMO]) {
	// Se inicializa el tablero con caracteres vacios en todas las posiciones
	cuadro();
	srand(time(0)); // Inicializa la semilla para la aleatoriedad
	int color1 = 240;
	int color2 = 63; 
	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),240);
	for(int i=10;i<20;i++){
		gotoxy(40,i);
		cout<<"|"<<endl;//Interio Izquierda
	}
	for(int i=10;i<20;i++){
		gotoxy(81,i);
		cout<<"|"<<endl;//Interior Derecha
	}
	gotoxy(40,9);
	for(int i=0;i<=41;i++){
		cout<<"-";//Interior Arriba
	}
	gotoxy(40,20);
	for(int i=0;i<=41;i++){
		cout<<"-";//Interio Abajo
	}
	for(int i=0;i<10;i++){
		for(int j=0;j<20;j++){
			if ((i + j) % 2 == 0) {
				setColor(color1);
			} else {
				setColor(color2);
			}
			if(i==9){
				setColor(2 * 16 + 15);//1er nro color fondo / 2do nro representa los colores basicos disponibles / 3er nro color letra
				if ((i + j) % 2 == 0) setColor(10 * 16 + 15);
			}
			gotoxy(41+(j*2),10+i);
			cout << tablero[i][j] << " ";
			
		}
	}
	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),243);
}

void cargarTablero(char tablero[][MAXIMO], int filas, int columnas){
	srand(time(NULL));
	int aves[CANT_AVES];
	for(int i=0; i < CANT_AVES; i++) aves[i]=1;
	int piedras[CANT_PIEDRAS] = {3,3,2,2,1};
	// Se inicializa el tablero con caracteres vacios en todas las posiciones
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			tablero[i][j] = ' ';
		}
	}
	cargarObstaculos(tablero, aves, 0, filas, columnas);
	cargarObstaculos(tablero, piedras, 1, filas, columnas);
}
	
void cargarObstaculos(char tablero[][MAXIMO], int tamanio_obstaculos[], bool tipo, int filas, int columnas){
	// CONVENCION VALORES variable tipo (booleana):
	// 0- Ave
	// 1- Piedra
	bool listo;
	int i,j,inicio,fin;
	char simbolo_obstaculo = (tipo) ? 'X' : '^';
	int cantidad_obstaculos = (tipo) ? CANT_PIEDRAS : CANT_AVES;
	for(int x=0;x<cantidad_obstaculos;x++){
		listo=false;
		do //do-while para intentar colocar obstaculo a partir de una posicion x e y aleatorias en el tablero
		{
			i = (tipo) ? 9:(rand()%3); // si el obstaculo es un ave, toma cualquier valor entre entre 0 y 2 en la matriz. en cualquier otro caso toma valor 9 (suelo).
			j = rand()%columnas; // posicion j aleatoria, el obstaculo puede estar en cualquier posicion de j
			if (not tipo){ // si es un ave...
				if (tablero[i][j]==' '){ // posicion disponible
					tablero[i][j] = simbolo_obstaculo;
					listo = true;
				}
			}
			else if(disponible(tablero, j, filas)){
				// Defino el final de las posiciones a chequear para saber si puedo
				// introducir el obstaculo en el rango necesario.
				inicio = 9-tamanio_obstaculos[x]+1;
				fin = 9;
				for(int y=inicio; y<=fin; y++){
					tablero[y][j]=simbolo_obstaculo;
				}
				listo = true;
			}
		}
		while(!listo); // Si no se pudo colocar el obstaculo en la posicion aleatoria generada, se vuelve a intentar con un nuevo par i e j.
	}
}
	
bool disponible(char tablero[][MAXIMO], int j, int filas){
	bool previa_disponible = (j>0) ? tablero[filas-1][j-1] == ' ' : false; // hay piedra en la posicion previa? si j==0, no puede haber una piedra alli (enunciado)
	bool siguiente_disponible = (j<19) ? tablero[filas-1][j+1] == ' ' : false; // hay piedra en la posicion siguiente? si j==19, no puede haber una piedra alli (enunciado)
	bool actual_disponible = tablero[filas-1][j] == ' ';
	return actual_disponible and previa_disponible and siguiente_disponible;
}

void RellenarVacios (char tablero[][MAXIMO]) {
	for(int i=0;i<20;i++) { 
		if (tablero[9][i]!='X') {
			tablero[9][i]='_';
		}
		for(int j=0;j<10;j++) { 
			if (tablero[j][i]== ' '){
				tablero[j][i]= '.';
			}
		}
	}
}
void vaciarTablero (char tablero[][MAXIMO]) {
	for(int i=0;i<10;i++) { 
		for(int j=0;j<20;j++) {
			tablero[i][j]= ' ';
		}
	}
}
	
void PersonajesTablero (char tablero[][MAXIMO], char caracter) {
	srand(time(NULL));
	int pos = rand()%20;
	bool bandera = true;
	while (bandera) {
		if (tablero[9][pos] == '_') {
			tablero[9][pos]= caracter;
			bandera = false;
		}else {
			pos = rand()%20;
		}
	}
}
			
void setColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color );
}

void SimulacionHermanos (char tablero[][MAXIMO], personaje Mario, personaje Luigi){
	int puntosMario=0, puntosLuigi=0;
	int posicionLuigi = BuscarPersonaje(tablero, 'L');
	int posicionMario = BuscarPersonaje(tablero, 'M');
	int saltoMario = 9, saltoLuigi=9;
	bool banderaM=true, banderaL=true;
	
	system("cls");
	cuadro();
	gotoxy(50,13);
	cout<<"Iniciando Animación";
	gotoxy(23,24);
	Sleep(2000);
	
	while (posicionLuigi != posicionMario){
		
		//Giro Mario
		if(posicionMario == 19 && banderaM) {
			Mario.direccion = 1;
			puntosMario++;
			banderaM=false;
		}else if (posicionMario == 0 &&banderaM){
			Mario.direccion = 0;
			puntosMario++;
			banderaM=false;
		}else if (Mario.direccion == 0){
			tablero[saltoMario][posicionMario] = '_';
			if (tablero[saltoMario][posicionMario+1] == 'X'){
				while (tablero[saltoMario][posicionMario+1] == 'X'){
					saltoMario--;
					if (tablero[saltoMario][posicionMario+1]=='.'){
						posicionMario++;
						tablero[saltoMario][posicionMario] = 'M';
						tablero[saltoMario][posicionMario-1] = '.';
						mostrarMatriz(tablero);
						gotoxy(23,24);
						Sleep(2000);
						puntosMario++;
					}else {
						tablero[saltoMario][posicionMario] = 'M';
						mostrarMatriz(tablero);
						gotoxy(23,24);
						Sleep(2000);
						puntosMario++;
						tablero[saltoMario][posicionMario] = '.';
					}
				}
				tablero[saltoMario][posicionMario] = '.';
				saltoMario=9;
				puntosMario++;
				posicionMario++;
				tablero[saltoMario][posicionMario] = 'M';
			}else {
				if (tablero[saltoMario][posicionMario]!='X'){
					tablero[saltoMario][posicionMario] = '_';
				}
				puntosMario++;
				posicionMario++;
				tablero[saltoMario][posicionMario] = 'M';
			}
		}else {
			
			tablero[saltoMario][posicionMario] = '_';
			
			if (tablero[saltoMario][posicionMario-1] == 'X'){
				while (tablero[saltoMario][posicionMario-1] == 'X'){
					saltoMario--;
					if (tablero[saltoMario][posicionMario-1]=='.'){
						posicionMario--;
						tablero[saltoMario][posicionMario] = 'M';
						tablero[saltoMario][posicionMario+1] = '.';
						mostrarMatriz(tablero);
						gotoxy(23,24);
						Sleep(2000);
						puntosMario++;
					}else {
						tablero[saltoMario][posicionMario] = 'M';
						mostrarMatriz(tablero);
						gotoxy(23,24);
						Sleep(2000);
						puntosMario++;
						tablero[saltoMario][posicionMario] = '.';
					}
				}
				tablero[saltoMario][posicionMario] = '.';
				saltoMario=9;
				puntosMario++;
				posicionMario--;
				tablero[saltoMario][posicionMario] = 'M';
			}else {
				if (tablero[saltoMario][posicionMario]!='X'){
					tablero[saltoMario][posicionMario] = '_';
				}
				puntosMario++;
				posicionMario--;
				tablero[saltoMario][posicionMario] = 'M';
			}
		}
		mostrarMatriz(tablero);
		gotoxy(23,24);
		Sleep(2000);
		if (posicionMario!=posicionLuigi){
		//Gira Luigi
		if(posicionLuigi == 19 && banderaL) {
			Luigi.direccion = 1;
			puntosLuigi++;
			banderaL=false;
		}else if (posicionLuigi == 0 && banderaL){
			Luigi.direccion = 0;
			puntosLuigi++;
			banderaL=false;
		}else if (Luigi.direccion == 0){
			tablero[saltoLuigi][posicionLuigi] = '_';
			if (tablero[saltoLuigi][posicionLuigi+1] == 'X'){
				while (tablero[saltoLuigi][posicionLuigi+1] == 'X'){
					saltoLuigi--;
					if (tablero[saltoLuigi][posicionLuigi+1]=='.'){
						posicionLuigi++;
						tablero[saltoLuigi][posicionLuigi] = 'L';
						tablero[saltoLuigi][posicionLuigi-1] = '.';
						mostrarMatriz(tablero);
						gotoxy(23,24);
						Sleep(2000);
						puntosLuigi++;
					}else {
						tablero[saltoLuigi][posicionLuigi] = 'L';
						mostrarMatriz(tablero);
						gotoxy(23,24);
						Sleep(2000);
						puntosLuigi++;
						tablero[saltoLuigi][posicionLuigi] = '.';
					}
				}
				tablero[saltoLuigi][posicionLuigi] = '.';
				saltoLuigi=9;
				posicionLuigi++;
				puntosLuigi++;
				tablero[saltoLuigi][posicionLuigi] = 'L';
			}else {
				if (tablero[saltoLuigi][posicionLuigi]!='X'){
					tablero[saltoLuigi][posicionLuigi] = '_';
				}
				puntosLuigi++;
				posicionLuigi++;
				tablero[saltoLuigi][posicionLuigi] = 'L';
			}
		}else {
			tablero[saltoLuigi][posicionLuigi] = '_';
			if (tablero[saltoLuigi][posicionLuigi-1] == 'X'){
				while (tablero[saltoLuigi][posicionLuigi-1] == 'X'){
					saltoLuigi--;
					if (tablero[saltoLuigi][posicionLuigi-1]=='.'){
						posicionLuigi--;
						tablero[saltoLuigi][posicionLuigi] = 'L';
						tablero[saltoLuigi][posicionLuigi+1] = '.';
						mostrarMatriz(tablero);
						gotoxy(23,24);
						Sleep(2000);
						puntosLuigi++;
					}else {
						tablero[saltoLuigi][posicionLuigi] = 'L';
						mostrarMatriz(tablero);
						gotoxy(23,24);
						Sleep(2000);
						puntosLuigi++;
						tablero[saltoLuigi][posicionLuigi] = '.';
					}
				}
				tablero[saltoLuigi][posicionLuigi] = '.';
				saltoLuigi=9;
				puntosLuigi++;
				posicionLuigi--;
				tablero[saltoLuigi][posicionLuigi] = 'L';
			}else {
				if (tablero[saltoLuigi][posicionLuigi]!='X'){
					tablero[saltoLuigi][posicionLuigi] = '_';
				}
				puntosLuigi++;
				posicionLuigi--;
				tablero[saltoLuigi][posicionLuigi] = 'L';
			}
			
		}
	}	
		if (posicionLuigi == posicionMario){
			tablero[saltoLuigi][posicionLuigi] = 'B';
		}
		mostrarMatriz(tablero);
		gotoxy(23,24);
		Sleep(2000);
	}
	
	gotoxy(45,6);
	cout<<"¡LOS HERMANOS SE ENCONTRARON!";
	gotoxy(40,8);
	cout<<Mario.saludo;
	gotoxy(66,8);
	cout<<Luigi.saludo;
	gotoxy(36,21);
	cout<<"Movimientos Mario: " <<puntosMario<<endl;
	gotoxy(66,21);
	cout<<"Movimientos Luigi: "<<puntosLuigi<<endl;
	if(puntosMario==puntosLuigi){
		gotoxy(58,22);
		cout<<"Empate"<<endl;
	}else if(puntosMario<puntosLuigi){
		gotoxy(56,22);
		cout<<"Gana Mario"<<endl;
	}else{
		gotoxy(56,22);
		cout<<"Gana Luigi"<<endl;
	}
	
}
int BuscarPersonaje (char tablero[][MAXIMO], char personaje){
	for(int j=0;j<20;j++) { 
		if (tablero[9][j] == personaje){
			return j;
		}
	}
	return 0;
}
