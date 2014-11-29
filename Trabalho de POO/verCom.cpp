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
	Consola con;
	int com_int = 0;

	con.setTextColor(8);
	vector<string> bocados1;
	vector<string> argumentos;

	cout << "Escreva um comando : ";
	cin >> comando;
	temp = comando;

	stringstream ss(comando);
	ss >> buf;
	bocados1.push_back(buf);
	ss.flush();

	if (buf == "load"){                                                                     //Verificaçao e implementação do comando LOAD  **EM PROGRESSO**
		stringstream s_temp(temp);
		com_int = 1;
		buf.clear();
		
		while (s_temp >> buf){
			argumentos.push_back(buf);
		}

		if (argumentos.size() != 1)
		{
			cout << "Numero de argumentos errado !" << argumentos.size() << endl;
			getchar();
		}


		verificarComandoJogo();
	}

	if (com_int == 0){
		cout << "Comando nao encontrado !" << endl;
		fflush(stdin);
		getchar();
		criarCampo(LINHAS, COLUNAS);
		verificarComandoJogo();
	}

	return 0;
}