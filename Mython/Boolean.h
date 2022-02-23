#pragma once
#include "Type.h"

class Boolean : public Type
{
public:
	Boolean(const bool value);
	bool isPrintable() const;
	std::string toString() const;

private:
	bool _value;
};