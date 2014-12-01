#ifndef UNIDADES_JOGO
#define UNIDADES_JOGO

#include <iostream>
#include <string>

using namespace std;

class Castelo{
public:
	int getCoordX();
	int getCoordY();

	Castelo(int x, int y);
private:
	int coordernada_x;
	int coordernada_y;
	int vida;

	void setCoords(int x, int y);
	Castelo(){}
};

class Soldado{
public:
	int getCoordX();
	int getCoordY();

	Soldado(int x, int y);
private:
	int coordernada_x;
	int coordernada_y;

	void setCoords(int x, int y);

	Soldado() {}
};

class Popul{
public:
	string getNome();
	int getQuantidade();
private:
	string nome;
	int quantidade;

	Popul(){}
};

#endif