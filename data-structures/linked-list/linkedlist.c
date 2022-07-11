#include <stdio.h>

#define LINKEDLIST_TYPE int
#include "linkedlist.h"


void print_ll(linkedlist_t * linkedlist)
{
    node_t * curr = linkedlist->head;
    while(curr!=NULL)
    {
        printf("%d\n", curr->data);
        curr = curr->next;
    }
}


int main(void)
{
    linkedlist_t linkedlist = init_linkedlist();
    int i;    
    for(i=0; i<4; i++)
    {
        push_tail(&linkedlist, i);
    }

    print_ll(&linkedlist);


    insert_to_ith(&linkedlist, 5, 2);
    printf("\n");
    print_ll(&linkedlist);

    node_t * val;
    val = remove_ith(&linkedlist, 2);
    printf("\n");
    print_ll(&linkedlist);
    printf("\nPREV: %p\n", val->prev);
    printf("\nNEXT: %p\n", val->next);
    printf("\nVAL: %d\n", val->data);

    return 0;
}