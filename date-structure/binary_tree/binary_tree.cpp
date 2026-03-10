#include<cstdio>
#include<bits/stdc++.h>
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
    vector<int> result;
    stk.push(head);
    
    while(!stk.empty())
    {
        treenode* node=stk.top();
        stk.pop();
        //printf("%d ", node->val);
        result.push_back(node->val);

        
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

//迭代法中序遍历
void inOrderUnRecur(treenode* head)
{
    vector<int> result;
    stack<treenode*> stk;
    treenode* cur=head;
    while(cur!=NULL || !stk.empty())
    {
        if(cur!=NULL)//指针用来访问节点，先访问最底层
        {
            stk.push(cur);//将访问到的节点压入栈
            cur=cur->left;   //左
        }
        else//该子树到底了，开始处理数据
        {
            cur=stk.top();    //从栈里 弹出数据，就是要放进result数组
            stk.pop();
            result.push_back(cur->val);    //中
            cur=cur->right;                //右
        }
    }
    return;
}

//迭代法后序遍历
void posOrderUnRecur(treenode* head)
{
    stack<treenode*> stk;
    vector<int> result;
    if(head==NULL)
    {
        return;
    }
    stk.push(head);
    while(!stk.empty())
    {
        treenode* node=stk.top();
        stk.pop();
        result.push_back(node->val);
        if(node->left) stk.push(node->left);
        if(node->right) stk.push(node->right);  
    }
    reverse(result.begin(),result.end());
    return;
}


//二叉树统一风格迭代法

//二叉树的层序遍历，广度优先搜索bfs
void LevelOrder(treenode* head)
{
    queue<treenode*> que;
    if(head!=NULL)
    {
        que.push(head);
    }
    vector<vector<int>> result;
    while(!que.empty())
    {
        int size=que.size();
        vector<int> vec;
        while(size--)
        {
            treenode* node=que.front();
            que.pop();
            vec.push_back(node->val);
            if(node->left) que.push(node->left);
            if(node->right) que.push(node->right);
         }
         result.push_back(vec);
    }
    return;
}

//二叉树的翻转
//递归(前序)
treenode* inverTreePreRecur(treenode* head)
{
    if(head==NULL)
    return head;
    swap(head->left,head->right);
    inverTreePreRecur(head->left);
    inverTreePreRecur(head->right);
    return head;

}
//递归中序。交换中间节点的两个子树后，第三次递归序要处理的是原来的右节点，也就是后来的左节点
treenode* invertTreeInRecur(treenode* head)
{
    if(head==NULL)
    {
        return head;

    }
    invertTreeInRecur(head->left);
    swap(head->left,head->right);
    invertTreeInRecur(head->left);//注意这边是左
    return head;
}
//迭代（前序）
treenode* inyerTreeUnRecur(treenode* head)
{
    if(head==NULL)
    return head;
    stack<treenode*> stk;
    stk.push(head);
    while(!stk.empty())
    {
        treenode* node=stk.top();
        stk.pop();
        swap(node->left,node->right);
        if(node->left) stk.push(node->left);
        if(node->right) stk.push(node->right);
    }
    return head;
}
//层序遍历实现
treenode* invertTreelevelOrder(treenode* head)
{
    queue<treenode*> que;
    if(head!=NULL) que.push(head);
    while(!que.empty())
    {
        int size=que.size();
        for(int i=0;i<size;i++)
        {
            treenode* node=que.front();
            que.pop();
            swap(node->left,node->right);
            if(node->left) que.push(node->left);
            if(node->right) que.push(node->right);
        }
    }
    return head;
}





//对称二叉树，给定一个二叉树，检查他是否是镜像对称的
bool compare(treenode* left,treenode* right)
{
    if(left==NULL && right !=NULL)
    {
        return false;
    }
    else if(left!=NULL &&right ==NULL)
    {
        return false;
    }
    else if(left==NULL && right==NULL)
    {
        return true;
    }
    //排除了空节点，再排除数值不同的情况
    else if(left->val!=right->val)
    {
        return false;
    }
    

    //存在数据，且数据相同时，做下一层递归
    bool outside=compare(left->left,right->right);
    bool inside=compare(left->right,right->left);
    bool isSame=outside &&inside;
    return isSame;
    //上面这段可以直接改为
    /*else return compare(left->left,right->right)&&compare(left->right,right->left);*/
}
bool isSymmetric(treenode* head)
{
    if(head==NULL)
    {
        return true;
    }
    return compare(head->left,head->right);
}

//迭代法（队列与栈都ok，完全对等替换，与bfs不类似）
bool isSymmetricUnRecur(treenode* head)
{
    if(head==NULL)
    {
        return true;
    }
    queue<treenode*> que;
    que.push(head->left);
    que.push(head->right);
    while(!que.empty())
    {
        treenode* leftnode=que.front();
        que.pop();
        treenode* rightnode=que.front();
        que.pop();
        if(!leftnode &&!rightnode)//左右节点为空，对称
        {
            continue;
        }
        //左右节点一个为空或不等
        if((!leftnode||!rightnode||(leftnode->val!=rightnode->val)))
        {
            return false;
        }
        que.push(leftnode->left);
        que.push(rightnode->right);
        que.push(leftnode->right);
        que.push(rightnode->left);
    }
    return true;
}