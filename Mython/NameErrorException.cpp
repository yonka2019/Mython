#include "NameErrorException.h"
std::string finalString;
const char* NameErrorException::what() const noexcept
{
	finalString =  "NameError: name '" + this->_name + "' is not defined";
	return finalString.c_str();
}
