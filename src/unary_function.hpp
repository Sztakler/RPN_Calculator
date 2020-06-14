#include "function.hpp"
#include <map>
#include <stdexcept>

namespace ONP_Calculator
{
    class UnaryFunction : public Function
    {
        private:
            double argument;

        private:
            void set_arguments(double, double);
            
        public:
            UnaryFunction();
            UnaryFunction(std::string name);
            ~UnaryFunction();

        public:
            double eval() override;
            void set_argument(double argument);
            int get_expression_type() override;
    }; 
}
