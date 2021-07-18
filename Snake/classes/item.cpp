#include "item.h"

item::item() {

}

item::item(const item& other) {
	head = other.head;
	tail = other.tail;
}

item::~item() {

}

void item::reverse() {
	point buff = head;
	head = tail;
	tail = buff;
}

item& item::operator=(const item& other) {
	head = other.head;
	tail = other.tail;
	return *this;
}