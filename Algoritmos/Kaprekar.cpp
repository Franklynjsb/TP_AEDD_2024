#include <iostream>
#include <windows.h>
#include <cstdlib>
using namespace std;
#include "main.h"
#include "Kaprekar.h"


void FuncionKaprekar() {
	int casos, numero;
	gotoxy(36,13);cout<<"Deberá ingresar el número entero que indica la";
	gotoxy(36,14);cout<<"cantidad de casos que el programa debe realizar";
	gotoxy(50,16);cin >> casos;
	for(int i=1;i<=casos;i++) { 
		system("cls");
		cuadro();
		gotoxy(28,13);cout<<"Deberá ingresar el número entero de hasta cuatro dígitos del cual";
		gotoxy(28,14);cout<<"quiere averiguar las repeticiones necesarias para obtener 6174: ";
		gotoxy(50,15);cin >> numero;
		gotoxy(28,17);cout << "Caso #"<<i<<", el resultado es: " << krapekar(numero) << endl;
		if(i!=casos){
			gotoxy(23,24);system("pause");
		}
	}
	
}

int krapekar(int X) {
	int cnt = 0;
	while (X != 6174) {
		int hi = highest_number_with_digits_of(X);
		int lo = lowest_number_with_digits_of(X);
		X = hi - lo;
		cnt = cnt + 1;
		if (cnt > 9998){
			return -1;
		}
	}
	return cnt;
}
int lowest_number_with_digits_of(int X) {
	int numero[4]{}, resultado=0, mult=1000;
	for(int i=0;i<4;i++) { 
		numero[i]=X%10;
		X/=10;
	}
	for(int i=0;i<3;i++) { 
		for(int j=0;j<3;j++) { 
			if (numero[j]>numero[j+1]) {
				Intercambio(numero[j], numero[j+1]);
			}
		}
	}
	for(int i=0;i<4;i++) { 
		resultado+=numero[i]*mult;
		mult/=10;
	}
	return resultado;
}

int highest_number_with_digits_of (int X) {
	int numero[4]{}, resultado=0, mult=1000;
	for(int i=0;i<4;i++) { 
		numero[i]=X%10;
		X/=10;
	}
	for(int i=0;i<3;i++) { 
		for(int j=0;j<3;j++) { 
			if (numero[j]<numero[j+1]) {
				Intercambio(numero[j], numero[j+1]);
			}
		}
	}
	for(int i=0;i<4;i++) { 
		resultado+=numero[i]*mult;
		mult/=10;
	}
	return resultado;
}
	
void Intercambio (int &num1, int &num2) {
	int aux= num1;
	num1=num2;
	num2=aux;
}

