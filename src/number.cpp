#include "number.hpp"

using namespace ONP_Calculator;

Number::Number()
{
    this->type = OPERAND;
}

Number::Number(double value) : value(value)
{
    this->type = OPERAND;
}

Number::~Number(){}

double Number::eval()
{
    return this->value;
}