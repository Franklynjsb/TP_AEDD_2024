#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;

#include "RaizCuadradaDe2.h"

void FuncionRaizCuadradaDe2() {
	
	int N;//Numero a ingresar
	gotoxy(32,13);cout<<"Deberá ingresar un número entero, el cual será el de la ";
	gotoxy(32,14);cout<<"cantidad de repeticiones de fracciones: ";
	cin >> N;
	
	//Funcion representada en una variable
	double raizcalculada = 1.0 + funcionRaizDe2(N);
	
	cout << fixed << setprecision(10);
	
	gotoxy(32,16);cout<<"Aproximadamente (con la cantidad de repeticiones elegida),";
	gotoxy(32,17);cout<<"la raíz de 2 es de " << raizcalculada;
	
	return;
}

//Recursiva para la parte fraccionaria
double funcionRaizDe2 (int N){
	if (N==0){
		return 0.0;
	}else {
		return 1.0/(2.0 + funcionRaizDe2(N-1));
	}
}
