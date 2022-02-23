#include "Void.h"

Void::Void() : Type()
{
}

bool Void::isPrintable() const
{
    return false;
}

std::string Void::toString() const
{
    return "";
}