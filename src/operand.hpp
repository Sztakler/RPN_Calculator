#ifndef OPERAND_HPP
#define OPERAND_HPP

#include "symbol.hpp"

namespace ONP_Calculator
{
    class Operand : public Symbol
    {

        private:
            void set_arguments(double, double);
        public:
            Operand();
            ~Operand();
            
        public:
            int get_expression_type() override;
    };
}


#endif