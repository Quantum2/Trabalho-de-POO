#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <sstream>
#include "verCom.h"

using namespace std;

void verificarComando(){
	string comando, temp, buf;
	int hash;

	vector<string> bocados1;
	vector<string> bocados2;

	cin >> comando;
	temp = comando;

	stringstream ss(comando);
	ss >> buf;
	bocados1.push_back(buf);
	comando = bocados1[0];

	cout << "O comando e : " << comando << endl;  //Eliminar este comando, funcao de debug apenas

	switch (hash)
	{
	default:
		break;
	}
}