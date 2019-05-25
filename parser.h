//
// Created by Miki Mints on 2019-05-19.
//

#ifndef HW3_PARSER_H
#define HW3_PARSER_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <utility>
#include "source.hpp"
#include "output.hpp"
#include "parser.tab.hpp"
#include <vector>
#include <stack>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <iostream>
#include <cstdarg>

#define tokens yytokentype
#define YYERROR_VERBOSE 1

#define WRAP_ERROR(exp) \
    do { \
        exp; \
        exit(1); \
    } while (0)

using namespace std;
using namespace output;

/**
 * External lexical analyzer function
 */
extern int yylex();

/**
 * External parser function
 */
extern int yyparse();

/**
 * Line count for lex
 */
extern int yylineno;
extern int yydebug;

int in_while = 0;
int func_param_offset;
int current_return_type;

struct var_data {
    tokens type;
    int offset;
};

struct func_data {
    vector<int> param_types;
    tokens ret_type;
};

typedef unordered_map<string, var_data> ScopeTable;
typedef unordered_map<string, func_data> FuncTable;

vector<string> func_names;
vector<ScopeTable> scopes_tables;
stack<int> offsets_stack;
FuncTable func_table;

unordered_map<int, string> type_to_string;

void initizlize_type_to_string(){
    type_to_string.insert({VOID, "VOID"});
    type_to_string.insert({INT, "INT"});
    type_to_string.insert({BOOL, "BOOL"});
    type_to_string.insert({BYTE, "BYTE"});
    type_to_string.insert({STRING, "STRING"});
}

unordered_set<int> int_convertables = {INT, BYTE, NUM};

bool compare_types(int assignee, int rvalue) {
    if(assignee == rvalue || (assignee == INT && (int_convertables.find(rvalue) != int_convertables.end()))) {
        return true;
    }
    return false;
}

bool compare_types(vector<int>& v1, vector<int>& v2){
    if(v1.size() != v2.size()){
        return false;
    }
    for (int i = 0; i < v1.size(); ++i){
        if(!compare_types(v1[i], v2[i]))
            return false;
    }
    return true;
}

bool var_comp(const pair<string, var_data>& v1, const pair<string, var_data>& v2) {
    var_data d1 = v1.second;
    var_data d2 = v2.second;
    return d1.offset < d2.offset;
}

bool var_comp_rev(const pair<string, var_data>& v1, const pair<string, var_data>& v2) {
    var_data d1 = v1.second;
    var_data d2 = v2.second;
    return d1.offset > d2.offset;
}

void exit_scope(bool is_func, stack_data* name, stack_data* precond_num) {
    endScope();
    if(is_func){
        string id = dynamic_cast<Id*>(name)->id;
        int n = dynamic_cast<Preconditions*>(precond_num)->preconditions_num;
        printPreconditions(id, n);
    }
    int offset = offsets_stack.top();
    offsets_stack.pop();
    ScopeTable& vars_to_print = scopes_tables.back();
    vector<pair<string, var_data> > vars_pos;
    vector<pair<string, var_data> > vars_neg;

    for(pair<string, var_data> d : vars_to_print){
        var_data data = d.second;
        if(data.offset >= 0)
            vars_pos.push_back(d);
        else
            vars_neg.push_back(d);
    }

    sort(vars_pos.begin(), vars_pos.end(), var_comp);
    sort(vars_neg.begin(), vars_neg.end(), var_comp_rev);

    for(auto& i : vars_neg){
        printID(i.first, i.second.offset, type_to_string[i.second.type]);
    }

    for(auto& i : vars_pos){
        printID(i.first, i.second.offset, type_to_string[i.second.type]);
    }

    scopes_tables.pop_back();
}

void new_scope() {
    func_param_offset = -1;
    offsets_stack.push(offsets_stack.top());
    scopes_tables.push_back(ScopeTable());
}

bool contains_var(string &name) {
    for (ScopeTable &t : scopes_tables) {
        if (t.find(name) != t.end()) {
            return true;
        }
    }
    return false;
}

void exit_last_scope(){
    endScope();
    for(int i = 0; i < func_names.size(); i++){
        string& name = func_names[i];
        func_data data = func_table[name];
        string ret_type = type_to_string[data.ret_type];
        vector<string> args;
        for(int type : data.param_types){
            args.push_back(type_to_string[type]);
        }
        string s = makeFunctionType(ret_type, args);
        string to_print = name + " " + s + " " + to_string(0);
        cout << to_print << endl;
    }
}

bool addVariable(stack_data *varType, stack_data *varId, bool isFunctionParameter) {
    Type *conv1 = dynamic_cast<Type *>(varType);
    Id *conv2 = dynamic_cast<Id *>(varId);

    tokens type = static_cast<tokens>(conv1->type);
    string name = conv2->id;

    if (contains_var(name) || func_table.find(name) != func_table.end()) {
        return false;
    }
    int *offset;
    if (isFunctionParameter)
        offset = &func_param_offset;
    else
        offset = &offsets_stack.top();
    var_data sd = {type, *offset};
    ScopeTable &t = scopes_tables.back();
    t.insert({name, sd});
    if (isFunctionParameter)
        (*offset)--;
    else
        (*offset)++;
    return true;
}

void add_func(vector<int> param_types, tokens ret_type, const string& name) {
    func_data fd = {param_types, ret_type};
    if (func_table.find(name) != func_table.end()) {
        WRAP_ERROR(errorDef(yylineno, name));
    }
    func_table.insert({name, fd});
    func_names.push_back(name);
}

void tryAddVariable(stack_data *type_class, stack_data *id_class, bool func_var) {
    if (!addVariable(type_class, id_class, func_var)) {
        Id *id = dynamic_cast<Id *>(id_class);
        WRAP_ERROR(errorDef(yylineno, id->id));
    }
}

