#pragma once
#include "point.h"

class item {

public:
	point head;
	point tail;

	item();
	item(const item& other);
	~item();
	void reverse();
	item& operator=(const item& other);
};

