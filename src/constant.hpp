#ifndef CONSTANT_HPP
#define CONSTANT_HPP

#include <vector>
#include <string>
#include "operand.hpp"
#include <stdexcept>

namespace ONP_Calculator
{
    static std::vector<std::pair<std::string, double>> constants = {std::pair<std::string, double>("e", 2.718281828459),
                                                                    std::pair<std::string, double>("pi", 3.14159265358),
                                                                    std::pair<std::string, double>("phi", 1.61803398875)};

    class Constant : public Operand
    {
        private:
            std::string name;                                                   

        public:
            Constant();
            Constant(std::string name);
            ~Constant();
        
        private:
            void set_arguments();

        public:
            double eval();
    };

}

#endif