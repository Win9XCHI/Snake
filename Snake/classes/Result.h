#pragma once
#include <map>
#include <string>

//Class for hold user result
class Result {
	std::multimap<std::string, unsigned int> results; //user results (name, count)

	/* Create string for output
	 * Input: name and count
	 * Output: string for output	 */
	std::string CreateString(std::string name, unsigned int count);

public:
	Result();
	~Result();

	/* Add result
	 * Input: name and count
	 * Output: -	 */
	void Add(std::string name, unsigned int count);

	/* Get all results
	 * Input: -
	 * Output: string for output	 */
	std::string GetResults();

	/* Get specific user results
	 * Input: name
	 * Output: string for output	 */
	std::string GetResults(std::string name);
};

