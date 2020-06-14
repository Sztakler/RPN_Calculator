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
            std::queue<Symbol*> queue;

        public:
            Parser();
            ~Parser();

        public:
            void parse();
            int classify();
            std::queue<Symbol*> get_queue();
    }; 
}

#endif
