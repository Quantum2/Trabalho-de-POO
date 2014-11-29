#ifndef INICIAR_JOGO
#define INICIAR_JOGO

#define TAM_X 7
#define TAM_Y 10

#include <iostream>
#include <string>
#include "Consola.h"
#include "verCom.h"

using namespace std;

class Mapa{
public:
	int getTamX();
	int getTamY();

	Mapa(int tamx, int tamy);

	void imprimirMapa();
private:
	int tam_x;
	int tam_y;

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

#endif