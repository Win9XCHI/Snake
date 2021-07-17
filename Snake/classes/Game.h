#pragma once
#include <string>
#include "GameWindow.h"
#include <conio.h>
#include "Result.h"

class Game {
	unsigned int count;

public:
	Game();
	~Game();
	unsigned int StartGame(std::string name);
};

