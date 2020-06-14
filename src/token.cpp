#include "token.hpp"
#include <iostream>

using namespace ONP_Calculator;

Token::Token(){set_type();}

Token::Token(std::string value) : value(value)
{
    set_type();
}

Token::~Token(){}

bool Token::is_number()
{
    if(value.size() < 1) return false;
    for (char digit : value)
    {
        if (!(digit <=57 && digit >= 48)) return false;
    }
    return true;
}

bool Token::is_constant()
{
    if (this->value == "e" ||
        this->value == "pi" || 
        this->value == "phi") return true;
    return false;
}

bool Token::is_variable()
{
    if (this->value.size() < 7 && this->value.size() > 0 && !is_number()) return true;
    return false;
}

bool Token::is_function()
{
    if(this->value == "modulo" ||
    this->value == "min" ||
    this->value == "max" ||
    this->value == "log" ||
    this->value == "pow" ||
    this->value == "abs" ||
    this->value == "sgn" ||
    this->value == "floor" ||
    this->value == "ceil" ||
    this->value == "fact" ||
    this->value == "sin" ||
    this->value == "cos" ||
    this->value == "atan" ||
    this->value == "acot" ||
    this->value == "ln" ||
    this->value == "exp") return true;
    return false;
}

void Token::set_type()
{
    if(is_constant()) this->type = CONSTANT;
    else if(is_number()) this->type = NUMBER;
    else if(is_variable()) this->type = VARIABLE;
    else if(is_function()) this->type = UNARY_FUNCTION;
    else if(is_function()) this->type = BINARY_FUNCTION;
    else this->type = UNRECOGNIZED;
}