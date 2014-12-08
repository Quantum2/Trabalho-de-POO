#ifndef INICIAR_JOGO
#define INICIAR_JOGO

#define TAM_X 7
#define TAM_Y 10

#include <iostream>
#include <string>
#include <vector>
#include "Consola.h"
#include "verCom.h"
#include "Unidades.h"
#include "Util.h"

using namespace std;

class Unidade;

extern vector<Unidade> units;
extern int coords_mapa_x, coords_mapa_y;

class Mapa{
public:
	int getTamX();
	int getTamY();

	Mapa(int tamx, int tamy);

	void imprimirMapa();
	int getCoord_X();
	int getCoords_Y();
	void setCoords_XY(int x, int y);
private:
	int tam_x;
	int tam_y;
	int coords_actuais_x;
	int coords_actuais_y;
	int size_x;
	int size_y;

	void setSize(int tam1, int tam2);
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

extern Mapa mapa_global;

void criarCampo(int linhas, int colunas);

void reimp(Mapa map, Sidebar barra);

void criarUnidades(string tipo, string nome_pop, int x, int y);

void scroll();

void selecionarUnidades(int id);

void movimentarUnidades(int id, int x, int y, int tipo_movimento);

#endif