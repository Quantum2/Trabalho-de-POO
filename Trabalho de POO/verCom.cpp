#include "verCom.h"

using namespace std;

void resetEcra(){
	Mapa map(largura, altura);
	Sidebar sidy(map.getTamY());

	reimp(map, sidy);
}

int verificarComandoJogo(){
	string comando, buf;
	Consola con;
	int com_int = 0;
	int args = 0;
	int jogo_decorrer = 0;

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
		case 3:
			ss >> buf;
			bocados1.push_back(buf);
			break;
		case 4:
			ss >> buf;
			bocados1.push_back(buf);
			break;
		default:
			break;
		}
	}

	if (bocados1[0] == "load"){                                   //Verificaçao e implementação do comando LOAD  **EM PROGRESSO**
		ifstream ficheiro;
		string temp;
		vector<string> comandos_fich;
		int linha = 0;

		cout << "A carregar o ficheiro de configuracao " << bocados1[1] << "..." << endl;

		ficheiro.open(bocados1[1]);

		while (!ficheiro.eof()){
			getline(ficheiro, temp);
			comandos_fich.push_back(temp);
			verificarComandoJogo(comandos_fich, linha);
			linha++;
		}

		com_int = 1;
		ficheiro.close();
		verificarComandoJogo();
	}

	if (bocados1[0] == "mkgame")
	{
		criarCampo(stoi(bocados1[1]), stoi(bocados1[2]));
		largura = stoi(bocados1[1]);
		altura = stoi(bocados1[2]);
		verificarComandoJogo();
	}

	if (bocados1[0] == "pop")
	{
		Popul temp(bocados1[1]);

		Pops_func(temp);

		resetEcra();
		verificarComandoJogo();
	}

	if (bocados1[0] == "sete")
	{
		criarUnidades(bocados1[2],bocados1[1], stoi(bocados1[3]), stoi(bocados1[4]));
	}

	if (com_int == 0){
		cout << "Comando nao encontrado !" << endl;
		getchar();
		resetEcra();
		verificarComandoJogo();
	}

	return 0;
}

int verificarComandoJogo(vector<string> vec, int linha){
	string comando, buf;
	Consola con;
	int com_int = 0;
	int args = 0;

	con.setTextColor(8);
	vector<string> bocados1;

	comando = bocados1[linha];

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

	if (bocados1[0] == "load"){                                 //Verificaçao e implementação do comando LOAD  **EM PROGRESSO**
		ifstream ficheiro;
		string temp;
		vector<string> comandos_fich;
		int linha = 0;

		cout << "A carregar o ficheiro de configuracao " << bocados1[1] << "..." << endl;

		ficheiro.open(bocados1[1]);

		while (!ficheiro.eof()){
			getline(ficheiro, temp);
			comandos_fich.push_back(temp);
			verificarComandoJogo(comandos_fich, linha);
			linha++;
		}

		com_int = 1;
		ficheiro.close();
		verificarComandoJogo();
	}

	if (bocados1[0] == "mkgame")
	{
		criarCampo(stoi(bocados1[1]), stoi(bocados1[2]));
	}

	if (bocados1[0] == "")

		if (com_int == 0){
			cout << "Comando nao encontrado !" << endl;
			getchar();
			resetEcra();
			verificarComandoJogo();
		}

	return 0;
}