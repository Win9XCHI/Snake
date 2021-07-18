#include "GameWindow.h"

GameWindow::GameWindow() {
	window[0].x = MIN;
	window[0].y = MIN;

	window[1].x = MAX;
	window[1].y = MIN;

	window[2].x = MAX;
	window[2].y = MAX;

	window[3].x = MIN;
	window[3].y = MAX;
}

GameWindow::~GameWindow() {

}

void GameWindow::Set(HDC& hDC) {
	for (unsigned int i = 0; i < 4; i++) {
		MoveToEx(hDC, window[i].x, window[i].y, NULL); //Set point

		if (i != 3) {
			LineTo(hDC, window[i + 1].x, window[i + 1].y);	//Set line
		}
		else {
			LineTo(hDC, window[0].x, window[0].y);		//Set line
		}
	}
}

bool GameWindow::Collision(point object) {

	if (object.x <= MIN || object.x >= MAX || object.y <= MIN || object.y >= MAX) {
		return true;
	}

	return false;
}