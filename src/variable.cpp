#include "variable.hpp"

using namespace ONP_Calculator;

Variable::Variable(){}

Variable::Variable(std::string name) : name(name){}

double Variable::eval()
{
    for(std::pair<std::string, double> p : variables)
    {
        if (this->name == p.first) return p.second;
    }
    throw "Variable not found";
}

void Variable::assign(double value)
{

    std::pair<std::string, double> p(this->name, value);
    variables.insert(p);
}