#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <sstream>
#include <map>
#include "verCom.h"
#include "Consola.h"
#include "musFundo.h"

using namespace std;

enum string_comandos {
	stop_music, mkgame, play_music, pop
};

map <string, string_comandos> comandos;

void registar_comandos(){
	comandos["stopmusic"] = stop_music;
	comandos["playmusic"] = play_music;
	comandos["mkgame"] = mkgame;
	comandos["pop"] = pop;
}

int verificarComando(){
	string comando, temp, buf;;
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

	cout << "O comando inserido foi : " << comando << endl;  //Eliminar este comando futuramente, funcao de debug apenas para verificar separaçao de string

	switch (comandos[bocados1[0]])
	{
	case stop_music:
		musFundo(2);
		break;
	case play_music:
		musFundo(1);
		break;
	default:
		cout << "Comando desconhecido";
		getchar();
		return 1;
		break;
	}
}