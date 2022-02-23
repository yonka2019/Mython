#include "String.h"

String::String(const std::string value) : Sequence()
{
	this->_value = value;
}

bool String::isPrintable() const
{
	return true;
}

std::string String::toString() const
{
	if (this->_value.find("'") != std::string::npos)
	{
		return '"' + _value + '"';
	}
	return "'" + _value + "'";

}
