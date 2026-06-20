#include <bits/stdc++.h>
using namespace std;

// ===== 学生结点（按实验要求）=====
typedef struct
{
    int num;
    char name[10];
} student;

// ===== 二叉树结点 =====
typedef struct treenode
{
    student data;
    treenode *left;
    treenode *right;
} treenode;

// ===== 创建结点 =====
treenode *createNode(int num, const char *name)
{
    treenode *node = new treenode();
    node->data.num = num;
    strcpy(node->data.name, name);
    node->left = node->right = NULL;
    return node;
}

// ===== 按层插入（构造完全二叉树，方便截图）=====
treenode *insertNode(treenode *root, int num, const char *name)
{
    treenode *newnode = createNode(num, name);

    if (!root)
        return newnode;

    queue<treenode *> q;
    q.push(root);

    while (!q.empty())
    {
        treenode *cur = q.front();
        q.pop();

        if (!cur->left)
        {
            cur->left = newnode;
            return root;
        }
        else
            q.push(cur->left);

        if (!cur->right)
        {
            cur->right = newnode;
            return root;
        }
        else
            q.push(cur->right);
    }
    return root;
}

// ===== 建树输出（用于截图）=====
void printTreeBFS(treenode *root)
{
    if (!root)
        return;

    cout << "\n[建树层序结构]\n";
    queue<treenode *> q;
    q.push(root);

    while (!q.empty())
    {
        treenode *node = q.front();
        q.pop();

        cout << "(" << node->data.num << "," << node->data.name << ") ";

        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
    }
    cout << "\n";
}

// ===== 前序非递归 =====
void preOrderUnRecur(treenode *head)
{
    cout << "\n[前序非递归遍历]\n";

    if (!head)
        return;

    stack<treenode *> st;
    st.push(head);

    while (!st.empty())
    {
        treenode *node = st.top();
        st.pop();

        cout << "(" << node->data.num << "," << node->data.name << ") ";

        if (node->right)
            st.push(node->right);
        if (node->left)
            st.push(node->left);
    }
    cout << "\n";
}

// ===== 层序遍历 =====
void levelOrder(treenode *head)
{
    cout << "\n[层序遍历]\n";

    if (!head)
        return;

    queue<treenode *> q;
    q.push(head);

    while (!q.empty())
    {
        treenode *node = q.front();
        q.pop();

        cout << "(" << node->data.num << "," << node->data.name << ") ";

        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
    }
    cout << "\n";
}
void printTree(treenode *root, int depth = 0)
{
    if (!root)
        return;

    // 先右子树（让右边在上面）
    printTree(root->right, depth + 1);

    // 当前节点
    for (int i = 0; i < depth; i++)
    {
        cout << "    ";
    }

    cout << "(" << root->data.num << "," << root->data.name << ")\n";

    // 再左子树
    printTree(root->left, depth + 1);
}

// ===== 主函数（带实验菜单）=====
int main()
{
    treenode *root = NULL;

    // ===== 实验数据（固定，方便截图）=====
    student arr[] = {
        {10, "Tom"},
        {5, "Ann"},
        {15, "Bob"},
        {3, "C"},
        {7, "D"},
        {12, "E"},
        {18, "F"},
        {6, "G"},
        {8, "H"}};

    int n = sizeof(arr) / sizeof(arr[0]);

    // ===== 建树 =====
    for (int i = 0; i < n; i++)
    {
        root = insertNode(root, arr[i].num, arr[i].name);
    }

    cout << "==== 二叉树实验 ====\n";

    // 截图1：建树结果
    cout << "\n[树状结构]\n";
    printTree(root);

    // 截图2：前序非递归
    preOrderUnRecur(root);

    // 截图3：层序遍历
    levelOrder(root);

    return 0;
}