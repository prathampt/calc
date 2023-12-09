#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void init(List *l){
    l->isNegative = 0;
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

    if (num->isNegative) printf("-"); // Will print a negative sign if the number is negative... 

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

    init(l);

    if ((c = *(str+i)) == '-'){
        l->isNegative = 1;
        i++;
    }

    while ((c = *(str+i)) == ' '){
        i++; // If the string contains spaces it will handle the spaces...
    }

    while ((c = *(str+i)) != '\0')
    {
        append(l, c - '0');
        i++;
    }
    
    return l;
}

Number add(Number num1, Number num2){

    if (num1->isNegative && num2->isNegative){
        return justAdd(num1, num2, 1);
    }
    else if (num1->isNegative){
        return justSubtract(num2, num1);
    }
    else if (num2->isNegative){
        return justSubtract(num1, num2);
    }
    else {
        return justAdd(num1, num2, 0);
    }

}

Number subtract(Number num1, Number num2){

    if (num1->isNegative && num2->isNegative){
        return justSubtract(num2, num1);
    }
    else if (num1->isNegative){
        return justAdd(num1, num2, 1);
    }
    else if (num2->isNegative){
        return justAdd(num1, num2, 0);
    }
    else {
        return justSubtract(num1, num2);
    }

}

Number multiply(Number num1, Number num2);
Number divide(Number num1, Number num2);

Number justAdd(Number num1, Number num2, short isNegative){
    short carry = 0;
    Node *p = num1->rear, *q = num2->rear;

    List *l = (List *)malloc(sizeof(List));
    init(l);

    if (isNegative) l->isNegative = 1;

    while (p && q)
    {   
        short t = p->data + q->data + carry;
        insertAtBeginning(l, t % 10);
        carry = t / 10;
        p = p->previous;
        q = p->previous;
    }

    while (p)
    {
        insertAtBeginning(l, p->data + carry);
        carry = 0;
        p = p->previous;
    }

    while (q)
    {
        insertAtBeginning(l, q->data + carry);
        carry = 0;
        q = q->previous;
    }
    
    return l;     
}

Number justSubtract(Number num1, Number num2);

Number justMultiply(Number num1, Number num2, short isNegative);
Number justDivide(Number num1, Number num2, short isNegative);