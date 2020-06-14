#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <string>
#include <set>
#include "constant.hpp"

namespace ONP_Calculator
{

    class Token
    {
        private:
            Constant constant;
            std::set<std::string> invalid_names = {"print", "assign", "clear", "exit", "to"};
            std::set<std::string> unary_operators = {"abs", "sgn", "floor", "ceil",
                                                        "frac", "sin", "cos", "atan", "acot", "ln", "exp"};
            std::set<std::string> binary_operators = {"+", "-", "*", "/", "modulo", "min", "max", "log", "pow"};

        public:
            enum symbol_type{UNRECOGNIZED, NUMBER, CONSTANT, VARIABLE, UNARY_FUNCTION, BINARY_FUNCTION};
            symbol_type type;
            std::string value;
            
        public:
            Token();
            Token(std::string value);
            ~Token();
        
        public:
            bool is_number();
            bool is_constant();
            bool is_variable();
            bool is_unary_function();
            bool is_binary_function();
            void set_type();
    };  
}


#endif