#include "constant.hpp"

using namespace ONP_Calculator;

Constant::Constant(){}

Constant::Constant(std::string name) : name(name){}

Constant::~Constant(){}

double Constant::eval()
{
    for(std::pair<std::string, double> p : constants)
    {
        if(p.first == this->name) return p.second;
    }
    throw std::invalid_argument("Constant name not found");
}
