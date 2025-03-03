#ifndef REGISTROUSUARIO_H
#define REGISTROUSUARIO_H

struct Fecha {
	int Dia,Mes,Anio;
};

struct Usuario {
	char Nombre[11]{};
	char Contrasena[33]{};
	Fecha UltimaSesion;
};

void FuncionRegistroUsuario (bool &);

#endif
