#ifndef VER_COM
#define VER_COM

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <fstream>
#include <vector>
#include "Consola.h"
#include "musFundo.h"
#include "iniciarJogo.h"
#include "Unidades.h"
#include "Util.h"

using namespace std;

void resetEcra();

int verificarComandoJogo(vector<string> vec, int linha);

int verificarComandoJogo();

#endif