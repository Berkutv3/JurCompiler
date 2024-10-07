#ifndef LL1PARSER_HPP
#define LL1PARSER_HPP
#include "LL1TAS.hpp"
#include "Lexer.hpp"
#include <iomanip>
class LL1Parser
{
private:
    LL1TAS T;
    Lexer L;
    std::vector<int> stack;
    int error(){
        std::cout<<"\nError de sintaxis"<<std::endl;
        return 1;
    }
public:
    LL1Parser(std::string);
    int getToken();
    int Parse();
    void printStack();
    std::string symbol(int);
    void entrada(int);
};

#endif