#ifndef NUMBER_HPP
#define NUMBER_HPP

#include "operand.hpp"

namespace ONP_Calculator
{
    class Number : public Operand
    {
        private:
            double value;
        
        public:
            Number();
            Number(double value);
            ~Number();

        public:
            double eval();
    };
}


#endif