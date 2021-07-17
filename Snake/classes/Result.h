#pragma once
#include <map>
#include <string>

class Result {
	std::multimap<std::string, unsigned int> results;

	std::string CreateString(std::string name, unsigned int count);

public:
	Result();
	~Result();
	void Add(std::string name, unsigned int count);
	std::string GetResults();
	std::string GetResults(std::string name);
};

