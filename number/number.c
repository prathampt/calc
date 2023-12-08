#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void init(List *l){
    l->front = NULL;
    l->rear = NULL;
    return;
}

void append(List *l, short data){
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
        nn->previous = l->rear;
        l->rear->next = nn;
        l->rear = nn;
    }

    return;
}

void insertAtBeginning(List *l, short data){
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

void display(Number num){
    if (!num->front) return;

    Node * p = num->front;
    while (p)
    {
        printf("%d", p->data);
        p = p->next;
    }
    return;  
}

Number toNumber(char * str){
    int i = 0;
    char c;

    List * l = (List *)malloc(sizeof(List));

    while ((c = *(str+i)) != '\0')
    {
        append(l, c - '0');
        i++;
    }
    
    return l;
}