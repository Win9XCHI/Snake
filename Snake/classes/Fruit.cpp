#include "Fruit.h"

Fruit::Fruit() {

}

Fruit::Fruit(int x, int y) : GObject(x, y) {
}

Fruit::~Fruit() {

}

void Fruit::Set(HDC& hDC) {
	RECT r; //coordinates of rectangle
	r.left = place.x;
	r.top = place.y;
	r.right = place.x + SIZE;
	r.bottom = place.y + SIZE;
	FillRect(hDC, &r, (HBRUSH)CreateSolidBrush(RGB(255, 0, 0)));
}

bool Fruit::Collision(point object) {

	if (object.x >= place.x && object.x <= place.x + SIZE && object.y >= place.y && object.y <= place.y + SIZE) {
		return true;
	}

	return false;
}