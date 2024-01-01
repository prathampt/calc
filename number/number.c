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
    l->frontDec = NULL;
    l->rearDec = NULL;
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

void appendDec(List *l, unsigned long long int data){
    Node * nn = (Node *) malloc(sizeof(Node));

    if (!nn) return;

    nn->data = data;
    nn->next = NULL;
    nn->previous = NULL;

    if (!l->frontDec) {
        l->frontDec = nn;
        l->rearDec = nn;
    }
    else {
        nn->previous = l->rearDec;
        l->rearDec->next = nn;
        l->rearDec = nn;
    }

    return;
}

void insertAtBeginningDec(List *l, unsigned long long int data){
    Node * nn = (Node *) malloc(sizeof(Node));

    if (!nn) return;

    nn->data = data;
    nn->next = NULL;
    nn->previous = NULL;

    if (!l->frontDec) {
        l->frontDec = nn;
        l->rearDec = nn;
    }
    else {
        nn->next = l->frontDec;
        l->frontDec->previous = nn;
        l->frontDec = nn;
    }

    return;
}

int removeEndDec(List *l){
    if (!l->rearDec) return INT_MIN;
    Node *p = l->rearDec;

    l->rearDec = l->rearDec->previous;

    if (!l->rearDec){
        l->frontDec = NULL;
        return INT_MIN;
    }

    l->rearDec->next = NULL;

    int data = p->data;

    free(p);

    return data;
}

void destroyDec(List *l){
    while (l->rearDec)
    {
        removeEndDec(l);
    }

    l->frontDec = NULL;
    l->isNegative = 0;

    return;
}

void display(Number num){

    if (num->isNegative) printf("-"); // Will print a negative sign if the number is negative... 

    if (!num->front){
        printf("0");
    } else {

        Node * p = num->front;

        printf("%lld", p->data); // This code will print only the first node as it is...
        p = p->next;

        while (p)
        {
            printf("%09lld", p->data); // All the rest nodes will be printed formatted...
            p = p->next;
        }

    }

    if (num->frontDec){
        printf(".");

        Node * p = num->frontDec;

        while (p) {
            printf("%lld", p->data);
            p = p->next;
        }
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

short lenDec(Number num){
    if (!num->frontDec) return 0;

    short count = 0;

    Node * p = num->frontDec;

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

        if (p && q) return (p->data > q->data)? 1 : 0 ;
    }

    // if two numbers are exactly same before decimal point...

    Node * x = num1->frontDec, * y = num2->frontDec;

    while (x && y && x->data == y->data){
        x = x->next;
        y = y->next;
    }

    if (x && y) return (x->data > y->data)? 1 : 0;
    else if (x) return 1;
    else if (y) return 0;
    else return 1;

}

Number toNumber(char * str){
    int i = 0;
    char c;
    int count = strlen(str);

    int len = 0;
    while ((c = *(str+len)) != '.' && c != '\0'){
        len++;
    }
    
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
        char a[10] = "000000000"; // This will ensure that even if the loop break earlier, the correct number is read...
        for (int j = 8; j >= 0 && c != '\0' && i != -1; j--)
        {
            c = *(str+i);
            i--;
            if (c == '-' || c == ' ') break;
            a[j] = c;
        }

        a[9] = '\0';
        insertAtBeginning(l, (unsigned long long int) atoll(a));
    }

    c = *(str+len+1);
    i = len + 1;

    while (c != '\0' && i <= count - 1)
    {
        char a[10] = "000000000"; // This will ensure that even if the loop break earlier, the correct number is read...
        for (int j = 0; j < 9 && c != '\0' && i <= count - 1; j++)
        {
            c = *(str + i);
            i++;
            a[j] = c;
        }

        a[9] = '\0';
        appendDec(l, (unsigned long long int) atoll(a));
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

    if ((!num1->front && !num1->frontDec) || (!num2->front && !num2->frontDec)){
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
    short carry = 0, carryDec = 0;
    Node *p = num1->rear, *q = num2->rear;
    Node *x = num1->frontDec, *y = num2->frontDec;

    List *l = (List *)malloc(sizeof(List));
    init(l);

    if (isNegative) l->isNegative = 1;

    // First adding digits after decimal point...

    if (x && y) {
        unsigned long long int tDec = x->data + y->data;
        appendDec(l, tDec % MAX);
        carry = tDec / MAX;
        x = x->next;
        y = y->next;
    }

    while (x && y)
    {
        unsigned long long int tDec = x->data + y->data;
        appendDec(l, tDec % MAX);
        carryDec = tDec / MAX;
        x = x->next;
        y = y->next;

        if (carryDec){
            l->rearDec->previous->data += 1;
        }
    }

    while (x)
    {
        appendDec(l, x->data);
        x = x->next;
    }

    while (y)
    {
        appendDec(l, y->data);
        y = y->next;
    }

    // Now adding digits before decimal points...
    
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

// Changes implemented till here for new updated data structure...
// Changes below are yet to be implemented...

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