#include<cstdio>
#include<cstdlib>
#include<stack>
#include"binary_tree.h"
using namespace std;


//创建新节点
treenode* Binary_treenodeCreate(int val)
{
    treenode* newnode=new treenode();
    if(newnode==NULL)
    {
        return NULL;
    }
    newnode->val=val;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

//插入新节点
treenode* Binary_treenodeInsert(treenode* root,int val)
{
    if(root==NULL)
    {
        return Binary_treenodeCreate(val);//如果树为空，直接创建新节点作为根
    }
    treenode* queue[1000];//利用数组模拟队列
    int front =0,rear=0;//队列的前后指针
    queue[rear++]=root;
    while(front<rear)
    {
        treenode* node=queue[front++];

        if(node->left==NULL)
        {
            node->left=Binary_treenodeCreate(val);
            return root;
        }
        else
        {
            queue[rear++]=node->left;
        }
        if(node->right==NULL)
        {
            node->right=Binary_treenodeCreate(val);
            return root;
        }
        else
        {
            queue[rear++]=node->right;
        }
    }
    return root;
}

//递归序中序遍历
void inOrderRecur(treenode* head)
{
    if(head==NULL)
    {
        return;
    }
    inOrderRecur(head->left);
    printf("%d ", head->val);
    inOrderRecur(head->right);

}
//完成先序遍历不用递归
/*1）每次从栈中弹出一个节点
2）打印处理节点
3）若该节点有孩子，先右再左压入栈中（也可以用队列，队列的话就是先左再右边
4）重复过程
*/
void preOrderUnRecur(treenode* head)
{
    if(head==NULL)
    {
        return;
    }
    
    stack<treenode*> stk;
    stk.push(head);
    
    while(!stk.empty())
    {
        treenode* node=stk.top();
        stk.pop();
        printf("%d ", node->val);
        
        if(node->right!=NULL)
        {
            stk.push(node->right);
        }
        if(node->left!=NULL)
        {
            stk.push(node->left);
        }
    }
}