#include "number.hpp"

using namespace ONP_Calculator;

Number::Number(){}

Number::Number(double value) : value(value){}

Number::~Number(){}

double Number::eval()
{
    return this->value;
}