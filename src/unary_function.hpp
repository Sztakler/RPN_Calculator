#include "function.hpp"
#include <map>
#include <stdexcept>

namespace ONP_Calculator
{
    class UnaryFunction : public Function
    {
        private:
            double argument;
        public:
            UnaryFunction();
            UnaryFunction(std::string name);
            ~UnaryFunction();

        public:
            double eval() override;
            void set_argument(double argument);
    }; 
}
