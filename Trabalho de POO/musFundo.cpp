#include <Windows.h>
#include <mmsystem.h>

#pragma comment(lib, "winmm.lib")

#include "musFundo.h"

void musFundo(int controlador){
	switch (controlador)
	{
	case 1:
		PlaySound(TEXT("song_menu.wav"), NULL, SND_FILENAME | SND_ASYNC);
		break;
	case 2:
		PlaySound(NULL, 0, 0);
		break;
	default:
		break;
	}
}