#include <stdio.h>
#include "sllist/sllist.h"
#include "stack/stack.h"

/*int main() {
    sllnode* head = NULL;

    // 构造链表 1 -> 2 -> 3 -> 2 -> 1
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 4);
    head = insert(head, 5);
    head = insert(head, 6);
    head = insert(head, 5);
    head = insert(head, 4);
    head = insert(head, 3);
    head = insert(head, 2);
    head = insert(head, 1);

    if (ispalindrome3(head))
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");
   
    head=listpartition2(head,4); 
    sllnode *cur=head;
    while(cur!=NULL)
    {
        printf("%d",cur->a);
        cur=cur->next;
    }
    unload(head);
    return 0;
}
*/

int main()
{
    printf("==== Test 1: Intersect ====\n");

    // 公共部分: 8 -> 9 -> 10
    sllnode *common = create(8);
    common->next = create(9);
    common->next->next = create(10);

    // list1: 1 -> 2 -> 3 -> common
    sllnode *head1 = create(1);
    head1->next = create(2);
    head1->next->next = create(3);
    head1->next->next->next = common;

    // list2: 4 -> 5 -> common
    sllnode *head2 = create(4);
    head2->next = create(5);
    head2->next->next = common;

    sllnode *res = getIntersectSllnode(head1, head2);

    if (res)
        printf("Intersect node value = %d\n", res->a);
    else
        printf("No intersection\n");

    printf("\n==== Test 2: No Intersect ====\n");

    // 新建两个完全独立链表
    sllnode *A = create(1);
    A->next = create(2);
    A->next->next = create(3);

    sllnode *B = create(4);
    B->next = create(5);
    B->next->next = create(6);

    res = getIntersectSllnode(A, B);

    if (res)
        printf("Intersect node value = %d\n", res->a);
    else
        printf("No intersection\n");

    // 释放内存
    unload(head1);   // 会同时释放 common
    unload(A);
    unload(B);

    return 0;
}

