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
#include "iniciarJogo.h"

#define LINHAS 35
#define COLUNAS 80

using namespace std;

int main(int argc, char **argv){

	musFundo(1);

	criarCampo(LINHAS, COLUNAS);

	verificarComandoJogo();

	return 0;

	}