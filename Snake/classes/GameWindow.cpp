#include "GameWindow.h"

GameWindow::GameWindow() {
	window[0].x = CONSTANTS::MIN_SIZE;
	window[0].y = CONSTANTS::MIN_SIZE;

	window[1].x = CONSTANTS::MAX_SIZE;
	window[1].y = CONSTANTS::MIN_SIZE;

	window[2].x = CONSTANTS::MAX_SIZE;
	window[2].y = CONSTANTS::MAX_SIZE;

	window[3].x = CONSTANTS::MIN_SIZE;
	window[3].y = CONSTANTS::MAX_SIZE;
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

	if (object.x <= CONSTANTS::MIN_SIZE || object.x >= CONSTANTS::MAX_SIZE || object.y <= CONSTANTS::MIN_SIZE || object.y >= CONSTANTS::MAX_SIZE) {
		return true;
	}

	return false;
}