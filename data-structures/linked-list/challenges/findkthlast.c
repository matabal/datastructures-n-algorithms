/*
* Implement an algorithm to find the kth
* to last element of a singly linked list.
* 
* LINKEDLIST_TYPE will assumed to be int
*/


#define LINKEDLIST_TYPE int
#include "../linkedlist.h"
#include <stdio.h> /* printf */


/*--------------SOLUTION--------------*/
int find_kth2last(const linkedlist_t linkedlist, const size_t k)
{
    size_t index = (linkedlist.length) - k;
    node_t * kth2last = get_ith(linkedlist, index);
    return kth2last->data;
}
/*----NOTES----*/
/* 
* Runs on O(n) time where n is the number of nodes
* Consumes O(1) space not counting for linked list
* 
* Note that if linked list length wasn't previously
* known, it could've been found without increasing
* the big-Oh time or space complexity.
*/


/*--------------FOR CLI INTERACTION--------------*/
int main(int argc, char * argv[])
{
    linkedlist_t linkedlist = init_linkedlist();
    if(argc<1)
        return 1;

    int k = atoi(argv[1]);
    int i;
    for(i=2; i<argc; i++)
    {
        push_tail(&linkedlist, atoi(argv[i]));
    }

    int kth2last = find_kth2last(linkedlist, k);
    printf("%dth To Last is: %d\n", k, kth2last);
    return 0;
}
