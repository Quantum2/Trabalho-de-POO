#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <sstream>
#include <fstream>
#include "verCom.h"
#include "Consola.h"
#include "musFundo.h"
#include "iniciarJogo.h"

using namespace std;

int verificarComandoJogo(){
	string comando, buf;
	Consola con;
	int com_int = 0;
	int args = 0;

	con.setTextColor(8);
	vector<string> bocados1;

	cout << ">>> ";
	getline(cin, comando);

	istringstream ss(comando);

	while (ss)
	{
		buf.clear();
		switch (args){
		case 0:
			ss >> buf;
			bocados1.push_back(buf);
			break;
		case 1:
			ss >> buf;
			bocados1.push_back(buf);
			break;
		case 2:
			ss >> buf;
			bocados1.push_back(buf);
			break;
		default:
			break;
		}
	}

	if (bocados1[0] == "load"){                              //Verificaçao e implementação do comando LOAD  **EM PROGRESSO**
		ifstream ficheiro;
		string temp;

		cout << "A carregar o ficheiro de configuracao " << bocados1[1] << "..." << endl;

		ficheiro.open(bocados1[1]);

		while (!ficheiro.eof()){
			getline(ficheiro, temp);
		}

		com_int = 1;
		ficheiro.close();
		verificarComandoJogo();
	}

	if (bocados1[0] == "mkgame")
	{
		criarCampo(stoi(bocados1[1]), stoi(bocados1[2]));
	}

	if (com_int == 0){
		cout << "Comando nao encontrado !" << endl;
		getchar();
		criarCampo(LINHAS, COLUNAS);
		verificarComandoJogo();
	}

	return 0;
}