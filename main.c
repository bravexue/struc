#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "src/array.h"
#include "src/list.h"
#include "src/stack.h"
void EXECUTE_EQ(int Expect, int Real)
{
    if (Expect != Real)	{
        printf("Not OK! Expect = %d, Real = %d \n", Expect, Real);
    }
    else {
        printf("OK! \n");
    }
}
void unit_array()
{
    array_t darray; /* 动态数组 */

    array_init(&darray, sizeof(int)); /* 初始化整型动态数组 */
    EXECUTE_EQ(sizeof(int), darray.width);

    int insertvalue1 = 5, insertvalue2 = 10;
    array_insert(&darray, 0, &insertvalue1); /* 插入元素 */
    array_insert(&darray, 1, &insertvalue2); /* 插入元素 */
    EXECUTE_EQ(insertvalue1, *(int*)array_value(darray, 0));
    EXECUTE_EQ(insertvalue2, *(int*)array_value(darray, 1));

    EXECUTE_EQ(2, array_len(darray)); /*数组中2个元素*/

    array_delete(&darray, 0); /* 删除索引2位置的元素 */
    EXECUTE_EQ(1, array_len(darray));

    int setvalue = 8;
    array_set(&darray, 0, &setvalue);
    EXECUTE_EQ(setvalue, *(int*)array_value(darray, 0));

    array_destroy(&darray); /* 释放数组 */
}

void unit_list()
{
    list_t alist;
    list_init(&alist);

    node_t anode;
    anode.value = 3;

    list_add_head(&alist, &anode.chain);
    node_t bnode;
    bnode.value = 5;
    list_insert_index(&alist, 1, &bnode.chain);
    list_travel(alist, list_visit_data);
}

void unit_stack()
{
    Stack_t astack;
    stack_init(&astack, sizeof(int));
    int a = 3, b = 5, c = 8;
    stack_push(&astack, &a);
    stack_push(&astack, &b);
    stack_push(&astack, &c);
    EXECUTE_EQ(*(int*)stack_top(astack), c);
    stack_pop(&astack);
    EXECUTE_EQ(*(int*)stack_top(astack), b);
    stack_pop(&astack);
    EXECUTE_EQ(*(int*)stack_top(astack), a);
    stack_destroy(&astack);

}

int main(int argc, char const *argv[])
{
    //unit_array();
    //unit_list();
    unit_stack();
    return 0;
}