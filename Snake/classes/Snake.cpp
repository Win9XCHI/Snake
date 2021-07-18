#include "Snake.h"

Snake::Snake() : length(1), vector(0)/*, width(5), thickness(5)*/ {
	head.head.x = DEFAULT_X;
	head.head.y = DEFAULT_Y;
	head.tail.x = DEFAULT_X + LENGTH_ITEM;
	head.tail.y = DEFAULT_Y;
	body.push_front(head);
}

Snake::~Snake() {

}

void Snake::Set(HDC& hDC) {

	for (auto i : body) {
		MoveToEx(hDC, i.head.x, i.head.y, NULL); //Set point
		LineTo(hDC, i.tail.x, i.tail.y);	//Set line
	}
}

bool Snake::Collision(point object) {
	int oneX, twoX, oneY, twoY, i(0);

	for (auto item : body) {

		if (i != 0) {
			if (item.head.x > item.tail.x) {
				oneX = item.head.x;
				twoX = item.tail.x;
			}
			else {
				twoX = item.head.x;
				oneX = item.tail.x;
			}

			if (item.head.y > item.tail.y) {
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

void Snake::SetVector(unsigned int direction) {

	if (direction > 3 || direction == vector || (direction == 0 && vector == 2) || (direction == 2 && vector == 0) || (direction == 1 && vector == 3) || (direction == 3 && vector == 1)) {
		return;
	}

	vector = direction;
}

void Snake::OnLeft() {
	head.head.x -= LENGTH_ITEM;
	head.head.y = head.tail.y;
}

void Snake::OnTop() {
	head.head.y -= LENGTH_ITEM;
	head.head.x = head.tail.x;
}

void Snake::OnRight() {
	head.head.x += LENGTH_ITEM;
	head.head.y = head.tail.y;
}

void Snake::OnBottom() {
	head.head.y += LENGTH_ITEM;
	head.head.x = head.tail.x;
}


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

point Snake::Move() {
	Move(true);
	return head.head;
}

point Snake::Add() {
	Move(false);
	length++;
	return head.head;
}