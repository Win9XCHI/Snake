#include "Result.h"

Result::Result() {

}

Result::~Result() {

}

void Result::Add(std::string name, unsigned int count) {
	results.insert({name, count});
}

std::string Result::CreateString(std::string name, unsigned int count) {
	return name + ":" + std::to_string(count) + "\n";
}

std::string Result::GetResults(std::string name) {
	std::string str = "";

	for (const auto& item : results) {
		if (item.first == name) {
			str += CreateString(item.first, item.second);
		}
	}

	return str;
}

std::string Result::GetResults() {
	std::string str = "";

	for (const auto& item : results) {
		str += CreateString(item.first, item.second);
	}

	return str;
}
