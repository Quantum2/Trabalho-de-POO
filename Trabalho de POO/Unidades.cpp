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

int Unidade::getCoordX(){
	return coordernada_x;
}

int Unidade::getCoordY(){
	return coordernada_y;
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

void imprimirUnidades(vector<Unidade> unit, int mapa_coordx, int mapa_coordy){
	int pos_x, pos_y;
	Consola con;
	DWORD saida;
	HANDLE hconsola;
	hconsola = GetStdHandle(STD_OUTPUT_HANDLE);

	for (size_t i = 0; i < unit.size(); i++){
		pos_x = unit[i].getCoordX();
		pos_y = unit[i].getCoordY();

		if (pos_x < mapa_coordx && pos_y < mapa_coordy){
			WriteConsoleA(hconsola, &topo_e, 1, &saida, NULL);
		}
	}
}