#include "evaluator.hpp"

using namespace ONP_Calculator;

Evaluator::Evaluator(){}

Evaluator::~Evaluator(){}

double Evaluator::evaluate(std::queue<Symbol*> queue)
{
    Symbol* expression;
    double value_1;
    double value_2;

    while(!queue.empty() || !stack.empty())
    {
        expression = queue.front();
        queue.pop();

        std::cout << expression->get_expression_type() << std::endl;

        switch(expression->get_expression_type())
        {
            case expression->OPERAND:
                std::cout << "operand" << std::endl; 
                value_1 = expression->eval();
                stack.push(value_1);
                break;
            case expression->UNARY_FUNCTION:
                std::cout << "unary_function" << std::endl; 
                if(stack.size() < 1) throw std::invalid_argument("Invalid expression: not enough arguments on stack");
                value_1 = stack.top();
                stack.pop();
                expression->set_arguments(value_1, value_1);
                value_1 = expression->eval();
                stack.push(value_1);
                break;
            case expression->BINARY_FUNCTION:
                std::cout << "binary_function" << std::endl; 
                if(stack.size() < 2) throw std::invalid_argument("Invalid expression: not enough arguments on stack");
                value_1 = stack.top();
                stack.pop();
                value_2 = stack.top();
                stack.pop();
                expression->set_arguments(value_1, value_2);
                value_1 = expression->eval();
                stack.push(value_1);
                break;
            default: 
               // throw std::invalid_argument("Invalid expression");
                break;
        }
        
        if (queue.empty() && stack.size() == 1) return stack.top();
    }
    return -1;
}