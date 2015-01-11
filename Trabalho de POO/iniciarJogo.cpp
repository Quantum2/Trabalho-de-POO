#include "iniciarJogo.h"

#define TEMPO_ESPERA 850
#define QUANTIDADE_MINAR 10

vector<Unidade> units;
vector<Edificio> barracos;
vector<Recursos> fontes_recursos;

Mapa mapa_global(LINHAS, COLUNAS);
int coords_mapa_x, coords_mapa_y;
int posicao_jogo_x, posicao_jogo_y;
int unidade_selecionada, select_on = 0;
int unidade_previa;

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
	string temp, tipo;
	DWORD saida;
	HANDLE hconsola;
	int i, linhas_sidebar = 24, x, tipo_sel;
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

		if (i == 3 && select_on == 1)                                                               //Informaçao de unidade aqui
		{
			cursor.gotoxy(dist + 1, 3 + i);
			cursor.setTextColor(cursor.VERMELHO_CLARO);

			for (x = 0; x < units.size(); x++){
				if (units.size() >= 1){
					if (units[x].getIDGeral() == unidade_selecionada){

						if (units[x].getTipo() == "sold"){
							temp = "Tipo : Soldado";
							for (int x = 4; x < temp.length() / 2; x++){
								cout << " ";
							}
							cout << temp << endl;
						}

						if (units[x].getTipo() == "camp"){
							temp = "Tipo : Campones";
							for (int x = 4; x < temp.length() / 2; x++){
								cout << " ";
							}
							cout << temp << endl;
						}

						if (units[x].getTipo() == "caval"){
							temp = "Tipo : Cavaleiro";
							for (int x = 4; x < temp.length() / 2; x++){
								cout << " ";
							}
							cout << temp << endl;
						}

						if (units[x].getTipo() == "camp_caval"){
							temp = "Tipo : Campones a Cavalo";
							for (int x = 4; x < temp.length() / 2; x++){
								cout << " ";
							}
							cout << temp << endl;
						}
						tipo_sel = 1;
						break;
					}
				}
			}

			for (x = 0; x < barracos.size(); x++){
				if (barracos.size() >= 1){
					if (barracos[x].getIDGeral() == unidade_selecionada){

						if (barracos[x].getTipo() == "quar"){
							temp = "Tipo : Quartel";

							for (int x = 4; x < temp.length() / 2; x++){
								cout << " ";
							}

							cout << temp << endl;
						}

						if (barracos[x].getTipo() == "esta"){
							temp = "Tipo : Estabulo";

							for (int x = 4; x < temp.length() / 2; x++){
								cout << " ";
							}
							cout << temp << endl;
						}

						if (barracos[x].getTipo() == "quinta"){
							temp = "Tipo : Quinta";

							for (int x = 4; x < temp.length() / 2; x++){
								cout << " ";
							}
							cout << temp << endl;
						}

						if (barracos[x].getTipo() == "cast"){
							temp = "Tipo : Castelo";

							for (int x = 4; x < temp.length() / 2; x++){
								cout << " ";
							}
							cout << temp << endl;
						}
						tipo_sel = 2;
						break;
					}
				}
			}
		}				

		if (i == 4 && select_on == 1)
		{
			if (tipo_sel == 1){
				cursor.gotoxy(dist + 1, 3 + i);
				cursor.setTextColor(cursor.VERMELHO_CLARO);
				temp = "Vida: " + to_string(units[x].getVida());

				for (int x = 3; x < temp.length(); x++){
					cout << " ";
				}

				cout << temp << endl;
			}
			if (tipo_sel == 2){
				cursor.gotoxy(dist + 1, 3 + i);
				cursor.setTextColor(cursor.VERMELHO_CLARO);
				temp = "Vida: " + to_string(barracos[x].getVida());

				for (int x = 3; x < temp.length(); x++){
					cout << " ";
				}

				cout << temp << endl;
			}
		}

		if (i == 10){
			if (getPops().size() != 0){
				string temp;
				cursor.gotoxy(dist + 1, 3 + i);
				cursor.setTextColor(cursor.VERDE);

				temp = "Nome: " + getPops()[0].getNome();

				for (int x = 3; x < temp.size(); x++){
					cout << " ";
				}
				cout << temp;
			}
		}
		if (i == 11 && getPops().size() != 0){
			cursor.gotoxy(dist + 1, 3 + i);
			cursor.setTextColor(cursor.VERDE);
			temp = "O: " + to_string(getPops()[0].getRecursos()[0]) + " P: " + to_string(getPops()[0].getRecursos()[1]) + " M: " + to_string(getPops()[0].getRecursos()[1]);

			for (int x = 15; x < temp.size(); x++){
				cout << " ";
			}
			cout << temp;
		}

		if (i == 13){
			if (getPops().size() > 1){
				string temp;
				cursor.gotoxy(dist + 1, 3 + i);
				cursor.setTextColor(cursor.AZUL);

				temp = "Nome: " + getPops()[1].getNome();

				for (int x = 3; x < temp.size(); x++){
					cout << " ";
				}
				cout << temp;
			}
		}
		if (i == 14 && getPops().size() > 1){
			cursor.gotoxy(dist + 1, 3 + i);
			cursor.setTextColor(cursor.AZUL);
			temp = "O: " + to_string(getPops()[1].getRecursos()[0]) + " P: " + to_string(getPops()[1].getRecursos()[1]) + " M: " + to_string(getPops()[1].getRecursos()[1]);

			for (int x = 15; x < temp.size(); x++){
				cout << " ";
			}
			cout << temp;
		}

		if (i == 16){
			if (getPops().size() > 2){
				string temp;
				cursor.gotoxy(dist + 1, 3 + i);
				cursor.setTextColor(cursor.ROXO);

				temp = "Nome: " + getPops()[2].getNome();

				for (int x = 3; x < temp.size(); x++){
					cout << " ";
				}
				cout << temp;
			}
		}
		if (i == 17 && getPops().size() > 2){
			cursor.gotoxy(dist + 1, 3 + i);
			cursor.setTextColor(cursor.ROXO);
			temp = "O: " + to_string(getPops()[2].getRecursos()[0]) + " P: " + to_string(getPops()[2].getRecursos()[1]) + " M: " + to_string(getPops()[2].getRecursos()[1]);

			for (int x = 15; x < temp.size(); x++){
				cout << " ";
			}
			cout << temp;
		}

		if (i == 19){
			if (getPops().size() > 3){
				string temp;
				cursor.gotoxy(dist + 1, 3 + i);
				cursor.setTextColor(cursor.CYAN_CLARO);

				temp = "Nome: " + getPops()[3].getNome();

				for (int x = 3; x < temp.size(); x++){
					cout << " ";
				}
				cout << temp;
			}
		}
		if (i == 20 && getPops().size() > 3){
			cursor.gotoxy(dist + 1, 3 + i);
			cursor.setTextColor(cursor.CYAN_CLARO);
			temp = "O: " + to_string(getPops()[3].getRecursos()[0]) + " P: " + to_string(getPops()[3].getRecursos()[1]) + " M: " + to_string(getPops()[3].getRecursos()[1]);

			for (int x = 15; x < temp.size(); x++){
				cout << " ";
			}
			cout << temp;
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
	int temp_id;

	temp_id = units.size() + barracos.size();
	temp_id = temp_id + 1;

	temp.setIDGeral(temp_id);
	units.push_back(temp);

	imprimirUnidades(units, coords_mapa_x, coords_mapa_y);

	verificarComandoJogo();
}

