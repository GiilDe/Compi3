//
// Created by Gilad on 10-May-19.
//

#ifndef COMPI3_PARSER_STUFF_HPP
#define COMPI3_PARSER_STUFF_HPP
#include <vector>


#include "cmake-build-debug-cygwin/parser.tab.hpp"

#define tokens yytokentype

using namespace std;

struct var_data{
    tokens type;
    int offset;
};

struct func_data{
    vector<tokens> param_types;
    tokens ret_type;
};




#endif //COMPI3_PARSER_STUFF_HPP
