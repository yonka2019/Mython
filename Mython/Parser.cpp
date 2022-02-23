#include "Parser.h"
#include <iostream>


Type* Parser::parseString(std::string str)
{
	if (str[0] == ' ' || str[0] == '\t')
		throw new IndentationException();

	if (str.length() > 0)
	{
		Helper::rtrim(str);
		Type* var = getType(str);
		if (var != nullptr)
		{
			return var;
		}

	}

	return nullptr;
}

Type* Parser::getType(std::string& str)
{
	Type* type = nullptr;
	Helper::trim(str); // remove whitespaces
	if (Helper::isInteger(str)) // string
	{
		Helper::removeLeadingZeros(str);

		type = new Integer(std::stoi(str));
		type->setIsTemp(true);

	}
	else if (Helper::isBoolean(str))
	{
		type = new Boolean(str == "True");
		type->setIsTemp(true);
		
	}
	else if (Helper::isString(str))
	{
		type = new String(str.substr(1, str.length() - 2));
		type->setIsTemp(true);
	}
	else
	{
		return nullptr;
	}
}


