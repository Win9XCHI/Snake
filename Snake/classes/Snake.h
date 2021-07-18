#pragma once
#include <windows.h>
#include <list>
#include "../structures.h"
#define DEFAULT_X 400
#define DEFAULT_Y 250
#define LENGTH_ITEM 5

class Snake {
	std::list<item> body;
	item head;
	unsigned int length;
	unsigned int vector;
	//const int width;
	//const int thickness;

	void Move(bool delTail);
	void OnLeft();
	void OnTop();
	void OnRight();
	void OnBottom();

public:
	Snake();
	~Snake();
	void Set(HDC &hDC);
	bool Collision(point object);
	void SetVector(unsigned int direction);
	point Move();
	point Add();
};

