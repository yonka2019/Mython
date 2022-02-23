#include "Type.h"
#include "SyntaxException.h";
#include "InterpreterException.h"
#include "Parser.h"
#include <iostream>

#define WELCOME "Welcome to Magshimim Python Interperter version 1.0 by "
#define YOUR_NAME "Yonatan"


int main(int argc,char **argv)
{
	std::cout << WELCOME << YOUR_NAME << std::endl;

	std::string input_string;
	Type* var;

	// get new command from user
	std::cout << ">>> ";
	std::getline(std::cin, input_string);
	
	while (input_string != "quit()")
	{
		try
		{
			// parsing command
			var = Parser::parseString(input_string);
			if (var == nullptr)
			{
				throw new SyntaxException();
			}
			if (var->isPrintable())
			{
				std::cout << var->toString() << std::endl;
			}
			delete var;
		}
		catch (const InterpreterException* err)
		{
			std::cout << err->what() << std::endl;
		}

		// get new command from user
		std::cout << ">>> ";
		std::getline(std::cin, input_string);

	}

	return 0;
}
