#ifndef DEFS_H
#define DEFS_H

typedef enum token_type_enum token_type_e;

typedef struct token_struct token_t;

enum token_type_enum
{
    T_PLUS, 
    T_MINUS, 
    T_STAR, 
    T_SLASH, 
    T_INTLIT
};

struct token_struct
{
    int token;
    int int_value;
};

#endif