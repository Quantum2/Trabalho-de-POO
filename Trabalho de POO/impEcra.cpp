#include "impEcra.h"

using namespace std;

void imprimirMenu(){
	ifstream loadFich;
	int numRand;
	string temp, fileName;
	int i_temp, i;

	Consola con;
	con.setTextColor(11);    //Mete cor da arte de menu a azul claro

	srand(time(NULL));
	numRand = (rand() % 3) + 1;    //Gerar um numero aleatorio entre 1 e 3 (itens de arte do menu)
	fileName = "men" + to_string(numRand);
	fileName = fileName + ".txt";
	
	loadFich.open(fileName);  //Aqui começa a carregar os ficheiros com a arte de menu

	if (loadFich.is_open()){
		while (!loadFich.eof()){
			getline(loadFich, temp);
			cout << temp;
			cout << endl;
		}
	}
	loadFich.close();
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
