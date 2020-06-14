#include "parser.hpp"

using namespace ONP_Calculator;

Parser::Parser(){}
Parser::~Parser(){}

void Parser::parse()
{
    char c;
    std::cin.get(c);
    while (c != '\n') 
    {
        this->token.value = "";
        
        while(c != ' ' && c != '\n')
        {
            this->token.value += c;
            std::cin.get(c);
        }

        this->token.set_type();
        Number* number;
        Constant* constant;
        Variable* variable;
        UnaryFunction* u_function;
        BinaryFunction* b_function;

        std::cout << this->token.value << std::endl;

        switch (this->token.type)
        {
            case this->token.NUMBER:
                number = new Number(std::stod(this->token.value));
                this->queue.push(number);
                break;
            case this->token.CONSTANT:
                constant = new Constant(this->token.value);
                this->queue.push(constant);
                break;
            case this->token.VARIABLE:
                variable = new Variable(this->token.value);
                this->queue.push(variable);
                break;
            case this->token.UNARY_FUNCTION:
                u_function = new UnaryFunction(this->token.value);
                this->queue.push(u_function);
                break;
            case this->token.BINARY_FUNCTION:
                b_function = new BinaryFunction(this->token.value);
                this->queue.push(b_function);
                break;
            default: throw std::invalid_argument("Unrecognized token");
        }     
        
        if(c != '\n') std::cin.get(c);
    }
  
}

