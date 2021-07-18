#pragma once
#include "GObject.h"
#define MIN 20
#define MAX 510

class GameWindow : GObject {
	point window[4];

public:
	GameWindow();
	~GameWindow();
	void Set(HDC &hDC) override;
	bool Collision(point object) override;
};

