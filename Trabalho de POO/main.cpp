#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <sstream>
#include <Windows.h>
#include "verCom.h"
#include "Consola.h"
#include "musFundo.h"

#pragma comment(lib, "winmm.lib")

#define LINHAS 35
#define COLUNAS 80

#define TAM_X 7
#define TAM_Y 10

using namespace std;

void imprimirMenu(){
	ifstream loadFich;
	int numRand;
	string temp;

	Consola con;
	con.setTextColor(11);    //Mete cor da arte de menu a azul claro

	srand(time(NULL));
	numRand = (rand() % 3) + 1;    //Gerar um numero aleatorio entre 1 e 3 (itens de arte do menu)
	cout << "A carregar ficheiro de menu "<< numRand << "...\n" << endl;       //Função de debug - LEMBRAR DE APAGAR

	switch (numRand)
	{
	case 1:
		loadFich.open("men1.txt");  //Aqui começa a carregar os ficheiros com a arte de menu

		if (loadFich.is_open()){
			while(!loadFich.eof()){
				getline(loadFich,temp);
				cout << temp;
				cout << endl;
			}
		}
		loadFich.close();
		break;
	case 2:
		loadFich.open("men2.txt");

		if (loadFich.is_open()){
			while(!loadFich.eof()){
				getline(loadFich,temp);
				cout << temp;
				cout << endl;
			}
		}
		loadFich.close();
		break;
	case 3:
		loadFich.open("men3.txt");

		if (loadFich.is_open()){
			while(!loadFich.eof()){
				getline(loadFich,temp);
				cout << temp;
				cout << endl;
			}
		}
		loadFich.close();
		break;
	default:
		break;
	}
}

void imprimirOpcoes(string dificuldade, string def_jogo){
	Consola con;
	con.setTextColor(14);
	con.setTextSize(TAM_X, TAM_Y);

	int temp, i;
	string s_temp;

	for (i = 0; i < COLUNAS; i++)
		cout << "-";
	
	cout << endl;

	s_temp = "Dificuldade : " + dificuldade;

	temp = COLUNAS / 2;
	temp = temp - (s_temp.length() / 2);
	for (i = 0; i < temp; i++)
		cout << " ";

	cout << s_temp << endl;

	s_temp = "Definicoes de jogo : " + def_jogo;

	temp = COLUNAS / 2;
	temp = temp - (s_temp.length() / 2);

	for (i = 0; i < temp; i++)
		cout << " ";

	cout << s_temp << endl << endl;
}



int main(int argc, char **argv){
	string dif = "Normal";
	string defs = "Originais";
	int abort = 0;
	Consola con;

	con.setScreenSize(LINHAS, COLUNAS);

	imprimirMenu();

	imprimirOpcoes(dif, defs);

	musFundo(1);

	while (abort == 0)
	{
		verificarComando();
		con.clrscr();
		imprimirMenu();
		imprimirOpcoes(dif, defs);
	}
	
	return 0;
}