#pragma once
#include "GObject.h"

class Fruit : GObject {

public:
	Fruit();
	Fruit(int x, int y);
	~Fruit();
	void Set(HDC &hDC) override;
	bool Collision(point object) override;
};

