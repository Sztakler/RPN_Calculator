#include "symbol.hpp"

using namespace ONP_Calculator;

Symbol::Symbol(){}

Symbol::~Symbol(){}

int Symbol::get_expression_type()
{
    return this->type;
}