#include "binary_function.hpp"

using namespace ONP_Calculator;

BinaryFunction::BinaryFunction(){}
BinaryFunction::BinaryFunction(std::string name) : Function(name){}
BinaryFunction::~BinaryFunction(){}

double BinaryFunction::eval()
{
    if(this->name == "+") return first_arg + second_arg;
    else if(this->name == "-") return first_arg - second_arg;
    else if(this->name == "*") return first_arg * second_arg;
    else if(this->name == "/") return first_arg / second_arg;
    else if(this->name == "modulo") return fmod(first_arg, second_arg);
    else if(this->name == "min") return std::min(first_arg, second_arg);
    else if(this->name == "max") return std::max(first_arg, second_arg);
    else if(this->name == "log") return log(first_arg) / log(second_arg);
    else if(this->name == "pow") return pow(first_arg, second_arg);
    else throw std::invalid_argument("Unknown function");
}

void BinaryFunction::set_arguments(double first_arg, double second_arg)
{
    this->first_arg = first_arg;
    this->second_arg = second_arg;
}
