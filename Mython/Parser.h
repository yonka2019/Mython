#pragma once
#include "InterpreterException.h"
#include "IndentationException.h"
#include "Type.h"
#include "Helper.h"
#include <string>
#include <unordered_map>
#include <iostream>
#include <sstream>


class Parser
{
public:
	static Type* parseString(std::string str);

private:

};
