#include <iostream>
#include <windows.h>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

#include "Encriptacion.h"
#include "Desencriptacion.h"
#include "RegistroUsuario.h"
#include "ValidacionUsuario.h"
#include "ValidacionContrasena.h"
#include "main.h"

void FuncionRegistroUsuario (bool & usuarioLog) {
	if(usuarioLog){
		gotoxy(41,15);cout<<"�Atenci�n! Ya tenes una sesi�n activa";
	}else{
		Usuario UsuarioARegistrar;
		string nombre, contrasena, verificacionContrasena;
		
		gotoxy(32,11);cout<<"�Hola! Para poder ingresar a todos nuestros algoritmos";
		gotoxy(32,12);cout<<"y juegos, deber�s tener un usuario registrado.";
		gotoxy(32,13);cout<<"Para registrarlo tenemos algunas condiciones.";
		gotoxy(32,14);cout<<"Nombre de usuario:";
		gotoxy(33,15);cout<<"- Debe tener como m�nimo 6 caracteres y como m�ximo 10";
		gotoxy(33,16);cout<<"- Debe iniciar con una letra min�scula";
		gotoxy(33,17);cout<<"- Debe tener al menos dos (2) may�sculas";
		gotoxy(33,18);cout<<"- Debe tener como m�ximo tres(3) d�gitos";
		gotoxy(55,20);getline(cin,nombre);
		while(!FuncionValidacionUsuario(nombre)){
			system("cls");
			cuadro();
			gotoxy(35,15);cout<<"Nombre de usuario no v�lido, vuelva a intentarlo."<<endl;
			gotoxy(55,16);getline(cin,nombre);
		}
		system("cls");
		cuadro();
		gotoxy(52,15);cout<<"Usuario v�lido."<<endl;
		gotoxy(23,24);system("pause");
		system("cls");
		cuadro();
		gotoxy(25,13);cout<<"Nuestra contrase�a tambi�n tiene condiciones";
		gotoxy(25,14);cout<<"Contrase�a: ";
		gotoxy(26,15);cout<<"- Debe tener como m�nimo 6 caracteres y como m�ximo 32";
		gotoxy(26,16);cout<<"- Debe tener como m�nimo una letra min�scula, una may�scula y un d�gito";
		gotoxy(26,17);cout<<"- No puede tener caracteres de puntuaci�n, acentos o espacios";
		gotoxy(50,18);getline(cin, contrasena);
		while(!FuncionValidacionContrasena(contrasena)){
			system("cls");
			cuadro();
			gotoxy(34,14);cout<<"Contrase�a incorrecta. Por favor, vuelva a intentarlo"<<endl;
			gotoxy(50,15);getline(cin, contrasena);
		}
		system("cls");
		cuadro();
		gotoxy(36,14);cout<<"Contrase�a v�lida, reingr�sela para verificar:"<<endl;
		gotoxy(50,15);getline(cin, verificacionContrasena);
		if (verificacionContrasena != contrasena){
			system("cls");
			cuadro();
			gotoxy(42,15);cout << "La contrase�a ingresada no coincide" << endl;
			
			return;
		}
		
		
		fstream UsuariosArchivo;
		UsuariosArchivo.open("Usuarios.dat", ios::binary | ios::out | ios::app);
		
		if (!UsuariosArchivo.is_open()){
			system("cls");
			cuadro();
			gotoxy(46,15);cout<< "No se pudo abrir el archivo" << endl;
		}else {
			
			//Encriptar Usuario
			Encriptar(nombre);
			Encriptar(contrasena);
			//
			
			strcpy(UsuarioARegistrar.Nombre, nombre.c_str());
			strcpy(UsuarioARegistrar.Contrasena, contrasena.c_str());
			
			
			UsuarioARegistrar.UltimaSesion.Dia = 0;
			UsuarioARegistrar.UltimaSesion.Mes = 0;
			UsuarioARegistrar.UltimaSesion.Anio = 0;
			
			
			
			UsuariosArchivo.write((char *) &UsuarioARegistrar, sizeof(Usuario));
			UsuariosArchivo.close();
			
			if(UsuariosArchivo.fail()) {
				system("cls");
				cuadro();
				gotoxy(45,15);cout <<"Error en el registro del usuario" << endl;
				gotoxy(24,24);system("pause");
			}else {
				system("cls");
				cuadro();
				gotoxy(44,14);cout << "�Usuario registrado con �xito!" << endl;
				gotoxy(46,15);cout << "Ahora debe iniciar sesi�n" << endl;
				gotoxy(23,24);system("pause");
				InicioSesion(usuarioLog);
			}
			
			
		}
	}
	return;
}
