/*-------------DESCRIPTION--------------*/
/*
* Write code that removes duplicates from an unsorted linked list.
* LINKEDLIST_TYPE is given as int
* Provide a solution with and without a temporary buffer.
*/



#define LINKEDLIST_TYPE int
#include "../linkedlist.h"
#include <stdlib.h> /* calloc, free, abs, atoi */
#include <stdio.h> /* printf */


/*--------------SOLUTION W/ TEMP. BUFFER--------------*/
int find_abs_max(const linkedlist_t linkedlist)
{
    unsigned int max = 0;
    node_t * curr = linkedlist.head;
    while(curr!=NULL)
    {
        if(abs(curr->data) > max)
            max = abs(curr->data);

        curr = curr->next;
    }
    return max;
}


int num2index(const int num, size_t arrlength)
{
    return (int)(((arrlength-1)/2)+num);
}


int index2num(const int index, const size_t arrlength)
{
    return (int)(index-((arrlength-1)/2));
}


void removedups_wbuff(linkedlist_t * linkedlist)
{
    size_t len = (2*find_abs_max(*linkedlist))+1;

    int * exists = (int*)calloc(len, sizeof(int));
    node_t * curr = linkedlist->head;
    node_t * next;
    while(curr!=NULL)
    {
        next = curr->next;
        if(exists[num2index(curr->data, len)])
        {
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            free(curr);
            linkedlist->length--;
        }
        else
            exists[num2index(curr->data, len)] = 1;

        curr = next;
    }

    free(exists);
}
/*----NOTES----*/
/* 
* Runs on O(n) time where n is the number of nodes
* Consumes O(n) space where n is the number of nodes
*/


/*--------------SOLUTION W/O TEMP. BUFFER--------------*/
void removedups_wobuff(linkedlist_t * linkedlist)
{
    node_t * outer = linkedlist->head;
    node_t * inner, * next;

    while(outer!=NULL)
    {
        inner = outer->next;
        while(inner!=NULL)
        {
            next = inner->next;
            if(inner->data == outer->data)
            {
                inner->prev->next = inner->next;
                inner->next->prev = inner->prev;
                free(inner);
                linkedlist->length--;
            }
            inner = next;

        }
        outer = outer->next;
        
    }
}
/*----NOTES----*/
/* 
* Runs on O(n^2) time where n is the number of nodes
* Consumes O(1) space not counting the linked list
*/




void print_ll(const linkedlist_t linkedlist)
{
    node_t * curr = linkedlist.head;

    printf("\n");
    while(curr!=NULL)
    {
        printf(" %d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}


int main(int argc, char * argv[])
{
    
    int i;
    linkedlist_t linkedlist = init_linkedlist();
    for(i=1; i<argc; i++)
    {
        push_tail(&linkedlist, atoi(argv[i]));
    }

    printf("Duplicates removed: ");
    removedups_wbuff(&linkedlist);
    print_ll(linkedlist);

    return 0;
}