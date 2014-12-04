#include "Unidades.h"

Unidade::Unidade(int x, int y, string tipo){
	vida = 100;
	
	setCoords(x,y);
	setTipo(tipo);
}

void Unidade::setCoords(int x, int y){
	coordernada_x = x;
	coordernada_y = y;
}

void Unidade::setTipo(string tipo_en){
	tipo = tipo_en;
}

Popul::Popul(string nomes){
	setNome(nomes);
}

void Popul::setNome(string nomes){
	nome = nomes;
}