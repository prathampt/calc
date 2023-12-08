#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "header.h"

void init(List *l){
    l->front = NULL;
    l->rear = NULL;
    return;
}

void insertAtBeginning(List *l, unsigned int data){
    Node * nn = (Node *) malloc(sizeof(Node));

    if (!nn) return;

    nn->data = data;
    nn->next = NULL;
    nn->previous = NULL;

    if (!l->front) {
        l->front = nn;
        l->rear = nn;
    }
    else {
        nn->next = l->front;
        l->front->previous = nn;
        l->front = nn;
    }

    return;
}

void display(List l){
    if (!l.front) return;

    Node * p = l.front;
    while (p)
    {
        printf("%d", p->data);
        p = p->next;
    }
    return;  
}

Number toNumber(char * str);