#pragma once
#include "InterpreterException.h"
#include "Type.h"
#include "SyntaxException.h"
#include "IndentationException.h"
#include "Integer.h"
#include "Boolean.h"
#include <algorithm>
#include "String.h"
#include "Helper.h"
#include <string>
#include <unordered_map>
#include <iostream>
#include <sstream>
#include <regex>

#define NUMBER_OF_EQUALS 1


class Parser
{
public:
    static Type* parseString(std::string str);
    static Type* getType(std::string& str);

private:
    static bool isLegalVarName(std::string str);
    static bool makeAssignment(std::string str);
    static std::unordered_map<std::string, Type*> _variables;
    static Type* getVariableValue(std::string str);
    static void deleteAllVariables();

};
