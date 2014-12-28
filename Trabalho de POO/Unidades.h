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
	int id_pop;

	Unidade(int x, int y, string tipo, int i, int pid);
private:
	int coordernada_x, coordernada_y;
	int vida;
	string tipo;

	void setTipo(string tipo_en);
	void setCoords(int x, int y);
	Unidade(){}
};

class Edificio{
public:
	int getCoordX();
	int getCoordY();
	int getVida();
	string getTipo();
	void mudarCoordenadas(int cx, int cy);
	int id;
	int id_pop;

	Edificio(int x, int y, string tip, int i, int pid);
	Edificio(int x, int y, string tip, int i);
private:
	int coordernada_x, coordernada_y;
	int vida;
	int conserva;
	string tipo;
	Edificio(){}
};

class Castelo : public Edificio
{
public:
	Castelo(int xx, int yy, int ii)
		: Edificio(xx, yy, "castelo", ii){};
};

class Soldado : public Unidade{
public:

};

class Popul{
public:
	string getNome();
	int getID();
	void setID(int ID);

	Popul(string nomes);
private:
	string nome;
	int ID;

	void setNome(string nomes);
	Popul(){}
};

class Recursos{
public:
	int res_restante;
	int getPosX();
	int getPosY();
	int getID();
	string getTipo();
	Recursos(string tipo_recurso, int x, int y, int id_inicial);
private:
	int ID;
	string tipo;
	int pos_x, pos_y;
};

void Pops_func(Popul pop_a);

vector<Popul> getPops();

void imprimirUnidades(vector<Unidade> unit, int mapa_coordx, int mapa_coordy);

void imprimirEdificios(vector<Edificio> unit, int mapa_coordx, int mapa_coordy);

void imprimirRecursos(vector<Recursos> recs, int mapa_coordx, int mapa_coordy);

#endif