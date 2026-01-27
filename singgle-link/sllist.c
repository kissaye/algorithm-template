#include<stdio.h>
#include<stdlib.h>
#include"sllist.h"



sllnode* create (int val)
{

    //a.dynamically（动态） allocate（分配） space for a new sllnode动态分配一个内存
    sllnode* newnode=malloc(sizeof(sllnode));

    //b.check to make sure we didn't run out of memery
    //防止返回一个NULL空指针，解引该指针
    if(newnode==NULL)
    return NULL;

    //c.innitialize初始化 the node(节点)'s val field
    newnode->a=val;
    //d.innitialize the node's next field
    //初始化结构体中的变量
    newnode->next=NULL;

    //e.return a pointer to the newly created sllonde
    return newnode;

    //如果他是最后一个，那么将结构体中的next值变为null
}
//创建一个函数查找链表中元素的值
bool find(sllnode *head,int val)
{

    //a.create a travelsal pointer pointing to the list's head
    //创建一个动态指针指向该链表的头部
    sllnode* trav =head;
    //b.if the current node's val field is what we're looking for,report success
    //如果该链表的val值是我们所寻找的，返回ture
    //c.if not ,see the travelsal pointer to the next in the list and go back to the step b
    //如果不是，使得动态指针为当前指针的next变量，再返回b步骤
    //d.if you've reached the end of the list,report failure
    //如果已经到达了链表的末尾，返回失败false
    while(trav!=NULL)
    {
        if(trav->a==val)
        {
            return true;
        }
        trav=trav->next;

    }
    return false;

    //我们并不需要为travelsal pointer创建一个内存空间

}
//插入一个新的值进入链表中
//我们可以快速的查找到链表的开头，但是不知道链表的顺序与节点数量，所以我们一般插入元素进入链表的开头
sllnode* insert (sllnode*head ,int  val)
{

    //a.daynamically allocate space for a new sllnode
    //为所需要的新的节点创建一个空间
    sllnode* newnode=malloc(sizeof(sllnode));
    //b.check to make sure we didn't run out of memory;
    if(newnode==NULL)
    return NULL;
    //c.populate and insert the node at the beginning of linked list
    newnode->a=val;
    newnode->next=head;

    //d.return a pointer to the new head of the linked list
    return newnode;
    //先将新节点的next等于list head，然后再将head等于新的节点

}


//清除所有指针，使用了递归，空间复杂度O(n)
void destroy (sllnode* head)
{

    //a.if you reach a null pointer,stop
    if(head==NULL)
    return;

    //b.delete the rest of the list
    destroy(head->next);
    //c.free the current node
    free(head);
    //先删掉剩余所有指针，再回来把我删掉

}


//迭代版本删除整个链表，空间复杂度O(1)
void unload(sllnode* head)
{
    //for (int i = 0; i < TABLE_SIZE; i++)
    //{
        sllnode* cursor=head;//node *cursor = table[i];

        while (cursor != NULL)
        {
            sllnode *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }


        //table[i] = NULL;
}


//单链表反转双指针
sllnode* reverse(sllnode*head)
{
    sllnode* prev=NULL;
    sllnode* curr=head;
    while(curr!=NULL)
    {
        sllnode* temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    return prev;
}
//单链表反转递归
sllnode* reverse_recursive(sllnode*curr,sllnode* prev)
{
    if(curr==NULL)
    return prev;
    sllnode*temp=curr->next;
    curr->next=prev;
    return reverse_recursive(temp,curr);
}
//调用方式reverse_recursive(head,NULL);
//其实就是上面双指针的理解方式



//删除指定值的节点
sllnode* delete_value(sllnode* head,int val)
{
    //处理头节点是要删除的节点的情况
    while(head!=NULL && head->a==val)
    {
        sllnode* temp=head;
        head=head->next;
        free(temp);
    }

    if(head==NULL)
    {
        return NULL;
    }

    //2.处理非头节点是要删除的节点的情况
    sllnode* curr=head;
    while(curr->next!=NULL)
    {
        if(curr->next->a==val)
        {
            sllnode* tmp=curr->next;
            curr->next=curr->next->next;
            free(tmp);
        }
        else
        {
            curr=curr->next;
        }
    }
    return head;
}

//判断环快慢指针法
bool has_cycle(sllnode* head)
{
    if(head==NULL||head->next==NULL)
    {
        return false;
    }
    sllnode* slow=head;
    sllnode* fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast)
        {
            return true;
        }
    }
    return false;
}
//找出环的起始节点
sllnode* detect_cycle(sllnode* head)
{
    if(head==NULL ||head->next==NULL)
    {
        return NULL;
    }
    sllnode* slow=head;
    sllnode* fast=head;

    while(fast!=NULL &&fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            fast=head;
            while(slow!=fast)
            {
                fast=fast->next;
                slow=slow->next;
            }
            return fast;
        }
    }
    return NULL;

}

//用链表实现栈/队列

