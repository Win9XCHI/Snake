#pragma once
#include <random>

struct PRNG
{
	std::mt19937 engine;
};

//Mersenne Vortex Algorithm
class Random {
	PRNG generator;

public:
	Random();
	~Random();

	/* Init generator
	 * Input: -
	 * Output: -	 */
	void initGenerator();

	/* Generate random number
	 * Input: min and max diapason
	 * Output: random numbers	 */
	unsigned int random(unsigned minValue, unsigned maxValue);
};

