#include <iostream>
#include <cmath>
#include <windows.h>
using namespace std;
#include "main.h"
#include "BinToDec_Iterativo.h"

void FuncionBinToDec_Iterativa() {
	
	string binario;
	long long resultado;
	
	gotoxy(31,12);cout<<"Deber� ingresar un n�mero binario (combinaci�n de 0 y 1):";
	gotoxy(31,13);cin >> binario;

	resultado = BinToDec(binario);
	gotoxy(31,17);cout<<"El n�mero: " << binario;
	gotoxy(31,18);cout<<"Se representa en sistema decimal como: " << resultado << endl;
	

}

long long BinToDec (string binario) {
	
	long long resultado=0;
	
	int largo = binario.length(); // Longitud del n�mero binario
	
	for(int i=0;i<largo;i++) { 
		if(binario[largo-1-i] == '1'){
			resultado+=pow(2,i);
		}
	}
	
	return resultado;
}
