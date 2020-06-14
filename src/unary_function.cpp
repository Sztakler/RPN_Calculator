#include "unary_function.hpp"

using namespace ONP_Calculator;

UnaryFunction::UnaryFunction()
{
    this->type = UNARY_FUNCTION;
}

UnaryFunction::UnaryFunction(std::string name) : Function(name)
{
    this->type = UNARY_FUNCTION;
}

UnaryFunction::~UnaryFunction(){}

double UnaryFunction::eval()
{
    if (this->name == "-") return -argument;
    else if(this->name == "abs")
    {
        if (argument < 0) return -argument;
        return argument;
    }
    else if(this->name == "sgn")
    {
        if (argument < 0) return -1;
        if (argument == 0) return 0;
        return 1;
    }
    else if(this->name == "floor") return floor(argument);
    else if(this->name == "ceil") return ceil(argument);
    else if(this->name == "frac")
    {
        return argument - floor(argument);
    }
    else if(this->name == "sin") return sin(argument);
    else if(this->name == "cos") return cos(argument);
    else if(this->name == "atan") return atan(argument);
    else if(this->name == "acot") return M_PI / 2 - atan(argument);
    else if(this->name == "ln") return log(argument);
    else if(this->name == "exp") return exp(argument);
    else throw std::invalid_argument("Unknown function");
}

void UnaryFunction::set_arguments(double first_arg, double second_arg)
{
    set_argument(first_arg);
}

void UnaryFunction::set_argument(double argument)
{
    this->argument = argument;
}

int UnaryFunction::get_expression_type()
{
    return this->type;
}