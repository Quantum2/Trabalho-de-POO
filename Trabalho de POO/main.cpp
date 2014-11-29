#pragma once

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

using namespace std;

int main(int argc, char **argv){

	//musFundo(1);                Desactivado por enquanto

	criarCampo(LINHAS, COLUNAS);

	verificarComandoJogo();

	return 0;
	}