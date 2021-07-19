#pragma once
#include <stdexcept>

//Exception for event or thread
class KernelObjectException : public std::exception {
private:
    std::string m_error;

public:
    KernelObjectException(std::string error) : m_error(error) {	}

    const char* what() const noexcept { return m_error.c_str(); }
};
