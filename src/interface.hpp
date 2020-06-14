#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <string>
#include "parser.hpp"
#include "evaluator.hpp"

using namespace ONP_Calculator;

   class Interface
{
    private:
        Parser parser;
        Evaluator evaluator;
    public:
        Interface();
        ~Interface();
        void print(std::string expression);
        void assign(std::string expression);
        void clear();
        void exit();
        void run_interface();
}; 


#endif