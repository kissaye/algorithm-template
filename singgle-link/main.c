#include<stdio.h>
#include"sllist.h"

int main(void)
{
    sllnode* head=NULL;
    head=insert(head,10);
    head=insert(head,16);
    head=insert(head,18);

    printf("Find 16:%d\n",find(head,16));

    head=reverse(head);
    destroy(head);
    return 0;
    
}
