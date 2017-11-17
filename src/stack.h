#ifndef _STACK_H
#define _STACK_H

#include "array.h"

typedef struct stack{
    array_t array;
    int top;
} Stack_t;

void stack_init(Stack_t *pstack, size_t width);
void stack_destroy(Stack_t *pstack);

void stack_push(Stack_t *pstack, void *value);
void stack_pop(Stack_t *pstack);

int stack_empty(Stack_t stack);

void *stack_top(Stack_t stack);


#endif
