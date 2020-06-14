#include <iostream>
#include "parser.hpp"
#include "evaluator.hpp"

using namespace ONP_Calculator;

int main()
{
    Parser parser;
    Evaluator evaluator;
    parser.parse();
    std::cout << evaluator.evaluate(parser.get_queue()) << std::endl;

    return 0;
}