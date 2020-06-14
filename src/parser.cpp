#include "parser.hpp"

using namespace ONP_Calculator;

Parser::Parser(){}
Parser::~Parser(){}

std::string Parser::get_token_name(std::string& expression)
{
    int i = 0;
    for(char c : expression)
    {
        if (c == ' ') i++;
        else break;
    }

    expression = expression.substr(i);

    std::string result;
    for(char c : expression)
    {
        if (c == ' ') break;
        result += c;
    }
    
    expression = expression.substr(result.size());

    return result;
}

std::queue<Symbol*> Parser::parse(std::string& concrete_expression)
{
    std::queue<Symbol*> queue;

    std::string token_name = get_token_name(concrete_expression);

    while(token_name != "" && token_name != "to")
    {
        this->token.value = token_name;
        this->token.set_type();
        Symbol* symbol;
        switch (this->token.type)
        {
            case this->token.NUMBER:
                symbol = new Number(std::stod(this->token.value));
                break;
            case this->token.CONSTANT:
                symbol = new Constant(this->token.value);
                break;
            case this->token.UNARY_FUNCTION:
                symbol = new UnaryFunction(this->token.value);
                break;
            case this->token.BINARY_FUNCTION:
                symbol = new BinaryFunction(this->token.value);
                break;
            case this->token.VARIABLE:
                symbol = new Variable(this->token.value);
                break;
            default: throw std::invalid_argument("Unrecognized token");
        }     
        
        queue.push(symbol);
        token_name = get_token_name(concrete_expression);
    } 
    return queue;
}
