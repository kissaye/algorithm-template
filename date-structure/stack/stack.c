#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

//栈stacks
//以有组织的方式放入我们定义的变量，只可以删除最近添加的方式
//lifo结构，last in,first out
//由于这种结构只可以对stacks做两件事，一个是push，在栈的顶端加入数据
//一种是pop，在栈的顶端删除数据
//从两个方面实现，一种数组的角度，一种链表的角度


/*
//数组
typedef struct _stack
{
    VALUE array[CAPACITY];
    int top;//top值可以等效计算该数组中有几个元素，或者是下一个元素该存储于哪个位置
}
stack;

void push(stack* s,VALUE date)//两个参数，一个栈指针，一个放入栈顶的数值
{
    //a.接受一个stacks指针
    //b.将value值压入栈顶
    //c.改变top值（这里的top值一般存储已有数组的顶值还要在加1）
}

VALUE pop(stack*s)
{
    //a.接受一个栈指针
    //b.改变栈顶位置（改变之后的arr[top]就是我们刚刚忽略掉的那个元素）
    //c.如果我们想删除一个值，并且返回他，就要return value
    //删除栈顶元素时，只需要把栈的top值忽略掉，而不需要去删除他
}
*/

//链表表示栈
/*typedef struct _stack
{
    int val;
    struct _stack* next;
}
stack;*/
//本身是一个单链表，作为程序员对自己要有限制（只可以动用开头的值）就变成了栈
//始终维护一个指向链表头部的指针



//push函数和之前单链表insert一样
stack* push(stack*top,int a)
{
    //a.动态分配一个新的节点
    stack* newnode=malloc(sizeof(stack));
    //b.检查内存是否分配成功
    if(newnode==NULL)
    {
        return top;
    }
    //c.填装新节点，并把他插入到链表头部
    newnode->next=top;
    newnode->a=a;

    //d.返回新的链表头指针
    return newnode;
}
//pop函数需要删除链表头部，并返回新的链表头指针。弹出栈顶元素
stack* pop(stack* top)
{
    //a.需要创建一个stack类型指针副本指向链表中第二个
    if(top==NULL)
    {
        printf("stack underflow1\n");
        return NULL;
    }
    //b.free原来第一个节点，使list等于副本
    stack* temp=top;
    top=top->next;
    free(temp);

    //c.返回新的链表头指针
    return top;
}

//peek查看栈顶元素
int peek(stack* top)
{
    if(top==NULL)
    {
        printf("stack underflow\n");
        return -1;
    }
    return top->a;
}
//释放整个栈
void freestack(stack *top)
{
    while(top)
    {
        top=pop(top);
    }
}
//判断栈是否为空
bool isempty(stack *top)
{
    return top==NULL;
}
