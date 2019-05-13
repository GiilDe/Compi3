//
// Created by Gilad on 10-May-19.
//

#ifndef COMPI3_SOURCE_HPP
#define COMPI3_SOURCE_HPP


enum tokens{
    VOID,
    INT,
    BYTE,
    B,
    BOOL,
    AND,
    OR,
    NOT,
    TRUE,
    FALSE,
    RETURN,
    IF,
    ELSE,
    WHILE,
    BREAK,
    CONTINUE,
    PRECOND,
    SC,
    COMMA,
    LPAREN,
    RPAREN,
    LBRACE,
    RBRACE,
    ASSIGN,
    RELOP,
    BINOP,
    ID,
    NUM,
    STRING
};

struct symbol_data{
    tokens type;
    int offset;
};




#endif //COMPI3_SOURCE_HPP
