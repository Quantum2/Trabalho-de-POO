#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <sstream>
#include <Windows.h>
#include "verCom.h"
#include "Consola.h"
#include "musFundo.h"
#include "impEcra.h"
#include "iniciarJogo.h"

using namespace std;

int main(int argc, char **argv){
	Consola con;
	string dif = "Normal";
	string defs = "Originais";

	con.setScreenSize(LINHAS, COLUNAS);

	imprimirMenu();

	imprimirOpcoes(dif, defs);

	musFundo(1);

	verificarComando();

	return 0;

	}