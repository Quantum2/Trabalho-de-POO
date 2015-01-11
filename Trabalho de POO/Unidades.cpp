#include "Unidades.h"

vector<Popul> populacoes;

void Base::setIDGeral(int pid){
	id_geral = pid;
}

int Base::getIDGeral(){
	return id_geral;
}

Unidade::Unidade(int x, int y, string tipo, int i, int pid){
	id = i;
	id_pop = pid;
	
	setCoords(x,y);
	setTipo(tipo);

	if (tipo == "sold")
		vida = 40;
	if (tipo == "caval")
		vida = 60;
	if (tipo == "camp")
		vida = 20;
	if (tipo == "camp_caval")
		vida = 40;
}

Edificio::Edificio(int x, int y, string tip, int i, int pid){
	vida = 100;
	id = i;
	id_pop = pid;

	coordernada_x = x;
	coordernada_y = y;
	tipo = tip;
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

int Edificio::getCoordX(){
	return coordernada_x;
}

int Unidade::getCoordY(){
	return coordernada_y;
}

int Edificio::getCoordY(){
	return coordernada_y;
}

int Unidade::getVida(){
	return vida;
}

void Unidade::mudarVida(int quantidade){
	vida = quantidade;
}

void Edificio::mudarVida(int quantidade){
	vida = quantidade;
}

int Edificio::getVida(){
	return vida;
}

void Unidade::mudarCoordenadas(int cx, int cy){
	coordernada_x = cx;
	coordernada_y = cy;
}

string Unidade::getTipo(){
	return tipo;
}

string Edificio::getTipo(){
	return tipo;
}

Popul::Popul(string nomes){
	setNome(nomes);
	ouro = 20;
	pedra = 50;
	madeira = 200;
}

void Popul::setNome(string nomes){
	nome = nomes;
}

void Popul::mudarRecs(int tipo, int quantidade){
	if (tipo == 1)
		ouro = ouro + quantidade;
	if (tipo == 2)
		pedra = pedra + quantidade;
	if (tipo == 3)
		madeira = madeira + quantidade;
}

vector<int> Popul::getRecursos(){
	vector<int> vec;
	vec.push_back(ouro);
	vec.push_back(pedra);
	vec.push_back(madeira);

	return vec;
}

string Popul::getNome(){
	return nome;
}

Recursos::Recursos(string tipo_recurso, int x, int y, int id_inicial){
	tipo = tipo_recurso;
	pos_x = x;
	pos_y = y;
	ID = id_inicial;
	res_restante = 100;
}

int Recursos::getPosX(){
	return pos_x;
}

int Recursos::getPosY(){
	return pos_y;
}

int Recursos::getID(){
	return ID;
}

string Recursos::getTipo(){
	return tipo;
}

void Pops_func(Popul pop_a){
	if (populacoes.size() <= 10){
		populacoes.push_back(pop_a);
		cout << "Populacao " << pop_a.getNome() << " adicionada" << endl;
		getchar();
	}
	if (populacoes.size() > 10){
		cout << "Quantidade maxima de populacoes atingida" << endl;
	}
}

vector<Popul> getPops(){
	return populacoes;
}

void makePops(vector<Popul> p){
	populacoes = p;
}

void imprimirUnidades(vector<Unidade> unit, int mapa_coordx, int mapa_coordy){
	int pos_x, pos_y;
	Consola con;
	DWORD saida;
	HANDLE hconsola;
	hconsola = GetStdHandle(STD_OUTPUT_HANDLE);

	//con.setTextColor(con.AZUL_CLARO);

	for (size_t i = 0; i < unit.size(); i++){
		pos_x = unit[i].getCoordX();
		pos_y = unit[i].getCoordY();

		pos_x = pos_x - mapa_global.getCoord_X();
		pos_y = pos_y - mapa_global.getCoords_Y();

		con.setTextColor(unit[i].id_pop + 1);

		if (unit[i].getTipo() == "sold"){
			if (pos_x < COLUNAS && pos_y < LINHAS + 2){
				con.gotoxy(pos_x, pos_y);
				cout << soldado_n;
			}
		}

		if (unit[i].getTipo() == "camp"){
			if (pos_x < COLUNAS && pos_y < LINHAS + 2){
				con.gotoxy(pos_x, pos_y);
				cout << campones;
			}
		}

		if (unit[i].getTipo() == "caval"){
			if (pos_x < COLUNAS && pos_y < LINHAS + 2){
				con.gotoxy(pos_x, pos_y);
				cout << cavaleiro;
			}
		}

		if (unit[i].getTipo() == "camp_caval"){
			if (pos_x < COLUNAS && pos_y < LINHAS + 2){
				con.gotoxy(pos_x, pos_y);
				cout << camp_caval;
			}
		}

		if (unit[i].getTipo() == "catap"){
			if (pos_x < COLUNAS && pos_y < LINHAS + 2){
				con.gotoxy(pos_x, pos_y);
				cout << catapulta;
			}
		}
	}

	con.gotoxy(0, LINHAS + 4);
	
	for (int j = 0; j < 50; j++){
		WriteConsoleA(hconsola, &limpar, 1, &saida, NULL);
	}

	con.setTextColor(con.BRANCO);
	con.gotoxy(0, LINHAS + 4);
}

void imprimirEdificios(vector<Edificio> unit, int mapa_coordx, int mapa_coordy){
	int pos_x, pos_y;
	Consola con;
	DWORD saida;
	HANDLE hconsola;
	hconsola = GetStdHandle(STD_OUTPUT_HANDLE);

	//con.setTextColor(con.AZUL_CLARO);

	for (size_t i = 0; i < unit.size(); i++){
		pos_x = unit[i].getCoordX();
		pos_y = unit[i].getCoordY();

		pos_x = pos_x - mapa_global.getCoord_X();
		pos_y = pos_y - mapa_global.getCoords_Y();

		con.setTextColor(unit[i].id_pop + 1);

		if (unit[i].getTipo() == "quar"){
			if (pos_x < COLUNAS && pos_y < LINHAS + 2){
				con.gotoxy(pos_x, pos_y);
				WriteConsoleA(hconsola, &topo_e, 1, &saida, NULL);
				WriteConsoleA(hconsola, &topo_d, 1, &saida, NULL);
				con.gotoxy(pos_x, pos_y + 1);
				WriteConsoleA(hconsola, &baixo_e, 1, &saida, NULL);
				WriteConsoleA(hconsola, &baixo_d, 1, &saida, NULL);
			}
		}

		if (unit[i].getTipo() == "esta"){
			if (pos_x < COLUNAS && pos_y < LINHAS + 2){
				con.gotoxy(pos_x, pos_y);
				cout << char(234);
			}
		}

		if (unit[i].getTipo() == "quinta"){
			if (pos_x < COLUNAS && pos_y < LINHAS + 2){
				con.gotoxy(pos_x, pos_y);
				cout << char(227);
			}
		}

		if (unit[i].getTipo() == "cast"){
			if (pos_x < COLUNAS && pos_y < LINHAS + 2){
				con.gotoxy(pos_x, pos_y);
				cout << char(206);
			}
		}
	}

	con.gotoxy(0, LINHAS + 4);

	for (int j = 0; j < 50; j++){
		WriteConsoleA(hconsola, &limpar, 1, &saida, NULL);
	}

	con.setTextColor(con.BRANCO);
	con.gotoxy(0, LINHAS + 4);
}

void imprimirRecursos(vector<Recursos> recs, int mapa_coordx, int mapa_coordy){
	int pos_x, pos_y;
	Consola con;
	DWORD saida;
	HANDLE hconsola;
	hconsola = GetStdHandle(STD_OUTPUT_HANDLE);

	con.setTextColor(con.AZUL_CLARO);

	for (size_t i = 0; i < recs.size(); i++){
		pos_x = recs[i].getPosX();
		pos_y = recs[i].getPosY();

		pos_x = pos_x - mapa_global.getCoord_X();
		pos_y = pos_y - mapa_global.getCoords_Y();

		if (recs[i].getTipo() == "Floresta"){
			con.gotoxy(recs[i].getPosX(), recs[i].getPosY());
			cout << 'F' << recs[i].getID();
		}
		if (recs[i].getTipo() == "Mina"){
			con.gotoxy(recs[i].getPosX(), recs[i].getPosY());
			cout << 'M' << recs[i].getID();
		}
		if (recs[i].getTipo() == "Pedreira"){
			con.gotoxy(recs[i].getPosX(), recs[i].getPosY());
			cout << 'P' << recs[i].getID();
		}
	}

	con.gotoxy(0, LINHAS + 4);

	for (int j = 0; j < 50; j++){
		WriteConsoleA(hconsola, &limpar, 1, &saida, NULL);
	}

	con.setTextColor(con.BRANCO);
	con.gotoxy(0, LINHAS + 4);
}