#pragma once
#include <windows.h>
#include "../structures.h"

class Fruit {
	point place;

public:
	Fruit();
	Fruit(int x, int y);
	~Fruit();
	void SetFruit(HDC &hDC);
	bool Collision(point object);
};

