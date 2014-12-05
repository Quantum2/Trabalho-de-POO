#include "iniciarJogo.h"

vector<Unidade> units;
int coords_mapa_x, coords_mapa_y;

Mapa::Mapa(int tamx, int tamy)
{
	setSize(tamx, tamy);
	defTam(LINHAS, COLUNAS);
	setCoords(0, 0);
}

void Mapa::setSize(int tam1, int tam2){
	size_x = tam1;
	size_y = tam2;
}

void Mapa::setCoords(int x, int y){
	coords_x = x;
	coords_y = y;
}

void Mapa::defTam(int a, int b)
{
	tam_x = a;
	tam_y = b;
}

void Mapa::imprimirMapa()
{
	int i, j;

	cout << endl;
	for (j = 0; j <= tam_y + 2; j++){
		cout << char(205);
	}
	cout << endl;
	for (i = 0; i <= tam_x; i++){
		cout << char(186);
		for (j = 0; j <= tam_y; j++){
			cout << " ";
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

	return coords_x;
}

int Mapa::getCoords_Y(){

	return coords_y;
}

Sidebar::Sidebar(int colunas){
	setDist(colunas);
}

void Sidebar::setDist(int colunas){
	dist = colunas + 5;
}

void Sidebar::imprimirSidebar(){
	Consola cursor;
	char topo[] = "----------------------\n";								//Mudar para string C++
	char lateral[] = "|                    |\n";
	char enter[] = "\n";
	DWORD saida;
	HANDLE hconsola;
	int i, linhas_sidebar = 24;
	hconsola = GetStdHandle(STD_OUTPUT_HANDLE);
	
	cursor.gotoxy(dist, 2);
	cursor.setTextColor(cursor.AMARELO_CLARO);

	WriteConsoleA(hconsola, topo, strlen(topo), &saida, NULL);

	for (i = 0; i <= linhas_sidebar; i++){
		cursor.gotoxy(dist, 3 + i);
		WriteConsoleA(hconsola, lateral, strlen(lateral), &saida, NULL);
		if (i == linhas_sidebar){
			cursor.gotoxy(dist, 3 + i);
			WriteConsoleA(hconsola, topo, strlen(topo), &saida, NULL);
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

void criarUnidades(string tipo, string nome_pop, int x, int y){
	Unidade temp(x, y, tipo);

	units.push_back(temp);

	imprimirUnidades(units, coords_mapa_x, coords_mapa_y);
}