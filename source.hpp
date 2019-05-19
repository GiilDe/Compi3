//
// Created by Gilad on 13-May-19.
//

#ifndef COMPI3_SOURCE_HPP
#define COMPI3_SOURCE_HPP

#include <string>
#include <vector>


using namespace std;

class stack_data {
public:
    virtual ~stack_data() = default;
};

class Id : public stack_data {
public:
    string id;

    Id(const string &id) : id(id) {}
};

class Type : public stack_data {
public:
    int type;

    Type(int type) : type(type) {}
};

class ParamsList : public stack_data {
public:
    vector<int> params;
};

#define YYSTYPE stack_data*


#endif //COMPI3_SOURCE_HPP
