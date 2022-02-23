#pragma once
#include <string>


class Type
{
public:
	virtual bool isPrintable() const = 0;
	virtual std::string toString() const = 0;
	bool getIsTemp() const;
	void setIsTemp(const bool flag);

protected:
	bool _isTemp = false;
};