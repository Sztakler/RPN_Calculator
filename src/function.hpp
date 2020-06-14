#ifndef FUNCTION_HPP
#define FUNCTION_HPP

#include <string>
#include "symbol.hpp"
#include <math.h>

namespace ONP_Calculator
{
    class Function : public Symbol
    {
        protected:
            std::string name;
        
        public:
            Function();
            Function(std::string name);
            ~Function();
    }; 
}



#endif