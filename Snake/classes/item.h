#pragma once
#include "point.h"

//line
class item {

public:
	point head;	//coordinate head
	point tail; //coordinate tail

	item();
	item(const item& other);
	~item();
	item& operator=(const item& other);

	/* Swap head and tail
	 * Input: -
	 * Output: -	 */
	void reverse();
};

