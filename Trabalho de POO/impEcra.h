#ifndef IMP_ECRA
#define IMP_ECRA

#define LINHAS 35
#define COLUNAS 80
#define TAM_X 7
#define TAM_Y 10

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <Windows.h>
#include <time.h>
#include "Consola.h"

using namespace std;

void imprimirMenu();

void imprimirOpcoes(string dificuldade, string def_jogo);

#endif