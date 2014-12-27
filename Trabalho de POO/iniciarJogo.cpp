#include "iniciarJogo.h"

vector<Unidade> units;
vector<Edificio> barracos;

Mapa mapa_global(LINHAS, COLUNAS);
int coords_mapa_x, coords_mapa_y;
int posicao_jogo_x, posicao_jogo_y;
int unidade_selecionada, select_on = 0;

Mapa::Mapa(int tamx, int tamy)
{
	setSize(tamx, tamy);
	defTam(LINHAS, COLUNAS);
	coords_actuais_x = 0;
	coords_actuais_y = 0;
}

void Mapa::setSize(int tam1, int tam2){
	size_x = tam1;
	size_y = tam2;
}

void Mapa::defTam(int a, int b)
{
	tam_x = a;
	tam_y = b;
}

void Mapa::imprimirMapa()
{
	int i, j;
	Consola con;

	con.setTextColor(con.VERDE_CLARO);
	cout << "Coordenadas actuais :  X=" << mapa_global.getCoord_X() << " Y=" << mapa_global.getCoords_Y() << endl;
	con.setTextColor(con.ROXO);

	for (j = 0; j <= tam_y + 2; j++){
		cout << char(205);
	}
	cout << endl;
	for (i = 0; i <= tam_x; i++){
		cout << char(186);
		for (j = 0; j <= tam_y; j++){
			con.setTextColor(con.CINZENTO);
			cout << char(176);
			con.setTextColor(con.ROXO);
		}
		cout << char(186) << endl;
	}
	for (j = 0; j <= tam_y + 2; j++){
		cout << char(205);
	}
	cout << endl;
}

int Mapa::getTamX()
{
	return tam_x;
}

int Mapa::getTamY()
{
	return tam_y;
}

int Mapa::getCoord_X(){

	return coords_actuais_x;
}

int Mapa::getCoords_Y(){

	return coords_actuais_y;
}

void Mapa::setCoords_XY(int x, int y){
	coords_actuais_x = x;
	coords_actuais_y = y;
}

Sidebar::Sidebar(int colunas){
	setDist(colunas);
}

void Sidebar::setDist(int colunas){
	dist = colunas + 5;
}

void Sidebar::imprimirSidebar(){
	Consola cursor;
	char topo[] = "----------------------\n";							                  	//Mudar para string C++
	char lateral[] = "|                    |\n";
	char enter[] = "\n";
	string temp;
	DWORD saida;
	HANDLE hconsola;
	int i, linhas_sidebar = 24;
	hconsola = GetStdHandle(STD_OUTPUT_HANDLE);
	
	cursor.setTextColor(cursor.AMARELO_CLARO);
	cursor.gotoxy(dist, 2);

	WriteConsoleA(hconsola, topo, strlen(topo), &saida, NULL);

	for (i = 0; i <= linhas_sidebar; i++){
		cursor.gotoxy(dist, 3 + i);
		cursor.setTextColor(cursor.AMARELO_CLARO);
		WriteConsoleA(hconsola, lateral, strlen(lateral), &saida, NULL);
		if (i == linhas_sidebar){
			cursor.gotoxy(dist, 3 + i);
			WriteConsoleA(hconsola, topo, strlen(topo), &saida, NULL);
		}

		if (i == 3 && select_on == 1)                                                       //Informaçao de unidade aqui
		{
			cursor.gotoxy(dist + 1, 3 + i);
			cursor.setTextColor(cursor.VERMELHO_CLARO);

			if (units[unidade_selecionada].getTipo() == "quar"){
				temp = "Tipo : Quartel";

				for (int x = 4; x < temp.length() / 2; x++){
					cout << " ";
				}

				cout << temp << endl;

			}


			if (units[unidade_selecionada].getTipo() == "esta"){
				temp = "Tipo : Estabulo";
				
				for (int x = 4; x < temp.length() / 2; x++){
					cout << " ";
				}
				cout << temp << endl;
			}

			if (units[unidade_selecionada].getTipo() == "quinta"){
				temp = "Tipo : Quinta";
				
				for (int x = 4; x < temp.length() / 2; x++){
					cout << " ";
				}
				cout << temp << endl;
			}

			if (units[unidade_selecionada].getTipo() == "cast"){
				temp = "Tipo : Castelo";
				
				for (int x = 4; x < temp.length() / 2; x++){
					cout << " ";
				}
				cout << temp << endl;
			}

			if (units[unidade_selecionada].getTipo() == "sold"){
				temp = "Tipo : Soldado";
				for (int x = 4; x < temp.length() / 2; x++){
					cout << " ";
				}
				cout << temp << endl;
			}

			if (units[unidade_selecionada].getTipo() == "camp"){
				temp = "Tipo : Campones";
				for (int x = 4; x < temp.length() / 2; x++){
					cout << " ";
				}
				cout << temp << endl;
			}

			if (units[unidade_selecionada].getTipo() == "caval"){
				temp = "Tipo : Cavaleiro";
				for (int x = 4; x < temp.length() / 2; x++){
					cout << " ";
				}
				cout << temp << endl;
			}

			if (units[unidade_selecionada].getTipo() == "camp_caval"){
				temp = "Tipo : Campones a Cavalo";
				for (int x = 4; x < temp.length() / 2; x++){
					cout << " ";
				}
				cout << temp << endl;
			}
		}

		if (i == 4 && select_on == 1)
		{
			cursor.gotoxy(dist + 1, 3 + i);
			cursor.setTextColor(cursor.VERMELHO_CLARO);
			temp = "Vida: " + to_string(units[unidade_selecionada].getVida());

			for (int x = 3; x < temp.length(); x++){
				cout << " ";
			}

			cout << temp << endl;
		}
	}

	cursor.gotoxy(0, LINHAS + 4);
}

