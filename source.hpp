//
// Created by Gilad on 13-May-19.
//

#ifndef COMPI3_SOURCE_HPP
#define COMPI3_SOURCE_HPP

#include <string>

using namespace std;

class stack_data{};

class Id : public stack_data{
public:
    string id;
};

class Type : public stack_data{
public:
    int type;
};

#define YYSTYPE stack_data*




#endif //COMPI3_SOURCE_HPP
