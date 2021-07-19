#pragma once
#include <stdexcept>

//Exception for game process
class GameProcessException : public std::exception {
private:
    std::string m_error;

public:
    GameProcessException(std::string error) : m_error(error) {	}

    const char* what() const noexcept { return m_error.c_str(); }
};
