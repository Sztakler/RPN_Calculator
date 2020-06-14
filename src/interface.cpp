#include "interface.hpp"

Interface::Interface(){}
Interface::~Interface(){}

void Interface::print(std::string expression)
{
    std::cout << evaluator.evaluate(parser.parse(expression)) << std::endl;
}

void Interface::assign(std::string expression)
{
    double value = evaluator.evaluate(parser.parse(expression));
    expression = expression.substr(1);
    Variable::assign(value, parser.get_token_name(expression));
}

void Interface::clear()
{
    Variable::clear();
}

void Interface::run_interface()
{
    std::string expression;
    std::string command;

    while(true)
    {
        try
        {
            std::cout << "$ ";
            getline(std::cin, expression);
            command = parser.get_token_name(expression);

            if (command == "print")
            {
                print(expression);
            }
            else if (command == "assign")
            {
                assign(expression);
            }
            else if (command == "clear")
            {
                clear();
            }
            else if(command == "exit")
            {
                break;
            }
            else std::cout << "unknown command" << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}