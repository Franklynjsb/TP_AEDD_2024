#include <iostream>
#include <windows.h>
using namespace std;
#include "main.h"
#include "Threebonacci.h"

void FuncionThreebonacci() {
	
	int N;
	long long result;
	
	gotoxy(32,11);cout<<"Deberá ingresar un número entero, el cual será la posición";
	gotoxy(32,12);cout<<"en la secuencia de la que desea averiguar el valor: ";
	gotoxy(32,13);cout<<"(la carga finaliza con un 'Ctrl+z')";
	gotoxy(32,15);
	while (cin >> N){ //1<=N>=60
		result = Threebonacci(N);
		gotoxy(32,17);
		cout<<"El valor de la posición ingresada corresponde a " << result << endl;
		
		gotoxy(23,24);
		system("pause");
		system("cls");
		cuadro();
		
		gotoxy(32,12);cout<<"Deberá ingresar un número entero, el cual será la posición";
		gotoxy(32,13);cout<<"de la secuencia de la desea averiguar el valor: ";
		gotoxy(32,15);
	}
	gotoxy(35,17);cin.clear();
}

bool valido (long long N){
	int aux;
	if(N%3==0){
		return true;
	}else {
		while (N){
			aux=N%10;
			if(aux==3){
				return true;
			}
			N/=10;
		}
	}
	return false;
}
	
long long Threebonacci (int N) {
	int i=1, Contador=0;
	long long resultado;
	
	while(Contador<N) {
		resultado = fibbonacci(i);
		if (valido(resultado)){
			Contador++;
		}
		i++;
	}
	return resultado;
}
	
long long fibbonacci(long long X){
	if (X==0 || X==1) return X;
	
	long long num = 0, resultado = 1, aux;
	for (long long i = 2; i <= X; i++) {
		aux = num + resultado;
		num = resultado;
		resultado = aux;
	}
	return resultado;
}		
