#ifndef GAME_H
#define GAME_H

#include "Core/engine.h"

using namespace WillEngine;

class Game : public Engine
{
public:
	Game();
	~Game();

	void userInitialization();

	void userInput();
	
	void userUpdate();
	
	void userDraw();
	
	void userDeinitialization();
};

#endif