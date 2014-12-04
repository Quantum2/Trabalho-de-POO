#ifndef UNIDADES_JOGO
#define UNIDADES_JOGO

#include <iostream>
#include <string>
#include <vector>
#include "Util.h"

using namespace std;

class Unidade{
public:
	int getCoordX();
	int getCoordY();

	Unidade(int x, int y, string tipo);
private:
	int coordernada_x;
	int coordernada_y;
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

class impressor{
public:
	void imprimirUni(Unidade target);
	impressor();
private:
	Unidade aImprimir;
};

#endif