#pragma once
#include "Result.h"
#include "Game.h"

class Menu {
	Result object_result;	//hold user result

public:
	Menu();
	~Menu();

	/* Main menu
	 * Input: -
	 * Output: -	 */
	void MainMenu();

	/* Game
	 * Input: -
	 * Output: -	 */
	void StartMenu();

	/* Show result
	 * Input: -
	 * Output: -	 */
	void ShowResult();

	/* Show demo game
	 * Input: -
	 * Output: -	 */
	void ShowDemo();
};

