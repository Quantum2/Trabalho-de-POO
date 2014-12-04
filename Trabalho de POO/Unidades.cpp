#include "Unidades.h"

vector<Popul> populacoes;

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

string Unidade::getTipo(){
	return tipo;
}

Popul::Popul(string nomes){
	setNome(nomes);
}

void Popul::setNome(string nomes){
	nome = nomes;
}

string Popul::getNome(){
	return nome;
}

void Pops_func(Popul pop_a){
	populacoes.push_back(pop_a);
	cout << "Populacao " << pop_a.getNome() << " adicionada" << endl;
	getchar();
}