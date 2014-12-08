#ifndef UNIDADES_JOGO
#define UNIDADES_JOGO

#include <iostream>
#include <string>
#include <vector>
#include "Util.h"
#include "iniciarJogo.h"

using namespace std;

class Unidade{
public:
	int getCoordX();
	int getCoordY();
	int getVida();
	string getTipo();
	void mudarCoordenadas(int cx, int cy);
	int id;

	Unidade(int x, int y, string tipo, int i);
private:
	int coordernada_x, coordernada_y;
	int vida;
	string tipo;

	void setTipo(string tipo_en);
	void setCoords(int x, int y);
	Unidade(){}
};

class Popul{
public:
	string getNome();
	int getID();

	Popul(string nomes);
private:
	string nome;

	void setNome(string nomes);
	void setID(int ID);
	Popul(){}
};

class Recursos{};

void Pops_func(Popul pop_a);

vector<Popul> getPops();

void imprimirUnidades(vector<Unidade> unit, int mapa_coordx, int mapa_coordy);

#endif