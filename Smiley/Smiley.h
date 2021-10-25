#pragma once

#include "SmileyApp.h"
#include "SmileyUtils.h"

// '\' used for multiline code 
#define START_SMILEY_GAME(classname) \
int main()\
{\
	classname _smiley_game;\
	_smiley_game.Run();\
}