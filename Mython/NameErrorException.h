#pragma once
#include "InterpreterException.h"
#include <string>

class NameErrorException : public InterpreterException
{
private:
	std::string _name;
public:
	virtual const char* what() const noexcept;
};