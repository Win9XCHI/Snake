#pragma once
#include <list>
#include "GObject.h"
#include "item.h"

//Graphic figure for snake
class Snake : GObject {
	std::list<item> body;	//array snake`s items
	item head;				//head item
	unsigned int length;	//length of snake
	unsigned int vector;	//direction of movement

	/* Move snake
	 * Input: delete tail item or not
	 * Output: -	 */
	void Move(bool delTail);

	/* Driving sides
	 * Input: -
	 * Output: -	 */
	void OnLeft();
	void OnTop();
	void OnRight();
	void OnBottom();

public:
	Snake();
	~Snake();

	/* Set figure on scene
	 * Input: context for consol`s descriptor
	 * Output: -	 */
	void Set(HDC &hDC) override;

	/* Check collision for figure
	 * Input: object point
	 * Output: point belongs to figure or not	 */
	bool Collision(point object) override;

	/* Set new direction of movement
	 * Input: direction (0 - left, 1 - top, 2 - right, 3 - bottom)
	 * Output: -	 */
	void SetVector(unsigned int direction);

	/* Move snake
	 * Input: -
	 * Output: point of head	 */
	point Move();

	/* Add item for snake`s body
	 * Input: -
	 * Output: point of head	 */
	point Add();

	/* Get coordinates sneke`s head
	 * Input: -
	 * Output: coordinates	 */
	point GetHead();

	/* Get vector
	 * Input: -
	 * Output: vector(0 - left, 1 - top, 2 - right, 3 - bottom)	 */
	unsigned int GetVector();
};

