#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <sstream>
#include "verCom.h"
#include "Consola.h"
#include "musFundo.h"
#include "iniciarJogo.h"

using namespace std;

int verificarComandoJogo(){
	string comando, temp, buf;
	int controlo = 0;
	Consola con;

	con.setTextColor(8);
	vector<string> bocados1;
	vector<string> bocados2;

	cout << "Escreva um comando : ";
	cin >> comando;
	temp = comando;

	stringstream ss(comando);
	ss >> buf;
	bocados1.push_back(buf);
	ss.flush();

	return 0;
}