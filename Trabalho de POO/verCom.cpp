#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <sstream>
#include "verCom.h"
#include "Consola.h"

using namespace std;

int verificarComando(){
	string comando, temp, buf;
	int stringNum;
	Consola con;

	con.setTextColor(8);
	vector<string> bocados1;
	vector<string> bocados2;

	cout << "Escreva um comando : " ;
	cin >> comando;
	temp = comando;

	stringstream ss(comando);
	ss >> buf;
	bocados1.push_back(buf);
	comando = bocados1[0];

	cout << "O comando e : " << comando << endl;  //Eliminar este comando futuramente, funcao de debug apenas para verificar separaçao de string

	stringNum = stoi(bocados1[0], nullptr, 0);

	switch (stringNum)
	{
	default:
		cout << "Comando desconhecido";
		return 1;
		break;
	}
}