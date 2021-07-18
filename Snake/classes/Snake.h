#pragma once
#include <list>
#include "GObject.h"
#include "item.h"

class Snake : GObject {
	std::list<item> body;
	item head;
	unsigned int length;
	unsigned int vector;

	void Move(bool delTail);
	void OnLeft();
	void OnTop();
	void OnRight();
	void OnBottom();

public:
	Snake();
	~Snake();
	void Set(HDC &hDC) override;
	bool Collision(point object) override;
	void SetVector(unsigned int direction);
	point Move();
	point Add();
};