tokens getVariableType(stack_data* stackData) {
    Id* varId = dynamic_cast<Id*>(stackData);

    for (ScopeTable &t : scopes_tables) {
        if (t.find(varId->id) != t.end()) {
            var_data& varData = t[varId->id];
            return varData.type;
        }
    }
    // Error
    WRAP_ERROR(errorUndef(yylineno, varId->id));
}

tokens getFunctionReturnType(stack_data* stackData) {
    Id* funId = dynamic_cast<Id*>(stackData);
    func_data& funcData = func_table[funId->id];
    return funcData.ret_type;
}

void verifyFunctionDefined(stack_data* stackData) {
    Id* functionId = dynamic_cast<Id*>(stackData);
    if (func_table.find(functionId->id) == func_table.end()) {
        WRAP_ERROR(errorUndefFunc(yylineno, functionId->id));
    }
}

void verifyRightParams(stack_data* func_name, stack_data* param_list){
    string functionId = dynamic_cast<Id*>(func_name)->id;
    vector<int>& params = dynamic_cast<TypesList*>(param_list)->params;
    vector<int>& real_params = func_table[functionId].param_types;
    vector<string> params_string;
    for(int type : real_params){
        string s = type_to_string[type];
        params_string.push_back(s);
    }
    if(!compare_types(real_params, params)){
        WRAP_ERROR(errorPrototypeMismatch(yylineno, functionId, params_string));
    }
}

void verifyVariableDefined(stack_data * stackData) {
    Id* varId = dynamic_cast<Id*>(stackData);
    if (!contains_var(varId->id)) {
        WRAP_ERROR(errorUndef(yylineno, varId->id));
    }
}

void verifyType(stack_data *stackData, int t) {
    Type* type = dynamic_cast<Type*>(stackData);
    if (type == nullptr || !compare_types(type->type, t)) {
        WRAP_ERROR(errorMismatch(yylineno));
    }
}

void verifyByteSize(stack_data* stackData) {
    Id* num = dynamic_cast<Id*>(stackData);
    int value = stoi(num->id);
    if (num == nullptr || value > 255 || value < 0) {
        WRAP_ERROR(errorByteTooLarge(yylineno, num->id));
    }
}

void verifyIdType(stack_data* idStackData, stack_data* expStackData) {
    Id* id = dynamic_cast<Id*>(idStackData);
    Type* type = dynamic_cast<Type*>(expStackData);

    for (ScopeTable &t : scopes_tables) {
        if (t.find(id->id) != t.end()) {
            var_data& varData = t[id->id];
            if (!compare_types(varData.type, type->type)) {
                WRAP_ERROR(errorMismatch(yylineno));
            }
        }
    }
}

void verifyReturn(int type) {
    if (!compare_types(current_return_type, type)) {
        WRAP_ERROR(errorMismatch(yylineno));
    }
}

int verifyTypes(stack_data *stackData, int num, ...) {
    Type* type = dynamic_cast<Type*>(stackData);

    va_list arguments;

    va_start(arguments, num);           // Initializing arguments to store all values after num
    for ( int x = 0; x < num; x++) {
        int t = va_arg(arguments, int);
        if (type != nullptr && compare_types(type->type,t) ) {
            return t;
        }
    }
    va_end(arguments);

    WRAP_ERROR(errorMismatch(yylineno));
    // Unreachable
    return -1;
}

void verifyBreak() {
    if (!in_while) {
        WRAP_ERROR(errorUnexpectedBreak(yylineno));
    }
}

void verifyContinue() {
    if (!in_while) {
        WRAP_ERROR(errorUnexpectedContinue(yylineno));
    }
}

void verifyMainFunction() {
    FuncTable::iterator iterator = func_table.find("main");
    if (iterator == func_table.end()                // main is not declared in code
        || !(*iterator).second.param_types.empty()  // main() has parameters (and shouldn't)
        || (*iterator).second.ret_type != VOID)     // Return type is not void
    {
        WRAP_ERROR(errorMainMissing());
    }
}

void addFunctionDeclaration(stack_data* retType, stack_data *idVarData, stack_data* typesList) {
    tokens ret_type = (tokens) dynamic_cast<Type*>(retType)->type;
    Id * idVar = dynamic_cast<Id*>(idVarData);
    string id = idVar->id;
    TypesList* func_params = dynamic_cast<TypesList*>(typesList);
    add_func(func_params->params, ret_type, id);
}

void yyerror(const char * err) {
    WRAP_ERROR(errorSyn(yylineno));
}

bool all_ret_same(const vector<int>& ret_params){
    int last = ret_params[0];
    for(int i : ret_params){
        if(!compare_types(last, i))
            return false;
    }
    return true;
}

int get_ret_from_statements(TypesList* ret_types){
    if (ret_types == NULL){
        return static_cast<int>(VOID);
    }
    else{
        return ret_types->params[0];
    }
}

void concatenate_params(vector<int>& v, TypesList* t1, TypesList* t2){
    if(t1 != NULL){
        v.insert(v.end(), t1->params.begin(), t1->params.end());
    }
    if(t2 != NULL){
        v.insert(v.end(), t2->params.begin(), t2->params.end());
    }
}

int main(){
    func_param_offset = -1;
    offsets_stack.push(0);

    // Add library functions
    add_func({STRING}, static_cast<tokens>(VOID), "print");
    add_func({INT}, static_cast<tokens>(VOID), "printi");

    initizlize_type_to_string();

//#ifdef YYDEBUG
//    yydebug = 1;
//#endif
    return yyparse();
}

#endif //HW3_PARSER_H
