#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <sstream>
#include "verCom.h"

using namespace std;

void imprimirMenu(){
	ifstream loadFich;
	int numRand;
	string temp;

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

	cout << "--------------------------------------------------------------------------" << endl;
	cout << "Dificuldade : " << dificuldade << endl;
	cout << "Definicoes de jogo : " << def_jogo << endl << endl;
}



void musFundo(){
	
}

int main(int argc, char **argv){
	string dif = "Normal";
	string defs = "Originais";

	imprimirMenu();

	imprimirOpcoes(dif, defs);

	musFundo();

	verificarComando();
	
	return 0;
}