#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "stack.h"

void stack_init(Stack_t *pstack, size_t width)
{
    array_init(&(pstack->array), width);
    pstack->top = -1;
}
void stack_destroy(Stack_t *pstack)
{
    array_destroy(&(pstack->array));
}
void stack_push(Stack_t *pstack, void *value)
{     
    array_insert(&pstack->array, (pstack->array).len, value);
    pstack->top = pstack->top + 1;    
}
void stack_pop(Stack_t *pstack)
{
    if (pstack->top == -1){
	printf("stack empty!\n");
	exit(1);
    }
    array_delete(&pstack->array, pstack->top);
    pstack->top = pstack->top - 1;
} 
int stack_empty(Stack_t stack)
{
    return (stack.top == -1) ? 1 : 0;
}
void *stack_top(Stack_t stack)
{
    if (stack.top == -1){
	printf("stack empty!\n");
	exit(1);
    }
    return array_value(stack.array, stack.top);
}



