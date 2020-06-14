#include "variable.hpp"
#include <stdexcept>

using namespace ONP_Calculator;

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
    for(std::pair<std::string, double> p : variables)
    {
        if (this->name == p.first) return p.second;
    }
    throw std::invalid_argument("Variable not found");
}

void Variable::assign(double value)
{

    std::pair<std::string, double> p(this->name, value);
    variables.insert(p);
}