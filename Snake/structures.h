#pragma once
#include <initializer_list>

struct point {
	int x;
	int y;

	point() : x(0), y(0) {

	}

	point(std::initializer_list<int> list) {
		x = 0;
		y = 0;

		if (list.size() == 2) {
			x = *list.begin();
			y = *list.end();
		}
	}

	point(point &other) {
		x = other.x;
		y = other.y;
	}

	point(int xx, int yy) : x(xx), y(yy) {

	}
};