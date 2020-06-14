#ifndef VARIABLE_HPP
#define VARIABLE_HPP

#include <map>
#include <string>
#include "operand.hpp"

namespace ONP_Calculator
{
    static std::map<std::string, double> variables;

    class Variable : public Operand
    {
        private:
            std::string name;

        public:
            Variable();
            Variable(std::string name);
            ~Variable();

        public:
            double eval();
            void assign(double value);
    };
}



#endif