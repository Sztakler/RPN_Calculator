#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <string>
#include "constant.hpp"

namespace ONP_Calculator
{
    class Token
    {
        private:
            Constant constant;
            
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
            bool is_function();
            void set_type();
    };  
}


#endif