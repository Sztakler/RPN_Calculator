#include "variable.hpp"
#include <stdexcept>
#include <iostream>

using namespace ONP_Calculator;

std::map<std::string, double> Variable::variables;

Variable::Variable()
{
    this->type = OPERAND;
}

Variable::Variable(std::string name) : name(name)
{
    this->type = OPERAND;
}

double Variable::eval()
{
    std::map<std::string, double>::iterator iter = this->variables.find(name);
    if (iter != variables.end()) return iter->second;
    throw std::invalid_argument("Variable not found");
}

void Variable::assign(double value, std::string name)
{
    std::pair<std::string, double> p(name, value);
    variables.insert(p);
}

void Variable::clear()
{
    variables.clear();
}