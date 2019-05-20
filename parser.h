//
// Created by Miki Mints on 2019-05-19.
//

#ifndef HW3_PARSER_H
#define HW3_PARSER_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "source.hpp"
#include "output.hpp"
#include "cmake-build-debug/parser.tab.hpp"
#include <vector>
#include <stack>
#include <unordered_map>
#include <string>
#include <iostream>

#define tokens yytokentype
#define YYERROR_VERBOSE 1

#define WRAP_ERROR(exp) \
    do { \
        exp; \
        error(); \
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

vector<ScopeTable> scopes_tables;
stack<int> offsets_stack;
FuncTable func_table;

bool in_while = false;

int func_param_offset;

void exit_scope() {
    int offset = offsets_stack.top();
    offsets_stack.pop();
    ScopeTable& t = scopes_tables.back();
    scopes_tables.pop_back();

    bool is_function_scope = false;

    endScope();
//    TODO Implement
//    if (is_function_scope) {
//        printPreconditions()
//    }

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

bool add_func(vector<int> param_types, tokens ret_type, string name) {
    func_data fd = {param_types, ret_type};
    if (func_table.find(name) != func_table.end()) {
        return false;
    }
    func_table.insert({name, fd});
    return true;
}

void error() {
    exit(5);
}

void tryAddVariable(stack_data *type_class, stack_data *id_class, bool func_var) {
    if (!addVariable(type_class, id_class, func_var)) {
        Id *id = dynamic_cast<Id *>(id_class);
        WRAP_ERROR(errorDef(yylineno, id->id));
    }
}

tokens getVariableType(stack_data* stackData) {
    Id* varId = dynamic_cast<Id*>(stackData);
    ScopeTable &t = scopes_tables.back();
    var_data& varData = t[varId->id];
    return varData.type;
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

void verifyVariableDefined(stack_data * stackData) {
    Id* varId = dynamic_cast<Id*>(stackData);
    if (!contains_var(varId->id)) {
        WRAP_ERROR(errorUndef(yylineno, varId->id));
    }
}

void verifyType(stack_data *stackData, int t) {
    Type* type = dynamic_cast<Type*>(stackData);
    if (type == nullptr || type->type != t) {
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

int verifyTypes(stack_data *stackData, int num, ...) {
    Type* type = dynamic_cast<Type*>(stackData);

    va_list arguments;

    va_start(arguments, num);           // Initializing arguments to store all values after num
    for ( int x = 0; x < num; x++) {
        int t = va_arg(arguments, int);
        if (type != nullptr && type->type == t) {
            return t;
        }
    }
    va_end(arguments);

    WRAP_ERROR(errorMismatch(yylineno));
    // Unreachable
    return -1;
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

void yyerror(char * err) {
    WRAP_ERROR(errorSyn(yylineno));
}

int main() {
    func_param_offset = -1;
    offsets_stack.push(0);

    // Add library functions
    add_func({STRING}, static_cast<tokens>(VOID), "print");
    add_func({INT}, static_cast<tokens>(VOID), "printi");

#ifdef YYDEBUG
    yydebug = 1;
#endif
    return yyparse();
}

#endif //HW3_PARSER_H
