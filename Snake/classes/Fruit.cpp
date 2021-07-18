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
	r.right = place.x + CONSTANTS::SIZE_FRUIT;
	r.bottom = place.y + CONSTANTS::SIZE_FRUIT;
	FillRect(hDC, &r, (HBRUSH)CreateSolidBrush(CONSTANTS::RED));
}

bool Fruit::Collision(point object) {

	if (object.x >= place.x && object.x <= place.x + CONSTANTS::SIZE_FRUIT && object.y >= place.y && object.y <= place.y + CONSTANTS::SIZE_FRUIT) {
		return true;
	}

	return false;
}