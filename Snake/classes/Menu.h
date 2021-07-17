#pragma once
#include <iostream>
#include "Result.h"
#include "Game.h"

class Menu {
	Result object_result;

public:
	Menu();
	~Menu();
	void MainMenu();
	void StartMenu();
	void ShowResult();
};

