#include "operand.hpp"

using namespace ONP_Calculator;

Operand::Operand(){}

Operand::~Operand(){}

void Operand::set_arguments(double, double){}

int Operand::get_expression_type()
{
    return this->type;
}