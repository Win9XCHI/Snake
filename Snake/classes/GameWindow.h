#pragma once
#include "GObject.h"

class GameWindow : GObject {
	point window[4];	//border coordinates

public:
	GameWindow();
	~GameWindow();

	/* Set figure on scene
	 * Input: context for consol`s descriptor
	 * Output: -	 */
	void Set(HDC &hDC) override;

	/* Check collision for figure
	 * Input: object point
	 * Output: point belongs to figure or not	 */
	bool Collision(point object) override;
};

