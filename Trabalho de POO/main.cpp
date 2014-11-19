#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>

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

int main(){

	imprimirMenu();
	
	return 0;
}