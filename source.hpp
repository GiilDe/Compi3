//
// Created by Gilad on 13-May-19.
//

#ifndef COMPI3_SOURCE_HPP
#define COMPI3_SOURCE_HPP

#include <string>

#define tokens yytokentype

using namespace std;


class dummy{
};

#define YYSTYPE dummy*
#include "cmake-build-debug-cygwin/parser.tab.hpp"

class stack_data : public dummy{
public:
    tokens type;
    string name;
    stack_data(tokens t, const char* c){
        type = t;
        name = string(c);
    }
};





#endif //COMPI3_SOURCE_HPP
