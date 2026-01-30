#include<stdio.h>
//双链表
//单链表不方便只知道该节点本身指针情况下删除，所以需要创建双链表，删得更方便
define VALUE int;

typedef struct dllist
{
    VALUE val;
    struct dllist* prev;
    struct dllist* next;
}
dllnode;
//创建一个不存在的双向链表
//搜寻链表查找一个元素
//插入一个新的节点
//删除其中某一个数据
//删除整个链表




//插入到原来链表头部
dllnode* insert (dllnode* head,VALUE val)
{

    //a.dynamically allocate space for a new dllnode
    dllnode* newnode=malloc(sizeof(dllnode));

    //b.check to make sure we didn't run out of memory
    if(newnode==NULL)
    {
        return head;
    }
    //c.populate and insert the node at the beginning of the linked list
    newnode->val=val;
    newnode->prev=NULL;
    newnode->next=head;

    //d.fix the prev pointer of the old head of the linked
    if(head!=NULL)
    {
        head->prev=newnode;
    }
    //e.return a pointer to the new head of the linked list
    return newnode;

   //先填装好新节点的指针，在修改原始头部指针
}

//删除某一个指针
void delete(dllnode* target)
{
    /*
    a.fix the pointers of the surrounding nodes to "skip over"target
    改变目标指针周围的量使得他们跳过该指针
    b.free target
    最后释放目标指针的内存
    */
   //移动两个量，加上释放内存一共三个步骤
}

