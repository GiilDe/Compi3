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
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstdarg>

#define tokens yytokentype
#define YYERROR_VERBOSE 1

#define FOR_EACH(iter, ds, name) \
    for (ds::iterator iter = name.begin(); iter != name.end(); iter++)

#define FOR_EACH_CONST(iter, ds, name) \
    for (__wrap_iter<ds::const_pointer> iter = name.begin(); iter != name.end(); iter++)


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

typedef map<string, var_data> ScopeTable;
typedef map<string, func_data> FuncTable;

vector<string> func_names;
vector<ScopeTable> scopes_tables;
stack<int> offsets_stack;
FuncTable func_table;

map<int, string> type_to_string;
set<int> int_convertables;

void initizlize_type_to_string(){
    type_to_string.insert(pair<int, string>(VOID, "VOID"));
    type_to_string.insert(pair<int, string>(INT, "INT"));
    type_to_string.insert(pair<int, string>(BOOL, "BOOL"));
    type_to_string.insert(pair<int, string>(BYTE, "BYTE"));
    type_to_string.insert(pair<int, string>(STRING, "STRING"));
}


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

    for (map<string, var_data>::iterator i = vars_to_print.begin(); i != vars_to_print.end(); ++i) {
        pair<string, var_data> d = *i;
        var_data data = d.second;
        if(data.offset >= 0)
            vars_pos.push_back(d);
        else
            vars_neg.push_back(d);
    }

    sort(vars_pos.begin(), vars_pos.end(), var_comp);
    sort(vars_neg.begin(), vars_neg.end(), var_comp_rev);

    for(vector<pair<string, var_data> >::iterator j = vars_neg.begin(); j != vars_neg.end(); ++j){
        pair<string, var_data> i = *j;
        printID(i.first, i.second.offset, type_to_string[i.second.type]);
    }

    for(vector<pair<string, var_data> >::iterator j = vars_pos.begin(); j != vars_pos.end(); ++j){
        pair<string, var_data> i = *j;
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
    for (vector<ScopeTable>::iterator i = scopes_tables.begin(); i != scopes_tables.end(); ++i) {
        ScopeTable &t = *i;
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
        for(vector<int>::iterator i = data.param_types.begin(); i != data.param_types.end(); ++i){
            int type = *i;
            args.push_back(type_to_string[type]);
        }
        string s = makeFunctionType(ret_type, args);
        string to_print = name + " " + s + " " + "0";
        cout << to_print << endl;
    }
}

PrecondList* addPreconds(stack_data *pl1, stack_data *pl2) {
    PrecondList* p = dynamic_cast<PrecondList*>(pl1);
    vector<int>& pv = p->preconditions_nums;

    PrecondList* t = new PrecondList();
    vector<int>& tv = t->preconditions_nums;
    if (p != NULL) {
        tv.insert(tv.end(), pv.begin(), pv.end());
    }
    PrecondList* p2 = dynamic_cast<PrecondList*>(pl2);
    vector<int>& pv2 = p2->preconditions_nums;

    if (p2 != NULL) {
        tv.insert(tv.end(), pv2.begin(), pv2.end());
    }
    return t;
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
    t.insert(pair<string, var_data>(name, sd));
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
    func_table.insert(pair<string, func_data>(name, fd));
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

    FOR_EACH(iter, vector<ScopeTable>, scopes_tables) {
        ScopeTable &t = *iter;
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

    FOR_EACH(iter, vector<int>, real_params) {
        int type = *iter;
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
    if (type == NULL || !compare_types(type->type, t)) {
        WRAP_ERROR(errorMismatch(yylineno));
    }
}

void verifyByteSize(stack_data* stackData) {
    Id* num = dynamic_cast<Id*>(stackData);
    int value;
    istringstream(num->id) >> value;
    if (num == NULL || value > 255 || value < 0) {
        WRAP_ERROR(errorByteTooLarge(yylineno, num->id));
    }
}

void verifyIdType(stack_data* idStackData, stack_data* expStackData) {
    Id* id = dynamic_cast<Id*>(idStackData);
    Type* type = dynamic_cast<Type*>(expStackData);

    FOR_EACH(iter, vector<ScopeTable>, scopes_tables) {
        ScopeTable& t = *iter;
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
        if (type != NULL && compare_types(type->type,t) ) {
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

//bool all_ret_same(const vector<int>& ret_params){
//    int last = ret_params[0];
//
//    FOR_EACH_CONST(iter, vector<int>, ret_params) {
//        if(!compare_types(last, *iter))
//            return false;
//    }
//    return true;
//}

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
    int_convertables.insert(INT);
    int_convertables.insert(BYTE);
    int_convertables.insert(NUM);

    func_param_offset = -1;
    offsets_stack.push(0);

    // Add library functions
    vector<int> v1;
    v1.push_back(STRING);
    add_func(v1, static_cast<tokens>(VOID), "print");
    vector<int> v2;
    v2.push_back(INT);
    add_func(v2, static_cast<tokens>(VOID), "printi");

    initizlize_type_to_string();

#ifdef YYDEBUG
    yydebug = 1;
#endif
    return yyparse();
}

#endif //HW3_PARSER_H
