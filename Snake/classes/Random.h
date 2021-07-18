#pragma once
#include <random>

struct PRNG
{
	std::mt19937 engine;
};

class Random {
	PRNG generator;

public:
	Random();
	~Random();
	void initGenerator();
	unsigned int random(unsigned minValue, unsigned maxValue);
};

