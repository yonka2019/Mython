#pragma once
#include "Type.h"

class Integer : public Type
{
public:
	Integer(const int value);
	bool isPrintable() const;
	std::string toString() const;

private:
	int _value;


};