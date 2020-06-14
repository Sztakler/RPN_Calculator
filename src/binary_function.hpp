#include "function.hpp"
#include <algorithm>
#include <stdexcept>
#include <string>

namespace ONP_Calculator
{   
    class BinaryFunction : public Function
    {
        private:
            double first_arg;
            double second_arg;

        public:
            BinaryFunction();
            BinaryFunction(std::string name);
            ~BinaryFunction();

        public:
            double eval();
            void set_arguments(double first_arg, double second_arg);
            int get_expression_type() override;
    };
    
}

