#include <stdlib.h> /* size_t, free, malloc */

#ifndef LINKEDLIST_TYPE
#define LINKEDLIST_TYPE int
#endif


#ifndef LINKEDLIST_H
#define LINKEDLIST_H


typedef struct node
{
    struct node * prev;
    LINKEDLIST_TYPE data;
    struct node * next;
} node_t;


struct linkedlist
{
    node_t * head;
    node_t * tail;
    size_t length;
};
typedef struct linkedlist linkedlist_t;


linkedlist_t init_linkedlist();
node_t * new_node(node_t * prev, node_t * next, LINKEDLIST_TYPE data);
void push_tail(linkedlist_t * linkedlist, LINKEDLIST_TYPE data);
void push_head(linkedlist_t * linkedlist, LINKEDLIST_TYPE data);
LINKEDLIST_TYPE pop_tail(linkedlist_t * linkedlist);
LINKEDLIST_TYPE pop_head(linkedlist_t * linkedlist);
node_t * get_ith(const linkedlist_t linkedlist, const size_t i);
node_t * remove_ith(linkedlist_t * linkedlist, const size_t i);
node_t * insert_to_ith(linkedlist_t * linkedlist, LINKEDLIST_TYPE data, const size_t i);


linkedlist_t init_linkedlist()
{
    linkedlist_t linkedlist;
    linkedlist.head = NULL;
    linkedlist.tail = linkedlist.head;
    linkedlist.length = 0;
    return linkedlist;
}

node_t * new_node(node_t * prev, node_t * next, LINKEDLIST_TYPE data)
{
    node_t * node = (node_t*)malloc(sizeof(node_t));
    node->data = data;
    node->prev = prev;
    node->next = next;
    return node;
}


void push_head(linkedlist_t * linkedlist, LINKEDLIST_TYPE data)
{
    node_t * nodeP = new_node(NULL, NULL, data);

    if(linkedlist->head)
    {
        node_t * currHead = linkedlist->head;
        nodeP->next = currHead;
        currHead->prev = nodeP;
    }
    else
    {
        nodeP->next = NULL;
        linkedlist->tail = nodeP;
    }

    linkedlist->head = nodeP;
    linkedlist->length++;
}


void push_tail(linkedlist_t * linkedlist, LINKEDLIST_TYPE data)
{
    node_t * nodeP = new_node(NULL, NULL, data);

    if(linkedlist->tail)
    {
        node_t * currTail = linkedlist->tail;
        nodeP->prev = currTail;
        currTail->next = nodeP;
    }
    else
    {
        nodeP->prev = NULL;
        linkedlist->head = nodeP;
    }

    linkedlist->tail = nodeP;
    linkedlist->length++;
}


LINKEDLIST_TYPE pop_tail(linkedlist_t * linkedlist)
{
    node_t * currTail = linkedlist->tail;
    linkedlist->tail = currTail->prev;
    currTail->prev->next = NULL;

    LINKEDLIST_TYPE data = currTail->data;
    free(currTail);
    linkedlist->length--;
    return data;
}


LINKEDLIST_TYPE pop_head(linkedlist_t * linkedlist)
{
    node_t * currHead = linkedlist->head;
    linkedlist->head = currHead->next;
    currHead->next->prev = NULL;

    LINKEDLIST_TYPE data = currHead->data;
    free(currHead);
    linkedlist->length--;
    return data;
}


node_t * get_ith(const linkedlist_t linkedlist, const size_t i)
{
    int s = 0;
    node_t * curr = linkedlist.head;
    while(s<i && curr!=NULL)
    {
        curr = curr->next;
        s++;
    }

    return curr;
}


node_t * remove_ith(linkedlist_t * linkedlist, const size_t i)
{
    node_t * node = get_ith(*linkedlist, i);
    if(!node)
        return NULL;

    node->prev->next = node->next;
    node->next->prev = node->prev;
    node->next = NULL;
    node->prev = NULL;

    linkedlist->length--;

    return node;
}


node_t * insert_to_ith(linkedlist_t * linkedlist, LINKEDLIST_TYPE data, const size_t i)
{
    node_t * node = get_ith(*linkedlist, i);
    if(!node)
        return NULL;

    node_t * newNodeP = new_node(node->prev, node, data);

    node->prev->next = newNodeP;
    node->prev = newNodeP;
    linkedlist->length++;

    return newNodeP;
}


#endif