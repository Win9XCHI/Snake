#pragma once
#include "GObject.h"

class GameWindow : GObject {
	point window[4];

public:
	GameWindow();
	~GameWindow();
	void Set(HDC &hDC) override;
	bool Collision(point object) override;
};

