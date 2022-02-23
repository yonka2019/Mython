#include "Integer.h"

Integer::Integer(const int value) : Type()
{
	this->_value = value;
}

bool Integer::isPrintable() const
{
	return true;
}

std::string Integer::toString() const
{
	return std::to_string(this->_value);
}