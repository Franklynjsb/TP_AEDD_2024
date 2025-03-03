#include <iostream>
#include <windows.h>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstddef>

using namespace std;

#include "Desencriptacion.h"
#include "InicioDeSesion.h"
#include "RegistroUsuario.h"
#include "main.h"

void FuncionInicioDeSesion(bool & usuarioLog) {
	
	if(usuarioLog){
		gotoxy(41,15);cout<<"¡Atención! Ya tenes una sesión activa";
	}else{
		Usuario UsuarioALeer;
		string contraseniaIngresada;
		string nombreIngresado;
		int contadorContrasenia=0;
		
		
		fstream UsuariosArchivo;
		UsuariosArchivo.open("Usuarios.dat", ios::binary | ios::in | ios::out );
		gotoxy(52,8);cout<<"Inicio de sesión"<<endl;
		gotoxy(45,12);cout<<"Ingrese su nombre de usuario:"<<endl;
		gotoxy(45,13);getline(cin,nombreIngresado);
		bool nombreNoValido=false;
		
		if (!UsuariosArchivo.is_open()){
			system("cls");
			cuadro();
			gotoxy(46,15);cout<< "No se pudo abrir el archivo" << endl;
		}else {
			
			while (!nombreNoValido and !UsuariosArchivo.eof()){
				UsuariosArchivo.read((char *) &UsuarioALeer, sizeof(Usuario));
				//
				string NombreUsuario = UsuarioALeer.Nombre;
				Desencriptar(NombreUsuario);
				//
				if (NombreUsuario == nombreIngresado){
					
					streampos pos = UsuariosArchivo.tellg(); // OBTENER la posicion actual
					pos -= sizeof(Usuario);             	 // Retroceder al inicio del usuario
					pos += offsetof(Usuario, UltimaSesion);  // Avanzar hasta el campo UltimaSesion
					
					nombreNoValido=true;
					while(contadorContrasenia<3 and !usuarioLog){
						if(contadorContrasenia==0){
							gotoxy(45,17);cout<<"Ingrese su contraseña:"<<endl;
							gotoxy(45,18);getline(cin,contraseniaIngresada);
						}else{
							system("cls");
							cuadro();
							gotoxy(52,8);cout<<"Inicio de sesión"<<endl;
							gotoxy(35,14);
							cout<<"Contraseña incorrecta. Por favor, vuelva a intentarlo"<<endl;
							gotoxy(35,15);
							cout<<"Tienes "<<3-contadorContrasenia<<" intentos restantes";
							gotoxy(50,16);getline(cin,contraseniaIngresada);
						}
						contadorContrasenia++;
						string UsuarioContrasena = UsuarioALeer.Contrasena;
						Desencriptar(UsuarioContrasena);
						
						if ( UsuarioContrasena == contraseniaIngresada){
							system("cls");
							cuadro();
							gotoxy(43,15);cout << "¡Has iniciado sesión correctamente!" << endl;
							gotoxy(59,16);
							Sleep(1500);
							system("cls");
							cuadro();
							gotoxy(49,11);cout<<"Bienvenido/a "<<nombreIngresado;
							gotoxy(29,12);cout<<"=============================================================";
							if(UsuarioALeer.UltimaSesion.Dia ==0 ){
								gotoxy(39,16);cout<<"Está es la primera vez que inicia sesión"<<endl;
							}else{
								gotoxy(44,16);cout<<"Último acceso a la aplicación:";
								gotoxy(54,17);cout<<UsuarioALeer.UltimaSesion.Dia<<"/"
												<<UsuarioALeer.UltimaSesion.Mes<<"/"
												<<UsuarioALeer.UltimaSesion.Anio<<endl;
							}
						//	REGISTRO DE SESION-FECHA
							   time_t tiempoActual = time(nullptr);
							tm* FechaActual = localtime(&tiempoActual);
							Fecha nuevaFecha;
							
							nuevaFecha.Dia = FechaActual->tm_mday;
							nuevaFecha.Mes = 1 + FechaActual->tm_mon;
							nuevaFecha.Anio = 1900 + FechaActual->tm_year;
							
							UsuariosArchivo.seekp(pos);//PARARME en esa posicion especificamente
							UsuariosArchivo.write((char *) &nuevaFecha, sizeof(Fecha));//REEMPLAZO
							
							usuarioLog=true;
						}
					}	
				}
			}
			if(!usuarioLog and nombreNoValido){
				system("cls");
				cuadro();
				gotoxy(49,15);cout<<"Error al iniciar sesión"<<endl;
				
			}
			if(!nombreNoValido){
				system("cls");
				cuadro();
				gotoxy(45,14);cout<<"Usuario incorrecto o inexistente";
				gotoxy(37,15);cout<<"Por favor, regístrese o vuelva a ingresar sesión";
			}
		}
		UsuariosArchivo.close();
	}
}
