#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include <iostream>
#include <queue>
#include "includes.hpp"

namespace ONP_Calculator
{
    class Parser
    {
        private:
            Token token;

        public:
            Parser();
            ~Parser();

        public:
            std::queue<Symbol*> parse(std::string& concrete_expression);
            int classify();
            std::string get_token_name(std::string& expression);
    }; 
}

#endif
