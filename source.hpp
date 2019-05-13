//
// Created by Gilad on 13-May-19.
//

#ifndef COMPI3_SOURCE_HPP
#define COMPI3_SOURCE_HPP

#include <string>

#define tokens yytokentype

using namespace std;


#define YYSTYPE stack_data

struct stack_data{
    int type;
    string name;
};





#endif //COMPI3_SOURCE_HPP
