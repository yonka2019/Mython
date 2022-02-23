#pragma once
#include "Sequence.h"
#include <string>

class String : public Sequence
{
public:
	String(const std::string value);
	bool isPrintable() const;
	std::string toString() const;

private:
	std::string _value;
};