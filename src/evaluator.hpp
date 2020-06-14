#ifndef EVALUATOR_HPP
#define EVALUATOR_HPP

#include "parser.hpp"
#include <stack>

namespace ONP_Calculator
{
   class Evaluator
    {
        private:
            std::stack<double> stack;

        public:
            Evaluator();
            ~Evaluator();

        public:
            double evaluate(std::queue<Symbol*> queue); 
    };
}

#endif