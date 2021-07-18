#pragma once
#include <initializer_list>

class point {

public:
	int x;
	int y;

	point();
	point(std::initializer_list<int> list);
	point(const point& other);
	point(int xx, int yy);
	~point();
	point& operator=(const point& other);
};

