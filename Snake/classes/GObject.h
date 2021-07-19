#pragma once
#include "point.h"
#include "../constants.h"

//Abstract graphic figure
class GObject {
protected:
	point place;	//default point for staging

public:
	GObject();
	GObject(int x, int y);
	~GObject();

	/* Set figure on scene
	 * Input: context for consol`s descriptor
	 * Output: -	 */
	virtual void Set(HDC &hDC) = 0;

	/* Check collision for figure
	 * Input: object point
	 * Output: point belongs to figure or not	 */
	virtual bool Collision(point object) = 0;
};

