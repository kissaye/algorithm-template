#ifndef SLLIST_H
#define SLLIST_H

#include<stdbool.h>

//数据结构单链表
typedef struct sllist
{
    int a;
    struct sllist *next;
}sllnode;

//基本操作
sllnode* create(int val);
bool find(sllnode*head,int val);
sllnode* insert(sllnode*head,int val);
sllnode* delete_value(sllnode*head,int val);
void destroy(sllnode* head);
void unload(sllnode* head);

//反转链表
sllnode*reverse(sllnode* head);
sllnode*reverse_recursive(sllnode* curr,sllnode*prev);

//环相关
bool has_cycle(sllnode* head);
sllnode* detect_cycle(sllnode*head);

//判断是否回文
bool ispalindrome1(sllnode *head);
bool ispalindrome2(sllnode *head);
bool ispalindrome3(sllnode *head);

//链表排序（荷兰国旗
sllnode * listpartition1(sllnode *head,int pivot);
sllnode * listpartition2(sllnode *head,int pivot);


#endif // SLLIST_H
