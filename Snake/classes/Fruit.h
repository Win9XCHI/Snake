#pragma once
#include "GObject.h"

class Fruit : GObject {

public:
	Fruit();
	Fruit(int x, int y);
	~Fruit();

	/* Set figure on scene
	 * Input: context for consol`s descriptor
	 * Output: -	 */
	void Set(HDC &hDC) override;

	/* Check collision for figure
	 * Input: object point
	 * Output: point belongs to figure or not	 */
	bool Collision(point object) override;
};

