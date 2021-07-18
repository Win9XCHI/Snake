#pragma once
#include <string>
#include <vector>
#include <ctime>
#include <conio.h>
#include <iostream>
#include "Random.h"
#include "GameWindow.h"
#include "Fruit.h"
#include "Snake.h"
#include "Result.h"

class Game {
	unsigned int count;
	HWND hWnd;
	HDC hDC;
	DWORD thread_id;
	HANDLE hThread, hEvent;

	void NewFruit(std::vector<Fruit> &fruits);
	void InitThread();
	void InitEvent();
	void InitConsole();

public:
	Game();
	~Game();
	unsigned int StartGame(std::string name);
};

