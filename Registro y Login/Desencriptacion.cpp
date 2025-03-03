#include <iostream>

#include <string>
using namespace std;

#include "Desencriptacion.h"
#include "Encriptacion.h"
	
void Desencriptar(string& palabra) {
	int largo = palabra.length();
	
	for(int i=(largo/2);i<largo;i++) { 
		palabra[i] = palabra[i]+1;
	}
	
	for(int i=0;i<largo;i++) { 
		if(esLetra(palabra[i]-3)){
			palabra[i] = palabra[i]-3;
		}
	}
	
	Invertir(palabra);

}
