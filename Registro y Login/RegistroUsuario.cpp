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
		gotoxy(41,15);cout<<"¡Atención! Ya tenes una sesión activa";
	}else{
		Usuario UsuarioARegistrar;
		string nombre, contrasena, verificacionContrasena;
		
		gotoxy(32,11);cout<<"¡Hola! Para poder ingresar a todos nuestros algoritmos";
		gotoxy(32,12);cout<<"y juegos, deberás tener un usuario registrado.";
		gotoxy(32,13);cout<<"Para registrarlo tenemos algunas condiciones.";
		gotoxy(32,14);cout<<"Nombre de usuario:";
		gotoxy(33,15);cout<<"- Debe tener como mínimo 6 caracteres y como máximo 10";
		gotoxy(33,16);cout<<"- Debe iniciar con una letra minúscula";
		gotoxy(33,17);cout<<"- Debe tener al menos dos (2) mayúsculas";
		gotoxy(33,18);cout<<"- Debe tener como máximo tres(3) dígitos";
		gotoxy(55,20);getline(cin,nombre);
		while(!FuncionValidacionUsuario(nombre)){
			system("cls");
			cuadro();
			gotoxy(35,15);cout<<"Nombre de usuario no válido, vuelva a intentarlo."<<endl;
			gotoxy(55,16);getline(cin,nombre);
		}
		system("cls");
		cuadro();
		gotoxy(52,15);cout<<"Usuario válido."<<endl;
		gotoxy(23,24);system("pause");
		system("cls");
		cuadro();
		gotoxy(25,13);cout<<"Nuestra contraseña también tiene condiciones";
		gotoxy(25,14);cout<<"Contraseña: ";
		gotoxy(26,15);cout<<"- Debe tener como mínimo 6 caracteres y como máximo 32";
		gotoxy(26,16);cout<<"- Debe tener como mínimo una letra minúscula, una mayúscula y un dígito";
		gotoxy(26,17);cout<<"- No puede tener caracteres de puntuación, acentos o espacios";
		gotoxy(50,18);getline(cin, contrasena);
		while(!FuncionValidacionContrasena(contrasena)){
			system("cls");
			cuadro();
			gotoxy(34,14);cout<<"Contraseña incorrecta. Por favor, vuelva a intentarlo"<<endl;
			gotoxy(50,15);getline(cin, contrasena);
		}
		system("cls");
		cuadro();
		gotoxy(36,14);cout<<"Contraseña válida, reingrésela para verificar:"<<endl;
		gotoxy(50,15);getline(cin, verificacionContrasena);
		if (verificacionContrasena != contrasena){
			system("cls");
			cuadro();
			gotoxy(42,15);cout << "La contraseña ingresada no coincide" << endl;
			
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
				gotoxy(44,14);cout << "¡Usuario registrado con éxito!" << endl;
				gotoxy(46,15);cout << "Ahora debe iniciar sesión" << endl;
				gotoxy(23,24);system("pause");
				InicioSesion(usuarioLog);
			}
			
			
		}
	}
	return;
}
