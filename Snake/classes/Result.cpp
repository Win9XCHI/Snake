#include "Result.h"

Result::Result() {

}

Result::~Result() {

}

/* Add result
 * Input: name and count
 * Output: -	 */
void Result::Add(std::string name, unsigned int count) {
	results.insert({name, count});
}

/* Create string for output
 * Input: name and count
 * Output: string for output	 */
std::string Result::CreateString(std::string name, unsigned int count) {
	return name + ":" + std::to_string(count) + "\n";
}

/* Get specific user results
 * Input: name
 * Output: string for output	 */
std::string Result::GetResults(std::string name) {
	std::string str = "";

	for (const auto& item : results) {
		if (item.first == name) {
			str += CreateString(item.first, item.second);
		}
	}

	return str;
}

/* Get all results
 * Input: -
 * Output: string for output	 */
std::string Result::GetResults() {
	std::string str = "";

	for (const auto& item : results) {
		str += CreateString(item.first, item.second);
	}

	return str;
}
