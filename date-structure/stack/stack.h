#ifndef STACK_H
#define STACK_H

#ifdef __cplusplus
#include <cstdbool>
extern "C" {
#else
#include <stdbool.h>
#endif

// 栈节点类型
typedef struct _stack
{
    int a;
    struct _stack* next;
} stack;

// 栈操作接口
stack* push(stack* top, int a);      // 入栈
stack* pop(stack* top);              // 出栈
int peek(stack* top);                // 查看栈顶元素
void freestack(stack* top);          // 释放整个栈
bool isempty(stack *top);

#ifdef __cplusplus
}
#endif

#endif // STACK_H
