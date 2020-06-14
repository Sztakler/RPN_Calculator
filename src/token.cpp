#include "token.hpp"
#include <iostream>

using namespace ONP_Calculator;

Token::Token()
{
    set_type();
}

Token::Token(std::string value) : value(value)
{
    set_type();
}

Token::~Token(){}

bool Token::is_number()
{
    if(value.size() < 1) return false;
    if(value.size() > 1 && value[0] == '0') return false;

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
    if (this->value.size() < 7 && this->value.size() > 0 && !is_number() && value[0] != '0' &&
        (this->unary_operators.find(this->value) == unary_operators.end()) &&
        (this->binary_operators.find(this->value) == binary_operators.end()) &&
        (this->invalid_names.find(this->value) == invalid_names.end())) return false;
    return true;
}

bool Token::is_unary_function()
{
   if(this->unary_operators.find(this->value) != unary_operators.end()) return true;
    return false;
}

bool Token::is_binary_function()
{
    if(this->binary_operators.find(this->value) != binary_operators.end()) return true;
    return false;     
}

void Token::set_type()
{
    if(is_constant()) this->type = CONSTANT;
    else if(is_number()) this->type = NUMBER;
    else if(is_unary_function()) this->type = UNARY_FUNCTION;
    else if(is_binary_function()) this->type = BINARY_FUNCTION;
    else if(is_variable()) this->type = VARIABLE;
    else this->type = UNRECOGNIZED;
}