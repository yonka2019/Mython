#include "Parser.h"
#include <unordered_map>


Type* Parser::parseString(std::string str)
{
	if (str[0] == ' ' || str[0] == '\t')
		throw new IndentationException();

	if (str.length() > 0)
	{
		Helper::rtrim(str);
		if (getVariableValue(str) == nullptr)
		{
			Type* var = getType(str);
			if (var != nullptr)
			{
				return var;
			}
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
	return type;
}
bool Parser::isLegalVarName(std::string str)
{
	if (!Helper::isDigit(str[0]))
	{
		for (char const& c : str)
		{
			if (!Helper::isLetter(c) || !Helper::isUnderscore(c))
			{
				return false;
			}
		}
		return true; // not false'd yet =p
	}
	else
	{
		return false;
	}
}

bool Parser::makeAssignment(std::string str)
{

	if (std::count(str.begin(), str.end(), '=') == NUMBER_OF_EQUALS)
	{
		std::regex r("^(.*) = (.*)$");
		std::smatch matches;
		std::regex_search(str, matches, r);
		std::string name = matches.str(1);
		std::string value = matches.str(2);
		/*
		* foo = bar
		* matches.str(1) = foo
		* matches.str(2) = bar
		*/
		Helper::rtrim(name);
		Helper::trim(value);
		if (!isLegalVarName(name)) // check variable name
		{
			throw new SyntaxException();
		}

		Type* type = getType(value);
		if (type == nullptr) // check variable value
		{
			throw new SyntaxException();
		}
		_variables.insert({ name, type });
		return true;
	}
	else
	{
		return false;
	}
}

Type* Parser::getVariableValue(std::string str)
{
	for (auto& it : _variables) 
	{
		if (it.first == str)
		{
			return it.second;
		}
	}
	return nullptr;
}

void Parser::deleteAllVariables()
{
	for (auto& it : _variables) 
	{
		delete it.second;
	}
}
