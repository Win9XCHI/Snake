#include "Fruit.h"

Fruit::Fruit() {

}

Fruit::Fruit(int x, int y) : place({x, y}) {

}

Fruit::~Fruit() {

}

void Fruit::SetFruit(HDC& hDC) {
	Rectangle(hDC, place.x, place.y, place.x + 5, place.y + 5);
}

bool Fruit::Collision(point object) {

	

	return false;
}