void criarEdi(string tipo, string nome_pop, int x, int y, int pop_id){
	Edificio temp(x, y, tipo, units.size() + 1, pop_id);
	int temp_id;

	temp_id = units.size() + barracos.size();
	temp_id = temp_id + 1;

	temp.setIDGeral(temp_id);
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

	unidade_selecionada = id;

	if (id < 1){
		cout << "Insira um ID valido" << endl;
		select_on = 0;
	}

	if (id > units.size() + barracos.size()){
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
		for (int i = 0; i < units.size(); i++){
			if (units[i].getIDGeral() == id)
				units[i].mudarCoordenadas(units[i].getCoordX() + x, units[i].getCoordY() + y);
		}
	}

	if (tipo_movimento == 2){
		for (int i = 0; i < units.size(); i++){
			if (units[i].getIDGeral() == id)
				units[i].mudarCoordenadas(x, y);
		}
	}

	resetEcra();
	verificarComandoJogo();
}

void colorFonteRecursos(string tipo, int x, int y){
	Consola con;

	con.gotoxy(x, y);
	if (tipo == "flo"){
		Recursos temp("Floresta", x, y, fontes_recursos.size() + 1);
		fontes_recursos.push_back(temp);
	}
	if (tipo == "min"){
		Recursos temp("Mina", x, y, fontes_recursos.size() + 1);
		fontes_recursos.push_back(temp);
	}
	if (tipo == "ped"){
		Recursos temp("Pedreira", x, y, fontes_recursos.size() + 1);
		fontes_recursos.push_back(temp);
	}

	resetEcra();
}

