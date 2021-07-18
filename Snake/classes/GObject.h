#pragma once
#include <windows.h>
#include "../structures.h"

class GObject {
protected:
	point place;

public:
	GObject();
	GObject(int x, int y);
	~GObject();
	virtual void Set(HDC &hDC) = 0;
	virtual bool Collision(point object) = 0;
};

