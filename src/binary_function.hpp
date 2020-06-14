#include "function.hpp"
#include <algorithm>
#include <stdexcept>

namespace ONP_Calculator
{   
    class BinaryFunction : public Function
    {
        private:
            std::string name;
            double first_arg;
            double second_arg;

        public:
            BinaryFunction();
            BinaryFunction(std::string name);
            ~BinaryFunction();

        public:
            double eval();
            void set_arguments(double first_arg, double second_arg);
    };
    
}

