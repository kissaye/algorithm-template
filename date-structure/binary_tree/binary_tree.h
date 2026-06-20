#ifndef BINARY_TREE_H
#define BINARY_TREE_H


#include<stdbool.h>
typedef struct 
{
    int num;
    char name[10];
}student;
typedef struct TreeNode
{
    //int val;
    student data;
    struct TreeNode* left;
    struct TreeNode* right;
}treenode;



#endif // BINARY_TREE_H