#include <Windows.h>
#include <mmsystem.h>

#pragma comment(lib, "winmm.lib")

#include "musFundo.h"

void musFundo(int controlador){
	
	if (controlador == 1){
		PlaySound(TEXT("song_menu.wav"), NULL, SND_FILENAME | SND_ASYNC);
		waveOutSetVolume(NULL, 0xFFFF);
	}
	if (controlador == 2){
		waveOutSetVolume(NULL, 0x0000);
	}
	if (controlador == 3){
		waveOutSetVolume(NULL, 0xFFFF);
	}
}