#include <stdio.h>
#include "sllist/sllist.h"
#include "stack/stack.h"

int main() {
    sllnode* head = NULL;

    // 构造链表 1 -> 2 -> 3 -> 2 -> 1
    head = insert(head, 1);
    head = insert(head, 3);
    head = insert(head, 3);
    head = insert(head, 2);
    head = insert(head, 1);

    if (ispalindrome2(head))
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");

    unload(head);
    return 0;
}
