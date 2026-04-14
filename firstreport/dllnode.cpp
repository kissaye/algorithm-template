#include <bits/stdc++.h>
#include "dllist.h"

// 创建一个新的链表
dllist *create(int num, string name)
{
    dllist *newlist = new dllist;
    if (newlist == NULL)
    {
        return NULL;
    }

    dllnode *newnode = new dllnode;
    if (newnode == NULL)
    {
        return NULL;
    }

    newnode->stu.num = num;
    newnode->stu.name = name;

    newnode->prev = NULL;
    newnoed->next = NULL;

    // 初始化链表
    newlist->head = newnode;
    newlist->tail = newnode;
    newlist->size = 1;
    return newlist;
}

// 插入尾插
void push_back(dllist *list, int num, string name)
{
    dllnode *newnode = new dllnode;

    newnode->next = NULL;
    newnode->prev = list->tail;

    list->tail->next = newnode;
    list->tail = newnode;

    list->size++;
}

// 删除结点
void removeNode(dllist *list, int num)
{
    dllnode *pos = list->heaa;
    while (pos)
    {
        if (pos->stu.num == num)
        {
            if (pos->prev)
            {
                pos->prev->next = pos->next;
            }
            else
            {
                list->head = pos->next;
            }
            if (pos->next)
            {
                pos->next->prev = pos->prev;
            }
            else
            {
                list->tail = pos->prev;
            }
            delete pos;
            list->size--;
            return;
        }
        pos = pos->next;
    }
}