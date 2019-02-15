#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

void DequeInit(Deque *pdeq)
{
    pdeq->head = NULL;
    pdeq->tail = NULL;
}

int DQIsEmpty(Deque *pdeq)
{
    if(pdeq->head == NULL)
        return TRUE;
    else
    {
        return FALSE;
    }
}


void DQAddFirst(Deque *pdeq, Data data)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    newNode->next = pdeq->head;

    if(DQIsEmpty(pdeq))
        pdeq->tail = newNode;
    else
    {
        pdeq->head->prev = newNode;
    }
    newNode->prev = NULL;
    pdeq->head = newNode;
}

void DQAddLast(Deque *pdeq, Data data)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    newNode->prev = pdeq->tail;

    
}