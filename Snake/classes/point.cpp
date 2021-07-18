#include "point.h"

point::point() : x(0), y(0) {

}

point::point(std::initializer_list<int> list) {
	x = 0;
	y = 0;

	if (list.size() == 2) {
		x = *list.begin();
		y = *(list.begin() + 1);
	}
}

point::point(const point& other) {
	x = other.x;
	y = other.y;
}

point::point(int xx, int yy) : x(xx), y(yy) {

}

point::~point() {

}

point& point::operator=(const point& other) {
	x = other.x;
	y = other.y;
	return *this;
}