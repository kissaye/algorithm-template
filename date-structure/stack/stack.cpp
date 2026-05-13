#include <iostream>
#include "stack.h"

// 栈stacks
// 以有组织的方式放入我们定义的变量，只可以删除最近添加的方式
// lifo结构，last in, first out
// 由于这种结构只可以对stacks做两件事，一个是push，在栈的顶端加入数据
// 一种是pop，在栈的顶端删除数据
// 从两个方面实现，一种数组的角度，一种链表的角度

// push函数和之前单链表insert一样
stack *push(stack *top, int a)
{
    // a. 动态分配一个新的节点
    stack *newnode = new stack;
    // b. 检查内存是否分配成功
    if (newnode == nullptr)
    {
        return top;
    }
    // c. 填装新节点，并把他插入到链表头部
    newnode->next = top;
    newnode->a = a;

    // d. 返回新的链表头指针
    return newnode;
}

// pop函数需要删除链表头部，并返回新的链表头指针。弹出栈顶元素
stack *pop(stack *top)
{
    // a.需要创建一个stack类型指针副本指向链表中第二个
    if (top == nullptr)
    {
        std::cout << "stack underflow1" << std::endl;
        return nullptr;
    }
    // b. delete 原来第一个节点，使 list 等于副本
    stack *temp = top;
    top = top->next;
    delete temp;

    // c. 返回新的链表头指针
    return top;
}

// peek 查看栈顶元素
int peek(stack *top)
{
    if (top == nullptr)
    {
        std::cout << "stack underflow" << std::endl;
        return -1;
    }
    return top->a;
}

// 释放整个栈
void freestack(stack *top)
{
    while (top)
    {
        top = pop(top);
    }
}

// 判断栈是否为空
bool isempty(stack *top)
{
    return top == nullptr;
}
