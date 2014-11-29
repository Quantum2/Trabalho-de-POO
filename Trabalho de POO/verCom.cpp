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
	string comando, buf;
	Consola con;
	int com_int = 0;

	con.setTextColor(8);
	vector<string> bocados1;
	vector<string> argumentos;

	cout << "Escreva um comando : ";
	cin >> comando;

	stringstream s_temp(comando);
	stringstream ss(comando);
	ss >> buf;
	bocados1.push_back(buf);
	ss.flush();

	if (buf == "load"){                                                                                //Verificaçao e implementação do comando LOAD  **EM PROGRESSO**
		string buf_load;
		
		for (int i = 0; i < 2; i++){
			s_temp >> buf_load;
			argumentos.push_back(buf_load);
		}

		cout << "A carregar o ficheiro de configuracao " << argumentos[1] << "..." << endl;

		com_int = 1;
		argumentos.clear();
		fflush(stdin);
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