void atacar(int id, int id_vitima){
	int pos_x_vit, pos_y_vit, pos_vit_id, f_ataque, dano;
	float defesa_vit;
	bool vit_existe = false;
	Consola con;

	for (int i = 0; i < units.size(); i++){
		if (units[i].getIDGeral() == id_vitima)
		{
			pos_x_vit = units[i].getCoordX();
			pos_y_vit = units[i].getCoordY();
			pos_vit_id = i;
			vit_existe = true;
		}
	}

	for (int i = 0; i < units.size(); i++){
		if (units[i].getIDGeral() == id && vit_existe == true)
		{
			units[i].mudarCoordenadas(pos_x_vit, pos_y_vit);

			if (units[i].getTipo() == "sold")
			{
				f_ataque = 5;
				defesa_vit = 1;
				units[i].mudarCoordenadas(pos_x_vit - 1, pos_y_vit - 1);

				if (units[pos_vit_id].getTipo() == "sold")
					defesa_vit = 0.2f;
				if (units[pos_vit_id].getTipo() == "caval")
					defesa_vit = 0.4f;
				if (units[pos_vit_id].getTipo() == "camp")
					defesa_vit = 0;
				if (units[pos_vit_id].getTipo() == "camp_caval")
					defesa_vit = 0;
				if (units[pos_vit_id].getTipo() == "camp")
					defesa_vit = 0.5f;

				resetEcra();
				con.gotoxy(units[pos_vit_id].getCoordX() + 2, units[pos_vit_id].getCoordY());
				dano = f_ataque * (1 - defesa_vit);
				cout << "-" << dano;
				con.gotoxy(units[pos_vit_id].getCoordX() + 2, units[pos_vit_id].getCoordY() + 1);
				cout << "V: " << units[pos_vit_id].getVida();
				Sleep(TEMPO_ESPERA);
				units[pos_vit_id].mudarVida(units[pos_vit_id].getVida() - (f_ataque * (1 - defesa_vit)));
			}

			if (units[i].getTipo() == "caval")
			{
				f_ataque = 8;
				defesa_vit = 1;
				units[i].mudarCoordenadas(pos_x_vit - 1, pos_y_vit - 1);

				if (units[pos_vit_id].getTipo() == "sold")
					defesa_vit = 0.2f;
				if (units[pos_vit_id].getTipo() == "caval")
					defesa_vit = 0.4f;
				if (units[pos_vit_id].getTipo() == "camp")
					defesa_vit = 0;
				if (units[pos_vit_id].getTipo() == "camp_caval")
					defesa_vit = 0;
				if (units[pos_vit_id].getTipo() == "camp")
					defesa_vit = 0.5f;

				resetEcra();
				con.gotoxy(units[pos_vit_id].getCoordX() + 2, units[pos_vit_id].getCoordY());
				dano = f_ataque * (1 - defesa_vit);
				cout << "-" << dano;
				con.gotoxy(units[pos_vit_id].getCoordX() + 2, units[pos_vit_id].getCoordY() + 1);
				cout << "V: " << units[pos_vit_id].getVida();
				Sleep(TEMPO_ESPERA);
				units[pos_vit_id].mudarVida(units[pos_vit_id].getVida() - (f_ataque * (1 - defesa_vit)));
			}

			if (units[i].getTipo() == "catap")
			{
				f_ataque = 15;
				defesa_vit = 1;
				units[i].mudarCoordenadas(pos_x_vit - 1, pos_y_vit - 1);

				if (units[pos_vit_id].getTipo() == "sold")
					defesa_vit = 0.2f;
				if (units[pos_vit_id].getTipo() == "caval")
					defesa_vit = 0.4f;
				if (units[pos_vit_id].getTipo() == "camp")
					defesa_vit = 0;
				if (units[pos_vit_id].getTipo() == "camp_caval")
					defesa_vit = 0;
				if (units[pos_vit_id].getTipo() == "camp")
					defesa_vit = 0.5f;

				resetEcra();
				con.gotoxy(units[pos_vit_id].getCoordX() + 2, units[pos_vit_id].getCoordY());
				dano = f_ataque * (1 - defesa_vit);
				cout << "-" << dano;
				con.gotoxy(units[pos_vit_id].getCoordX() + 2, units[pos_vit_id].getCoordY() + 1);
				cout << "V: " << units[pos_vit_id].getVida();
				Sleep(TEMPO_ESPERA);
				units[pos_vit_id].mudarVida(units[pos_vit_id].getVida() - (f_ataque * (1 - defesa_vit)));
			}
		}
	}

	vit_existe = 0;

	for (int i = 0; i < barracos.size(); i++){
		if (barracos[i].getIDGeral() == id_vitima)
		{
			pos_x_vit = barracos[i].getCoordX();
			pos_y_vit = barracos[i].getCoordY();
			pos_vit_id = i;
			vit_existe = true;
		}
	}

	for (int i = 0; i < units.size(); i++){
		if (units[i].getIDGeral() == id && vit_existe == true)
		{
			units[i].mudarCoordenadas(pos_x_vit, pos_y_vit);

			if (units[i].getTipo() == "sold")
			{
				f_ataque = 5;
				defesa_vit = 1;
				units[i].mudarCoordenadas(pos_x_vit - 1, pos_y_vit - 1);

				if (barracos[pos_vit_id].getTipo() == "cast")
					defesa_vit = 0;
				if (barracos[pos_vit_id].getTipo() == "quar")
					defesa_vit = 0;
				if (barracos[pos_vit_id].getTipo() == "esta")
					defesa_vit = 0;
				if (barracos[pos_vit_id].getTipo() == "quinta")
					defesa_vit = 0;

				resetEcra();
				con.gotoxy(barracos[pos_vit_id].getCoordX() + 2, barracos[pos_vit_id].getCoordY());
				dano = f_ataque * (1 - defesa_vit);
				cout << "-" << dano;
				con.gotoxy(barracos[pos_vit_id].getCoordX() + 2, barracos[pos_vit_id].getCoordY() + 1);
				cout << "V: " << barracos[pos_vit_id].getVida();
				Sleep(TEMPO_ESPERA);
				barracos[pos_vit_id].mudarVida(barracos[pos_vit_id].getVida() - (f_ataque * (1 - defesa_vit)));
			}

			if (units[i].getTipo() == "caval")
			{
				f_ataque = 8;
				defesa_vit = 1;
				units[i].mudarCoordenadas(pos_x_vit - 1, pos_y_vit - 1);

				if (barracos[pos_vit_id].getTipo() == "cast")
					defesa_vit = 0;
				if (barracos[pos_vit_id].getTipo() == "quar")
					defesa_vit = 0;
				if (barracos[pos_vit_id].getTipo() == "esta")
					defesa_vit = 0;
				if (barracos[pos_vit_id].getTipo() == "quinta")
					defesa_vit = 0;

				resetEcra();
				con.gotoxy(barracos[pos_vit_id].getCoordX() + 2, barracos[pos_vit_id].getCoordY());
				dano = f_ataque * (1 - defesa_vit);
				cout << "-" << dano;
				con.gotoxy(barracos[pos_vit_id].getCoordX() + 2, barracos[pos_vit_id].getCoordY() + 1);
				cout << "V: " << barracos[pos_vit_id].getVida();
				Sleep(TEMPO_ESPERA);
				barracos[pos_vit_id].mudarVida(barracos[pos_vit_id].getVida() - (f_ataque * (1 - defesa_vit)));
			}

			if (units[i].getTipo() == "catap")
			{
				f_ataque = 15;
				defesa_vit = 1;
				units[i].mudarCoordenadas(pos_x_vit - 1, pos_y_vit - 1);

				if (barracos[pos_vit_id].getTipo() == "cast")
					defesa_vit = 0;
				if (barracos[pos_vit_id].getTipo() == "quar")
					defesa_vit = 0;
				if (barracos[pos_vit_id].getTipo() == "esta")
					defesa_vit = 0;
				if (barracos[pos_vit_id].getTipo() == "quinta")
					defesa_vit = 0;

				resetEcra();
				con.gotoxy(barracos[pos_vit_id].getCoordX() + 2, barracos[pos_vit_id].getCoordY());
				dano = f_ataque * (1 - defesa_vit);
				cout << "-" << dano;
				con.gotoxy(barracos[pos_vit_id].getCoordX() + 2, barracos[pos_vit_id].getCoordY() + 1);
				cout << "V: " << barracos[pos_vit_id].getVida();
				Sleep(TEMPO_ESPERA);
				barracos[pos_vit_id].mudarVida(barracos[pos_vit_id].getVida() - (f_ataque * (1 - defesa_vit)));
			}
		}
	}

	for (size_t i = 0; i < units.size(); i++)
		if (units[i].getVida() <= 0)
			units.erase(units.begin() + i);

	for (size_t i = 0; i < barracos.size(); i++)
		if (barracos[i].getVida() <= 0)
			barracos.erase(barracos.begin() + i);

	resetEcra();
	verificarComandoJogo();
}

