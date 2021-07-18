#pragma once
#include <string>
#include <vector>
#include <ctime>
#include <conio.h>
#include <iostream>
#include "Random.h"
#include "GameWindow.h"
#include "Fruit.h"
#include "Snake.h"
#include "../exceptions/GameProcess_exceptions.h"
#include "../exceptions/KernelObject_exceptions.h"

//class for game logic
class Game {
	unsigned int count;
	HWND hWnd;				//descriptor consol window
	HDC hDC;				//context for descriptor
	DWORD thread_id;
	HANDLE hThread, hEvent;

	/* Set random coordinates for fruit on scene
	 * Input: array of fruit
	 * Output: array of fruit with coordinates	 */
	void NewFruit(std::vector<Fruit> &fruits);

	/* Init kernel objects
	 * Input: -
	 * Output: -	 */
	void InitThread();
	void InitEvent();
	void InitConsole();

	/* Event handler
	 * Input: key, snake
	 * Output: modified	snake */
	void Events(WPARAM param, Snake &object_snake);

	/* Loop with game logic
	 * Input: -
	 * Output: - */
	void GameProcess();

	/* Collision handler
	 * Input: snake, window, fruits
	 * Output: modified snake, modified window, modified fruits */
	void CollisionHandling(Snake &object_snake, GameWindow &object_window, std::vector<Fruit> &fruits);

	/* Draw graphics
	 * Input: snake, window, fruits
	 * Output: modified snake, modified window, modified fruits */
	void Draw(Snake& object_snake, GameWindow& object_window, std::vector<Fruit>& fruits);

public:
	Game();
	~Game();

	/* Start game
	 * Input: user`s name
	 * Output: count */
	unsigned int StartGame(std::string name);
};

