//
// Created by Gilad on 13-May-19.
//

#ifndef COMPI3_SOURCE_HPP
#define COMPI3_SOURCE_HPP

#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

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

class TypesList : public stack_data {
public:
    vector<int> params;
    TypesList() : params(){}
    TypesList(vector<int> vector) : params(vector){}
};

class Preconditions : public stack_data{
public:
    int preconditions_num;
    Preconditions(int num) : preconditions_num(num){}
};

class PrecondList : public stack_data{
public:
    vector<int> preconditions_nums;
    PrecondList(int num){
        preconditions_nums.push_back(num);
    }
    PrecondList() : preconditions_nums(){}
};



#define YYSTYPE stack_data*


#endif //COMPI3_SOURCE_HPP
