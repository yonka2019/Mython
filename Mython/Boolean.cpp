#include "Boolean.h"

Boolean::Boolean(const bool value) : Type()
{
	this->_value = value;
}

bool Boolean::isPrintable() const
{
	return true;
}

std::string Boolean::toString() const
{
	if (this->_value)
	{
		return "True";
	}
	else
	{
		return "False";
	}
}
