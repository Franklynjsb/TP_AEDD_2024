#include <iostream>
#include <string>
using namespace std;
#include "ValidacionContrasena.h"


bool FuncionValidacionContrasena(string contrasenia){
	int cant=0,num;
	bool min=false, may=false, dig=false, caracter=false;
	num=contrasenia.size();		
	for(int i=0; i<num; i++){
		if(contrasenia[i]>='a' and contrasenia[i]<='z') min=true;
		else if(contrasenia[i]>='A' and contrasenia[i]<='Z') may=true;
		else if(contrasenia[i]>='0' and contrasenia[i]<='9') dig=true;
		else caracter=true;
		cant++;
	}
	if(!caracter and min and may and dig and (cant>=6 and cant<=32)) return true;
	else return false;
}
