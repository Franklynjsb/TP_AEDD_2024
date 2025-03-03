#ifndef TABLERO_GRAFICO_H
#define TABLERO_GRAFICO_H
#define CANT_AVES 10
#define CANT_PIEDRAS 5
#define MAXIMO 20
struct personaje {
	char inicial;
	int direccion;
	string saludo;
};

void cargarTablero(char [][MAXIMO], int, int); // carga el tablero recibido por parámetro con piedras y aves
void mostrarMatriz (char tablero[][MAXIMO]);
void cargarObstaculos(char tablero[][MAXIMO], int tamanio_obstaculos[], bool tipo, int filas, int columnas);
bool disponible(char tablero[][MAXIMO], int x, int filas);
void RellenarVacios (char tablero[][MAXIMO]);
void vaciarTablero (char tablero[][MAXIMO]);
void PersonajesTablero (char tablero[][MAXIMO], char caracter);
void setColor(int color);
int BuscarPersonaje (char tablero[][MAXIMO], char personaje);
void SimulacionHermanos (char tablero[][MAXIMO], personaje Mario, personaje Luigi);
void Simulacion();

#endif
