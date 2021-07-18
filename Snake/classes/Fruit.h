#pragma once
#include "GObject.h"
#define SIZE 5

class Fruit : GObject {

public:
	Fruit();
	Fruit(int x, int y);
	~Fruit();
	void Set(HDC &hDC) override;
	bool Collision(point object) override;
};

