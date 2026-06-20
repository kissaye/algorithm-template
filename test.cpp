#include <bits/stdc++.h>
using namespace std;

// =============================
// 学生结构体
// =============================
struct Student
{
    int num;
    float Chinese;
    int Math;
    float English;
    float sum;
};

// =============================
// BST节点
// =============================
struct Node
{
    Student data;
    Node *left;
    Node *right;
};

Node *BTroot = NULL;

// =============================
// ================= BST部分 =================
// =============================

// 创建节点
Node *createNode(Student s)
{
    Node *node = new Node;
    node->data = s;
    node->left = node->right = NULL;
    return node;
}

// BST插入（按总分sum）
Node *insertBST(Node *root, Student s)
{
    if (root == NULL)
        return createNode(s);

    if (s.sum < root->data.sum)
        root->left = insertBST(root->left, s);
    else
        root->right = insertBST(root->right, s);

    return root;
}

// 中序遍历（升序输出）
void inorder(Node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data.num << "\t"
         << root->data.Chinese << "\t"
         << root->data.Math << "\t"
         << root->data.English << "\t"
         << root->data.sum << endl;
    inorder(root->right);
}

// 查找
bool searchBST(Node *root, float key, Student &res)
{
    if (root == NULL)
        return false;

    if (root->data.sum == key)
    {
        res = root->data;
        return true;
    }
    else if (key < root->data.sum)
        return searchBST(root->left, key, res);
    else
        return searchBST(root->right, key, res);
}

// 最大值
Student findMax(Node *root)
{
    while (root->right)
        root = root->right;
    return root->data;
}

// 最小值
Student findMin(Node *root)
{
    while (root->left)
        root = root->left;
    return root->data;
}

// 删除节点（标准BST删除）
Node *deleteBST(Node *root, float key)
{
    if (root == NULL)
        return NULL;

    if (key < root->data.sum)
        root->left = deleteBST(root->left, key);
    else if (key > root->data.sum)
        root->right = deleteBST(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            Node *t = root->right;
            delete root;
            return t;
        }
        else if (root->right == NULL)
        {
            Node *t = root->left;
            delete root;
            return t;
        }
        else
        {
            Node *t = root->left;
            while (t->right)
                t = t->right;
            root->data = t->data;
            root->left = deleteBST(root->left, t->data.sum);
        }
    }
    return root;
}

// =============================
// ================= 堆排序部分 =================
// =============================

// =====================================================
// 【1】你的版本：插入式建堆（O(N log N)）
// =====================================================

// 上浮（heapInsert）
void heapInsert(Student arr[], int index)
{
    while (index > 0 &&
           arr[index].sum > arr[(index - 1) / 2].sum)
    {
        swap(arr[index], arr[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

// 插入式建堆
void buildHeap_yours(Student arr[], int n)
{
    for (int i = 0; i < n; i++)
        heapInsert(arr, i);
}

// =====================================================
// 【2】老师版本：标准建堆（O(N)）
// =====================================================

// 下沉调整
void heapify(Student arr[], int index, int heapsize)
{
    int left = index * 2 + 1;

    while (left < heapsize)
    {
        int largest = left;

        if (left + 1 < heapsize &&
            arr[left + 1].sum > arr[left].sum)
            largest = left + 1;

        if (arr[largest].sum <= arr[index].sum)
            break;

        swap(arr[largest], arr[index]);
        index = largest;
        left = index * 2 + 1;
    }
}

// 标准建堆（老师推荐）
void buildHeap_teacher(Student arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, i, n);
}

// =============================
// 堆排序统一接口（可切换）
// =============================
void heapSort(Student arr[], int n, int mode)
{
    /*
        mode = 1 → 老师版本（O(N)建堆）
        mode = 2 → 你的版本（O(N log N)建堆）
    */

    if (mode == 1)
        buildHeap_teacher(arr, n);
    else
        buildHeap_yours(arr, n);

    int heapsize = n;

    while (heapsize > 0)
    {
        swap(arr[0], arr[--heapsize]);
        heapify(arr, 0, heapsize);
    }
}

// =============================
// 初始化数据
// =============================
void initData(Student heap[], int &HeapSize)
{
    int num[9] = {20010001, 20010002, 20010003, 20010004, 20010005, 20010006, 20010007, 20010008, 20010009};
    float Chinese[9] = {85.0, 92.5, 95.0, 85.0, 96.0, 72.0, 65.0, 88.0, 96.5};
    int Math[9] = {88, 91, 98, 87, 93, 76, 53, 94, 83};
    float English[9] = {97.0, 95.0, 99.0, 96.5, 100, 70.5, 53.0, 90.5, 65.0};
    float sum[9] = {270.0, 278.5, 292.0, 268.5, 289.0, 218.5, 171.0, 272.5, 244.5};

    HeapSize = 9;

    for (int i = 0; i < 9; i++)
    {
        heap[i].num = num[i];
        heap[i].Chinese = Chinese[i];
        heap[i].Math = Math[i];
        heap[i].English = English[i];
        heap[i].sum = sum[i];

        BTroot = insertBST(BTroot, heap[i]);
    }
}

// =============================
// 主函数（实验演示）
// =============================
int main()
{
    Student heap[100];
    int HeapSize;

    initData(heap, HeapSize);

    // ================= BST输出 =================
    cout << "====== BST中序遍历（升序）======" << endl;
    inorder(BTroot);

    cout << "\n====== 最大值 ======" << endl;
    Student maxv = findMax(BTroot);
    cout << maxv.num << " " << maxv.sum << endl;

    cout << "\n====== 最小值 ======" << endl;
    Student minv = findMin(BTroot);
    cout << minv.num << " " << minv.sum << endl;

    // ================= 堆排序 =================
    cout << "\n====== 堆排序======" << endl;
    heapSort(heap, HeapSize, 1);

    for (int i = 0; i < HeapSize; i++)
    {
        cout << heap[i].num << "\t"
             << heap[i].Chinese << "\t"
             << heap[i].Math << "\t"
             << heap[i].English << "\t"
             << heap[i].sum << endl;
    }

    return 0;
}