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
			y = *(list.begin() + 1);
		}
	}

	point(const point &other) {
		x = other.x;
		y = other.y;
	}

	point(int xx, int yy) : x(xx), y(yy) {

	}

	point& operator=(const point& other) {
		x = other.x;
		y = other.y;
		return *this;
	}
};

struct item {
	point head;
	point tail;

	item() {

	}

	item(const item& other) {
		head = other.head;
		tail = other.tail;
	}

	void reverse() {
		point buff = head;
		head = tail;
		tail = buff;
	}

	item& operator=(const item& other) {
		head = other.head;
		tail = other.tail;
		return *this;
	}
};