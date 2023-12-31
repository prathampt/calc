#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "header.h"
#define MAX 1000000000

void init(List *l){
    l->isNegative = 0;
    l->front = NULL;
    l->rear = NULL;
    return;
}

void append(List *l, unsigned long long int data){
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

void insertAtBeginning(List *l, unsigned long long int data){
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

int removeBeginning(List *l){
    if (!l->front) return INT_MIN;
    Node *p = l->front;

    l->front = l->front->next;
    if (!l->front){
        l->rear = NULL;
        return INT_MIN;
    } 
    l->front->previous = NULL;

    int data = p->data;

    free(p);

    return data;
}

void destroy(List *l){
    while (l->front)
    {
        removeBeginning(l);
    }

    l->rear = NULL;
    l->isNegative = 0;

    return;
    
}

void display(Number num){
    if (!num->front){
        printf("0");
        return;
    }

    if (num->isNegative) printf("-"); // Will print a negative sign if the number is negative... 

    Node * p = num->front;

    printf("%lld", p->data); // This code will print only the first node as it is...
    p = p->next;

    while (p)
    {
        printf("%09lld", p->data); // All the rest nodes will be printed formatted...
        p = p->next;
    }
    return;  
}

short len(Number num){
    if (!num->front) return 0;

    short count = 0;

    Node * p = num->front;

    while (p)
    {
        count++;
        p = p->next;
    }
    
    return count;
}

short greater(Number num1, Number num2){
    short len1 = len(num1), len2 = len(num2);

    if (len1 > len2){
        return 1;
    }
    else if (len2 > len1){
        return 0;
    }
    else {
        Node *p = num1->front, *q = num2->front;

        while (p && q && p->data == q->data){
            p = p->next;
            q = q->next;
        }

        if (q) return 0;
        else if (p && q) return (p->data > q->data)? 1 : 0 ;
        else return 1; // if two numbers are exactly same...
    }

}

Number toNumber(char * str){
    int i = 0;
    char c;
    int len = strlen(str);

    List * l = (List *)malloc(sizeof(List));

    init(l);

    if ((c = *(str+i)) == '-'){
        l->isNegative = 1;
        // *(str+i) = '\0';
        i++;
    }

    while ((c = *(str+i)) == ' '){
        // *(str+i) = '\0';
        i++; // If the string contains spaces it will handle the spaces...
    }

    i = len - 1; // Now traversing in reverse direction...

    while (c != '\0' && i != -1)
    {
        char a[11] = "0000000000"; // This will ensure that even if the loop break earlier, the correct number is read...
        for (int j = 9; j > 0 && c != '\0' && i != -1; j--)
        {
            c = *(str+i);
            i--;
            if (c == '-' || c == ' ') break;
            a[j] = c;
        }

        a[10] = '\0';
        insertAtBeginning(l, (unsigned long long int) atoll(a));
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

Number multiply(Number num1, Number num2){

    if (!num1->front || !num2->front){
        List *l = (List *)malloc(sizeof(List));
        init(l);
        return l;
    }

    if (num1->isNegative && num2->isNegative){
        return justMultiply(num1, num2, 0);
    }
    else if (num1->isNegative || num2->isNegative){
        return justMultiply(num1, num2, 1);
    }
    else {
        return justMultiply(num1, num2, 0);
    }

}

Number justAdd(Number num1, Number num2, short isNegative){
    short carry = 0;
    Node *p = num1->rear, *q = num2->rear;

    List *l = (List *)malloc(sizeof(List));
    init(l);

    if (isNegative) l->isNegative = 1;

    while (p && q)
    {   
        unsigned long long int t = p->data + q->data + carry;
        insertAtBeginning(l, t % MAX);
        carry = t / MAX;
        p = p->previous;
        q = q->previous;
    }

    while (p)
    {
        insertAtBeginning(l, (p->data + carry) % MAX);
        carry = (p->data + carry) / MAX;
        p = p->previous;
    }

    while (q)
    {
        insertAtBeginning(l, (q->data + carry) % MAX);
        carry = (q->data + carry) / MAX;
        q = q->previous;
    }

    if (carry){
        insertAtBeginning(l, carry);
    }
    
    return l;     
}

Number justSubtract(Number num1, Number num2){
    int borrow = 0;
    Node *p, *q;
    
    List *l = (List *)malloc(sizeof(List));
    init(l);

    if (greater(num1, num2)){
        l->isNegative = 0;
        p = num1->rear; 
        q = num2->rear;
    }
    else {
        l->isNegative = 1;
        p = num2->rear;
        q = num1->rear;
    }

    while (p && q)
    {   
        long long int t = (long long int) p->data - q->data - borrow;

        if (t < 0){
            t += MAX;
            borrow = 1;
        }
        else {
            borrow = 0;
        }

        insertAtBeginning(l, (unsigned long long int) t % MAX );
        
        p = p->previous;
        q = q->previous;
    }

    while (p)
    {
        insertAtBeginning(l, p->data - borrow);
        borrow = 0;
        p = p->previous;
    }

    while (q)
    {
        insertAtBeginning(l, q->data - borrow);
        borrow = 0;
        q = q->previous;
    }

    Node *r = l->front;

    while (r && r->data == 0){
        r = r->next;
        removeBeginning(l);
    }
    
    
    return l;    
    
}

Number justMultiply(Number num1, Number num2, short isNegative){
    long long int carry = 0;
    int count = 0;
    Node *p = num1->rear, *q = num2->rear;

    List *l = (List *)malloc(sizeof(List));
    init(l);

    List *temp = (List *)malloc(sizeof(List));
    init(temp);

    while (q)
    {
        p = num1->rear;

        while (p)
        {
            int qData = q->data;

            unsigned long long int t = (unsigned long long int) p->data * qData + carry;
            insertAtBeginning(temp, t % MAX);
            carry = t / MAX;
            p = p->previous;
        }
        if (carry != 0) insertAtBeginning(temp, carry);

        for (int i = 0; i < count; i++)
        {
            append(temp, 0);
        }

        carry = 0;
        
        l = add(l, temp);

        destroy(temp);
        init(temp);

        q = q->previous;
        count++;
    }

    if (isNegative) l->isNegative = 1;
    
    return l;    
}