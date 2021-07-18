#pragma once
#include <windows.h>
#include "../structures.h"
#define SIZE 5

class Fruit {
	point place;

public:
	Fruit();
	Fruit(int x, int y);
	~Fruit();
	void Set(HDC &hDC);
	bool Collision(point object);
};

