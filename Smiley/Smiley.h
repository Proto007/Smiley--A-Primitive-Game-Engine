#pragma once

#include "SmileyApp.h"
#include "SmileyUtils.h"
#include "GameWindow.h"
#include "Sprite.h"
#include "Shader.h"
#include "Renderer.h"
// '\' used for multiline code 
#define START_SMILEY_GAME(classname) \
int main()\
{\
	classname _smiley_game;\
	_smiley_game.Run();\
}