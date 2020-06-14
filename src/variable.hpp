#ifndef VARIABLE_HPP
#define VARIABLE_HPP

#include <map>
#include <string>
#include "operand.hpp"

namespace ONP_Calculator
{
    

    class Variable : public Operand
    {
        private:
            std::string name;
            static std::map<std::string, double> variables;
    
        public:
            Variable();
            Variable(std::string name);
            ~Variable();

        public:
            double eval();
            static void assign(double value, std::string name);
            static void clear();
    };
}



#endif