void recRecursos(string unidade_id, int id){
	int unidade_anterior;
	vector<Popul> pops_temp = getPops();

	for (int i = 0; i < units.size(); i++){
		if (units[i].getIDGeral() == id && unidade_id == "-"){
			movimentarUnidades(unidade_anterior, fontes_recursos[stoi(unidade_id)].getPosX() + 1, fontes_recursos[stoi(unidade_id)].getPosY() + 1, 2);

			if (units[i].getTipo() == "camp"){
				fontes_recursos[stoi(unidade_id)].res_restante = fontes_recursos[stoi(unidade_id)].res_restante - QUANTIDADE_MINAR;

				if (fontes_recursos[stoi(unidade_id)].getTipo() == "flo"){
					pops_temp[units[i].id_pop].mudarRecs(3, QUANTIDADE_MINAR);
				}
				if (fontes_recursos[stoi(unidade_id)].getTipo() == "min"){
					pops_temp[units[i].id_pop].mudarRecs(1, QUANTIDADE_MINAR);
				}
				if (fontes_recursos[stoi(unidade_id)].getTipo() == "ped"){
					pops_temp[units[i].id_pop].mudarRecs(2, QUANTIDADE_MINAR);
				}

				makePops(pops_temp);
			}
		}
		else if (units[i].getIDGeral() == id){
			unidade_anterior = id;
			movimentarUnidades(id, fontes_recursos[stoi(unidade_id) - 1].getPosX() + 1, fontes_recursos[stoi(unidade_id) - 1].getPosY() + 1, 2);
			
			if (units[i].getTipo() == "camp"){
				fontes_recursos[stoi(unidade_id) - 1].res_restante = fontes_recursos[stoi(unidade_id) - 1].res_restante - QUANTIDADE_MINAR;

				if (fontes_recursos[stoi(unidade_id) - 1].getTipo() == "flo"){
					pops_temp[units[i].id_pop].mudarRecs(3, QUANTIDADE_MINAR);
				}
				if (fontes_recursos[stoi(unidade_id) - 1].getTipo() == "min"){
					pops_temp[units[i].id_pop].mudarRecs(1, QUANTIDADE_MINAR);
				}
				if (fontes_recursos[stoi(unidade_id) - 1].getTipo() == "ped"){
					pops_temp[units[i].id_pop].mudarRecs(2, QUANTIDADE_MINAR);
				}

				makePops(pops_temp);
			}
		}
	}
}

void ia(int turnos){
	//A fazer
}

void resetEcra(){
	Mapa map(largura, altura);
	Sidebar sidy(map.getTamY());
	Consola con;

	reimp(map, sidy);
	con.setTextColor(8);
	imprimirUnidades(units, coords_mapa_x, coords_mapa_y);
	imprimirEdificios(barracos, coords_mapa_x, coords_mapa_y);
	imprimirRecursos(fontes_recursos, coords_mapa_x, coords_mapa_y);
}