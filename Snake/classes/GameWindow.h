#pragma once
#include <windows.h>
#include "../structures.h"
#define MIN 20
#define MAX 510

class GameWindow {
	point window[4];

public:
	GameWindow();
	~GameWindow();
	void Set(HDC &hDC);
	bool Collision(point object);
};

