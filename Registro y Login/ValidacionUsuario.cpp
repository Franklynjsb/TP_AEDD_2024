#include <iostream>
#include <windows.h>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;
#include "RegistroUsuario.h"
#include "ValidacionUsuario.h"
#include "ValidacionContrasena.h"
#include "main.h"

bool FuncionValidacionUsuario(string usuario){
	int num=usuario.size();
	int cantmay=0,cantnum=0;
	if(num<6 or num>10) return false;
	else{
		if(usuario[0]>='a' and usuario[0]<='z'){
			for(int i=1; i<num; i++){
				if(usuario[i]>='A' and usuario[i]<='Z') cantmay++;
				else if(usuario[i]>='0' and usuario[i]<='9')cantnum++;
				else if(usuario[i]<'a' or usuario[i]>'z'){
					
					if(usuario[i]!='+' && usuario[i]!='-' && usuario[i]!='*' && usuario[i]!='/') {
						return false;
					}
				}
			}
			if(cantmay<2 or cantnum>3){
				return false;
			}
			else{
				if (UsuarioUnico(usuario)) {
					return true;
				}else {
					return false;
				}
			}
		}else{
			return false;
		}
	}
}

bool UsuarioUnico (string nombreIngresado) {
	Usuario UsuarioALeer;
	ifstream UsuariosArchivo;
	UsuariosArchivo.open("Usuarios.dat");
	if (!UsuariosArchivo.is_open()){
		system("cls");
		cuadro();
		gotoxy(46,15);cout << "No se pudo abrir el archivo";
		return false;
	}else {
		while (UsuariosArchivo.read((char *) &UsuarioALeer, sizeof(Usuario))){
			
			if (UsuarioALeer.Nombre == nombreIngresado){
				system("cls");
				cuadro();
				gotoxy(49,15);cout << "Ese usuario ya existe" << endl;
				gotoxy(23,24);system("pause");
				return false;
			}
		}
		UsuariosArchivo.close();
		return true;
	}
	return false;
}
