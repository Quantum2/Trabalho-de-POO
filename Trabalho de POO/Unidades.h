#ifndef UNIDADES_JOGO
#define UNIDADES_JOGO

#include <iostream>
#include <string>
#include <vector>
#include "Util.h"
#include "iniciarJogo.h"

using namespace std;

class Base{
public:
	int getIDGeral();
	void setIDGeral(int pid);
	Base(){};
private:
	int id_geral;
};

class Unidade : public Base{
public:
	int getCoordX();
	int getCoordY();
	int getVida();
	void mudarVida(int quantidade);
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

class Edificio : public Base{
public:
	int getCoordX();
	int getCoordY();
	int getVida();
	void mudarVida(int quantidade);
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

class Popul{
public:
	string getNome();
	int getID();
	void setID(int ID);
	void mudarRecs(int tipo, int quantidade);
	vector<int> getRecursos();

	Popul(string nomes);
private:
	string nome;
	int ID;
	int pedra;
	int madeira;
	int ouro;

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
	void mudar(int quantidade);
	Recursos(string tipo_recurso, int x, int y, int id_inicial);
private:
	int ID;
	string tipo;
	int pos_x, pos_y;
};

void Pops_func(Popul pop_a);

vector<Popul> getPops();

void makePops(vector<Popul> p);

void imprimirUnidades(vector<Unidade> unit, int mapa_coordx, int mapa_coordy);

void imprimirEdificios(vector<Edificio> unit, int mapa_coordx, int mapa_coordy);

void imprimirRecursos(vector<Recursos> recs, int mapa_coordx, int mapa_coordy);

#endif