#include "Type.h"

bool Type::getIsTemp() const
{
	return this->_isTemp;
}

void Type::setIsTemp(const bool flag)
{
	this->_isTemp = flag;
}