void criarCampo(int linhas, int colunas){
	Consola con;
	Mapa map(linhas, colunas);
	Sidebar barra(map.getTamY());
	coords_mapa_x = linhas;
	coords_mapa_y = colunas;

	mapa_global = map;
	reimp(map, barra);

	con.gotoxy(0, LINHAS + 4);
}

void reimp(Mapa map, Sidebar barra){
	Consola con;

	con.clrscr();
	con.setScreenSize(LINHAS + 8, COLUNAS + 30);
	con.setTextSize(TAM_X, TAM_Y);
	con.setTextColor(con.ROXO);

	map.imprimirMapa();
	barra.imprimirSidebar();

	}

void criarUnidades(string tipo, string nome_pop, int x, int y, int pop_id){
	Unidade temp(x, y, tipo, units.size() + 1, pop_id);

	units.push_back(temp);

	imprimirUnidades(units, coords_mapa_x, coords_mapa_y);

	verificarComandoJogo();
}

void criarEdi(string tipo, string nome_pop, int x, int y, int pop_id){
	Edificio temp(x, y, tipo, units.size() + 1, pop_id);

	barracos.push_back(temp);

	imprimirEdificios(barracos, coords_mapa_x, coords_mapa_y);

	verificarComandoJogo();
}

void scroll(){
	Consola con;
	int cor_x, cor_y;
	resetEcra();
	
	while (con.getch() != 'c')
	{
		cor_x = mapa_global.getCoord_X();
		cor_y = mapa_global.getCoords_Y();

		if (con.getch() == con.ESQUERDA){
			cout << "A mover para a esquerda..." << endl;

			if (cor_x > 0){
				mapa_global.setCoords_XY(mapa_global.getCoord_X() - 1, mapa_global.getCoords_Y());
			}

			con.getch();
			resetEcra();
		}
		if (con.getch() == con.DIREITA){
			cout << "A mover para a direita..." << endl;

			if (cor_x < mapa_global.getTamX()){
				mapa_global.setCoords_XY(mapa_global.getCoord_X() + 1, mapa_global.getCoords_Y());
			}

			con.getch();
			resetEcra();
		}
		if (con.getch() == con.CIMA){
			cout << "A mover para cima..." << endl;

			if (cor_y > 0){
				mapa_global.setCoords_XY(mapa_global.getCoord_X(), mapa_global.getCoords_Y() - 1);
			}

			con.getch();
			resetEcra();
		}
		if (con.getch() == con.BAIXO){
			cout << "A mover para baixo..." << endl;

			if (cor_y < mapa_global.getTamY()){
				mapa_global.setCoords_XY(mapa_global.getCoord_X(), mapa_global.getCoords_Y() + 1);
			}

			con.getch();
			resetEcra();
		}
	}

	cout << "A mudar para modo comandos" << endl;
	resetEcra();
	verificarComandoJogo();
}

void selecionarUnidades(int id){
	select_on = 1;

	unidade_selecionada = id - 1;

	if (id < 1){
		cout << "Insira um ID valido" << endl;
		select_on = 0;
	}

	if (id > units.size()){
		cout << "Essa unidade nao existe" << endl;
		select_on = 0;
	}

	if (id == 0)
		select_on = 0;
}

void movimentarUnidades(int id, int x, int y, int tipo_movimento){
	
	if (id < 1){
		cout << "Insira um ID valido" << endl;
		getchar();
		resetEcra();
		verificarComandoJogo();
	}
	
	if (tipo_movimento == 1){
		units[id - 1].mudarCoordenadas(units[id - 1].getCoordX() + x, units[id - 1].getCoordY() + y);
	}

	if (tipo_movimento == 2){
		units[id - 1].mudarCoordenadas(x, y);
	}

	resetEcra();
	verificarComandoJogo();
}

void resetEcra(){
	Mapa map(largura, altura);
	Sidebar sidy(map.getTamY());
	Consola con;

	reimp(map, sidy);
	con.setTextColor(8);
	imprimirUnidades(units, coords_mapa_x, coords_mapa_y);
}