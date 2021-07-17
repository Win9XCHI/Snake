#pragma once
#include <windows.h>
#include "../structures.h"
#define MIN 10
#define MAX 1100

class GameWindow {
	point window[4];

public:
	GameWindow();
	~GameWindow();
	void SetWindow(HDC &hDC);
	bool Collision(point object);
};

