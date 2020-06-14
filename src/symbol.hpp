#ifndef SYMBOL_HPP
#define SYMBOL_HPP

namespace ONP_Calculator
{
   class Symbol
    {   
        public:
            enum expression_type{SYMBOL, OPERAND, UNARY_FUNCTION, BINARY_FUNCTION};
            
        protected:
            expression_type type;

        public:
            Symbol();
            ~Symbol();
            virtual double eval() = 0;
            virtual void set_arguments(double, double) = 0;
            virtual int get_expression_type() = 0;
    }; 
}


#endif