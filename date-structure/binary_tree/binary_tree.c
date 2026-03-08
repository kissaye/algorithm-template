#include<stdio.h>
#include<stdlib.h>
#include"binary_tree.h"

//创建新节点
treenode* Binary_treenodeCreate(int val)
{
    treenode* newnode=malloc(sizeof(treenode));
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