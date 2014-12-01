#ifndef INICIAR_JOGO
#define INICIAR_JOGO

#define TAM_X 7
#define TAM_Y 10

#include <iostream>
#include <string>
#include "Consola.h"
#include "verCom.h"
#include "Unidades.h"
#include "Util.h"

using namespace std;

class Mapa{
public:
	int getTamX();
	int getTamY();

	Mapa(int tamx, int tamy);

	void imprimirMapa();
	int getCoord_X();
	int getCoords_Y();
private:
	int tam_x;
	int tam_y;
	int coords_x; 
	int coords_y;
	int size_x;
	int size_y;

	void setSize(int tam1, int tam2);
	void setCoords(int x, int y);
	void defTam(int a, int b);
	Mapa() {}
};

class Sidebar{
public:
	int getDist();

	Sidebar(int colunas);

	void imprimirSidebar();
	void mudarDist(int change);
private:
	int dist;

	void setDist(int colunas);

	Sidebar() {}
};

void criarCampo(int linhas, int colunas);

void reimp(Mapa map, Sidebar barra);

void criarUnidades(int tipo, int quant);

#endif