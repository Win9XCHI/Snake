#include "Fruit.h"

Fruit::Fruit() {

}

Fruit::Fruit(int x, int y) : GObject(x, y) {
}

Fruit::~Fruit() {

}

/* Set figure on scene
 * Input: context for consol`s descriptor
 * Output: -	 */
void Fruit::Set(HDC& hDC) {
	RECT r;															//coordinates of rectangle
	r.left = place.x;
	r.top = place.y;
	r.right = place.x + CONSTANTS::SIZE_FRUIT;
	r.bottom = place.y + CONSTANTS::SIZE_FRUIT;
	FillRect(hDC, &r, (HBRUSH)CreateSolidBrush(CONSTANTS::RED));	//Set red rectangle
}

/* Check collision for figure
 * Input: object point
 * Output: point belongs to figure or not	 */
bool Fruit::Collision(point object) {

	if (object.x >= place.x && object.x <= place.x + CONSTANTS::SIZE_FRUIT && object.y >= place.y && object.y <= place.y + CONSTANTS::SIZE_FRUIT) {
		return true;
	}

	return false;
}

/* Get point
 * Input: -
 * Output: point	 */
point Fruit::GetPlace() {
	return place;
}