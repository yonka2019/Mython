#include "Parser.h"
#include <iostream>


Type* Parser::parseString(std::string str)
{
	if (str[0] == ' ' || str[0] == '\t')
		throw new IndentationException();

	if (str.length() > 0)
	{
		std::cout << str << std::endl;
	}

	return nullptr;
}


