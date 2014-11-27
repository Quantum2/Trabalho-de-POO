#include "iniciarJogo.h"

Mapa::Mapa(int tamx, int tamy)
{
	defTam(tamx, tamy);
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
		cout << "-";
	}
	cout << endl;
	for (i = 0; i <= tam_x; i++){
		cout << "|";
		for (j = 0; j <= tam_y; j++){
			cout << " ";
		}
		cout << "|" << endl;
	}
	for (j = 0; j <= tam_y + 2; j++){
		cout << "-";
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

Sidebar::Sidebar(int colunas){
	setDist(colunas);
}

void Sidebar::setDist(int colunas){
	dist = colunas + 5;
}

void Sidebar::imprimirSidebar(){
	Consola cursor;
	char topo[] = "----------------------";
	DWORD saida;
	HANDLE hconsola;
	hconsola = GetStdHandle(STD_OUTPUT_HANDLE);
	
	cursor.gotoxy(dist, 2);
	cursor.setTextColor(cursor.AMARELO_CLARO);

	WriteConsoleA(hconsola, topo, strlen(topo), &saida, NULL);

	cursor.gotoxy(0, LINHAS + 4);
}

void criarCampo(int linhas, int colunas){
	Consola con;
	Mapa map(linhas, colunas);
	Sidebar barra(map.getTamY());

	con.clrscr();
	con.setScreenSize(linhas + 6, colunas + 30);
	con.setTextSize(TAM_X, TAM_Y);
	con.setTextColor(con.ROXO);

	map.imprimirMapa();
	barra.imprimirSidebar();

	verificarComandoJogo();
}