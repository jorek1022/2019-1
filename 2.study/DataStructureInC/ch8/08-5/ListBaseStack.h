#ifndef __LB_STACK_H__
#define __LB_STACK_H__

#include "BinaryTree2.c"

#define TRUE  1
#define FALSE 0

typedef BTreeNode *Data;

typedef struct _node
{
    Data data;
    struct _node *next;
} Node;

typedef struct _listSatck
{
    Node *head;
} ListStack;

typedef ListStack Stack;

void(StackInit(Stack *pstack));
int SIsEmpty(Stack *pstack);

void SPush(Stack *pstack, Data data);
Data SPop(Stack *pstack);
Data SPeek(Stack *pstack);

#endif