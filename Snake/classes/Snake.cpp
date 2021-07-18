#include "Snake.h"

Snake::Snake() : length(1), vector(0) {
	head.head.x = CONSTANTS::DEFAULT_X;
	head.head.y = CONSTANTS::DEFAULT_Y;
	head.tail.x = CONSTANTS::DEFAULT_X + CONSTANTS::LENGTH_ITEM;
	head.tail.y = CONSTANTS::DEFAULT_Y;
	body.push_front(head);
}

Snake::~Snake() {

}

/* Set figure on scene
 * Input: context for consol`s descriptor
 * Output: -	 */
void Snake::Set(HDC& hDC) {

	for (auto &i : body) {
		MoveToEx(hDC, i.head.x, i.head.y, NULL);	//Set start coordinates
		LineTo(hDC, i.tail.x, i.tail.y);			//Set line
	}
}

/* Check collision for figure
 * Input: object point
 * Output: point belongs to figure or not	 */
bool Snake::Collision(point object) {
	int oneX, twoX, oneY, twoY, i(0);

	for (auto &item : body) {					//loop for fragments

		if (i != 0) {							//exclude head
			//Filling variables depending on orientation of fragments
			if (item.head.x > item.tail.x) {	//x
				oneX = item.head.x;
				twoX = item.tail.x;
			}
			else {
				twoX = item.head.x;
				oneX = item.tail.x;
			}

			if (item.head.y > item.tail.y) {	//y
				oneY = item.head.y;
				twoY = item.tail.y;
			}
			else {
				twoY = item.head.y;
				oneY = item.tail.y;
			}

			if (object.x >= oneX && object.x <= twoX && object.y >= oneY && object.y <= twoY) {
				return true;
			}
		}
		i++;
	}

	return false;
}

/* Set new direction of movement
 * Input: direction (0 - left, 1 - top, 2 - right, 3 - bottom)
 * Output: -	 */
void Snake::SetVector(unsigned int direction) {

	if (direction > 3 || direction == vector || (direction == 0 && vector == 2) || (direction == 2 && vector == 0) || (direction == 1 && vector == 3) || (direction == 3 && vector == 1)) {
		return;
	}

	vector = direction;
}

/* Driving sides
 * Input: -
 * Output: -	 */
void Snake::OnLeft() {
	head.head.x -= CONSTANTS::LENGTH_ITEM;
	head.head.y = head.tail.y;
}

void Snake::OnTop() {
	head.head.y -= CONSTANTS::LENGTH_ITEM;
	head.head.x = head.tail.x;
}

void Snake::OnRight() {
	head.head.x += CONSTANTS::LENGTH_ITEM;
	head.head.y = head.tail.y;
}

void Snake::OnBottom() {
	head.head.y += CONSTANTS::LENGTH_ITEM;
	head.head.x = head.tail.x;
}

/* Move snake
 * Input: delete tail item or not
 * Output: -	 */
void Snake::Move(bool delTail) {
	head.reverse();

	switch (vector) {
	case 0: {
		OnLeft();
		break;
	}
	case 1: {
		OnTop();
		break;
	}
	case 2: {
		OnRight();
		break;
	}
	case 3: {
		OnBottom();
		break;
	}
	}

	body.push_front(head);

	if (delTail) {
		body.pop_back();
	}
}

/* Move snake
 * Input: -
 * Output: point of head	 */
point Snake::Move() {
	Move(true);
	return head.head;
}

/* Add item for snake`s body
 * Input: -
 * Output: point of head	 */
point Snake::Add() {
	Move(false);
	length++;
	return head.head;
}