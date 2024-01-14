#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "header.h"
#define MAX 1000000000

void init(List *l)
{
    l->isNegative = 0;
    l->front = NULL;
    l->rear = NULL;
    l->frontDec = NULL;
    l->rearDec = NULL;
    return;
}

void append(List *l, unsigned long long int data)
{
    Node *nn = (Node *)malloc(sizeof(Node));

    if (!nn)
        return;

    nn->data = data;
    nn->next = NULL;
    nn->previous = NULL;

    if (!l->front)
    {
        l->front = nn;
        l->rear = nn;
    }
    else
    {
        nn->previous = l->rear;
        l->rear->next = nn;
        l->rear = nn;
    }

    return;
}

void insertAtBeginning(List *l, unsigned long long int data)
{
    Node *nn = (Node *)malloc(sizeof(Node));

    if (!nn)
        return;

    nn->data = data;
    nn->next = NULL;
    nn->previous = NULL;

    if (!l->front)
    {
        l->front = nn;
        l->rear = nn;
    }
    else
    {
        nn->next = l->front;
        l->front->previous = nn;
        l->front = nn;
    }

    return;
}

int removeBeginning(List *l)
{
    if (!l->front)
        return INT_MIN;
    Node *p = l->front;

    l->front = l->front->next;
    if (!l->front)
    {
        l->rear = NULL;
        return INT_MIN;
    }
    l->front->previous = NULL;

    int data = p->data;

    free(p);

    return data;
}

void destroy(List *l)
{
    while (l->front)
    {
        removeBeginning(l);
    }

    l->rear = NULL;
    l->isNegative = 0;

    return;
}

void appendDec(List *l, unsigned long long int data)
{
    Node *nn = (Node *)malloc(sizeof(Node));

    if (!nn)
        return;

    nn->data = data;
    nn->next = NULL;
    nn->previous = NULL;

    if (!l->frontDec)
    {
        l->frontDec = nn;
        l->rearDec = nn;
    }
    else
    {
        nn->previous = l->rearDec;
        l->rearDec->next = nn;
        l->rearDec = nn;
    }

    return;
}

void insertAtBeginningDec(List *l, unsigned long long int data)
{
    Node *nn = (Node *)malloc(sizeof(Node));

    if (!nn)
        return;

    nn->data = data;
    nn->next = NULL;
    nn->previous = NULL;

    if (!l->frontDec)
    {
        l->frontDec = nn;
        l->rearDec = nn;
    }
    else
    {
        nn->next = l->frontDec;
        l->frontDec->previous = nn;
        l->frontDec = nn;
    }

    return;
}

int removeEndDec(List *l)
{
    if (!l->rearDec)
        return INT_MIN;
    Node *p = l->rearDec;

    l->rearDec = l->rearDec->previous;

    if (!l->rearDec)
    {
        l->frontDec = NULL;
        return INT_MIN;
    }

    l->rearDec->next = NULL;

    int data = p->data;

    free(p);

    return data;
}

void destroyDec(List *l)
{
    while (l->rearDec)
    {
        removeEndDec(l);
    }

    l->frontDec = NULL;
    l->isNegative = 0;

    return;
}

void display(Number num)
{

    if (num->isNegative)
        printf("-"); // Will print a negative sign if the number is negative...

    if (!num->front)
    {
        printf("0");
    }
    else
    {

        Node *p = num->front;

        printf("%lld ", p->data); // This code will print only the first node as it is...
        p = p->next;

        while (p)
        {
            printf("%09lld ", p->data); // All the rest nodes will be printed formatted...
            p = p->next;
        }
    }

    if (num->frontDec)
    {
        printf(".");

        Node *p = num->frontDec;

        while (p->next)
        {
            printf("%09lld", p->data);
            p = p->next;
        }

        unsigned long long int z = p->data;

        printf("%09lld", p->data);

        while (z % 10 == 0)
        {
            printf("\b");
            z /= 10;
        }

        p = p->next;
    }
    printf("\n");

    return;
}

short len(Number num)
{
    if (!num->front)
        return 0;

    short count = 0;

    Node *p = num->front;

    while (p)
    {
        count++;
        p = p->next;
    }

    return count;
}

short lenDec(Number num)
{
    if (!num->frontDec)
        return 0;

    short count = 0;

    Node *p = num->frontDec;

    while (p)
    {
        count++;
        p = p->next;
    }

    return count;
}

short greater(Number num1, Number num2) // returns 1 when num1 > num2
{
    short len1 = len(num1), len2 = len(num2);

    if (len1 > len2)
    {
        return 1;
    }
    else if (len2 > len1)
    {
        return 0;
    }
    else
    {
        Node *p = num1->front, *q = num2->front;

        while (p && q && p->data == q->data)
        {
            p = p->next;
            q = q->next;
        }

        if (p && q)
            return (p->data > q->data) ? 1 : 0;
    }

    // if two numbers are exactly same before decimal point...

    Node *x = num1->frontDec, *y = num2->frontDec;

    while (x && y && x->data == y->data)
    {
        x = x->next;
        y = y->next;
    }

    if (x && y)
        return (x->data > y->data) ? 1 : 0;
    else if (x)
        return 1;
    else if (y)
        return 0;
    else
        return 1;
}

Number toNumber(char *str)
{
    int i = 0;
    char c;
    int count = strlen(str);
    int nonNumericCount = 0;

    int len = 0;
    while ((c = *(str + len)) != '.' && c != '\0')
    {
        len++;
    }

    List *l = (List *)malloc(sizeof(List));

    init(l);

    if ((c = *(str + i)) == '-')
    {
        l->isNegative = 1;
        // *(str+i) = '\0';
        nonNumericCount++;
        i++;
    }

    while ((c = *(str + i)) == ' ')
    {
        // *(str+i) = '\0';
        nonNumericCount++;
        i++; // If the string contains spaces it will handle the spaces...
    }

    i = len - 1; // Now traversing in reverse direction...

    while (c != '\0' && i != (-1 + nonNumericCount) && c != '-' && c != ' ')
    {
        char a[10] = "000000000"; // This will ensure that even if the loop break earlier, the correct number is read...
        for (int j = 8; j >= 0 && c != '\0' && i != (-1 + nonNumericCount); j--)
        {
            c = *(str + i);
            i--;
            if (c == '-' || c == ' ')
                break;
            a[j] = c;
        }

        a[9] = '\0';
        insertAtBeginning(l, (unsigned long long int)atoll(a));
    }

    c = *(str + len + 1);
    i = len + 1;

    while (c != '\0' && i <= count - 1)
    {
        char a[10] = "000000000"; // New approach is displaying wrong data... Hence continuing with the original approach...
        for (int j = 0; j < 9 && c != '\0' && i <= count - 1; j++)
        {
            c = *(str + i);
            i++;
            a[j] = c;
        }

        a[9] = '\0';
        appendDec(l, (unsigned long long int)atoll(a));
    }

    return l;
}

Number add(Number num1, Number num2)
{

    if (num1->isNegative && num2->isNegative)
    {
        return justAdd(num1, num2, 1);
    }
    else if (num1->isNegative)
    {
        return justSubtract(num2, num1);
    }
    else if (num2->isNegative)
    {
        return justSubtract(num1, num2);
    }
    else
    {
        return justAdd(num1, num2, 0);
    }
}

Number subtract(Number num1, Number num2)
{

    if (num1->isNegative && num2->isNegative)
    {
        return justSubtract(num2, num1);
    }
    else if (num1->isNegative)
    {
        return justAdd(num1, num2, 1);
    }
    else if (num2->isNegative)
    {
        return justAdd(num1, num2, 0);
    }
    else
    {
        return justSubtract(num1, num2);
    }
}

Number multiply(Number num1, Number num2)
{

    if ((!num1->front && !num1->frontDec) || (!num2->front && !num2->frontDec))
    {
        List *l = (List *)malloc(sizeof(List));
        init(l);
        return l;
    }

    if (num1->isNegative && num2->isNegative)
    {
        return justMultiply(num1, num2, 0);
    }
    else if (num1->isNegative || num2->isNegative)
    {
        return justMultiply(num1, num2, 1);
    }
    else
    {
        return justMultiply(num1, num2, 0);
    }
}

Number divide(Number num1, Number num2)
{
    if (!num1->front && !num1->frontDec)
    {
        List *l = (List *)malloc(sizeof(List));
        init(l);
        return l;
    }
    else if (!num2->front && !num2->frontDec)
    {
        printf("Error: Cannot Divide by Zero!\n");
        return toNumber("0");
    }
    else if (!greater(num1, num2))
    {
        return toNumber("0");
    }

    if (num1->isNegative && num2->isNegative)
    {
        return justDivide(num1, num2, 0);
    }
    else if (num1->isNegative || num2->isNegative)
    {
        return justDivide(num1, num2, 1);
    }
    else
    {
        return justDivide(num1, num2, 0);
    }
}

Number justAdd(Number num1, Number num2, short isNegative)
{
    short carry = 0, carryDec = 0;
    Node *p = num1->rear, *q = num2->rear;
    Node *x = num1->frontDec, *y = num2->frontDec;

    List *l = (List *)malloc(sizeof(List));
    init(l);

    if (isNegative)
        l->isNegative = 1;

    // First adding digits after decimal point...

    if (x && y)
    {
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

        if (carryDec)
        {
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

    if (carry)
    {
        insertAtBeginning(l, carry);
    }

    return l;
}

Number justSubtract(Number num1, Number num2)
{
    int borrow = 0, borrowDec = 0;
    int xlen = 0, ylen = 0;
    Node *p, *q;
    Node *x, *y;

    List *l = (List *)malloc(sizeof(List));
    init(l);

    if (greater(num1, num2))
    {
        l->isNegative = 0;
        p = num1->rear;
        q = num2->rear;
        x = num1->rearDec;
        xlen = lenDec(num1);
        y = num2->rearDec;
        ylen = lenDec(num2);
    }
    else
    {
        l->isNegative = 1;
        p = num2->rear;
        q = num1->rear;
        x = num2->rearDec;
        xlen = lenDec(num2);
        y = num1->rearDec;
        ylen = lenDec(num1);
    }

    /*

    // Here tried subtracting from right to left for numbers after decimal point,
    // but thing are getting very complicated... Hence, tried new approach...

    if (x && y){

        borrow = (x->data < y->data)? 1 : 0;

        while (x->next && y->next)
        {
            long long int t = (long long int) x->data - y->data - ((x->next->data < y->next->data)? 1 : 0);

            if (t < 0) t += MAX;

            appendDec(l,  (unsigned long long int) t % MAX);
            x = x->next;
            y = y->next;
        }

        if (y->next){
            long long int t = (long long int) x->data - y->data - 1;

            if (t < 0) t += MAX;

            appendDec(l,  (unsigned long long int) t % MAX);
            x = x->next;
            y = y->next;
        }
        else{
            long long int t = (long long int) x->data - y->data;

            if (t < 0){
                borrowDec = 1;
                t += MAX;
            }

            appendDec(l,  (unsigned long long int) t % MAX);
            x = x->next;
            y = y->next;
        }

    }

    while (x){
        long long int t = (long long int) x->data - y->data;
        appendDec(l, x->data - borrowDec);
        x = x->next;
    }

    while (y->next){
        appendDec(l, MAX - y->data - 1);
        y = y->next;
    }

    appendDec(l, MAX - y->data);
    y = y->next;

    */

    while (xlen > ylen)
    {
        insertAtBeginningDec(l, x->data);
        x = x->previous;
        xlen--;
    }

    while (ylen > xlen)
    {
        insertAtBeginningDec(l, MAX - y->data - borrowDec);
        y = y->previous;
        borrowDec = 1;
        ylen--;
    }

    while (x && y)
    {
        long long int t = (long long int)x->data - y->data - borrowDec;

        if (t < 0)
        {
            t += MAX;
            borrowDec = 1;
        }
        else
        {
            borrowDec = 0;
        }

        insertAtBeginningDec(l, (unsigned long long int)t % MAX);

        x = x->previous;
        y = y->previous;
    }

    borrow = borrowDec;

    while (p && q)
    {
        long long int t = (long long int)p->data - q->data - borrow;

        if (t < 0)
        {
            t += MAX;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        insertAtBeginning(l, (unsigned long long int)t % MAX);

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
        insertAtBeginning(l, -q->data - borrow);
        borrow = 0;
        q = q->previous;
    }

    Node *r = l->front;

    while (r && r->data == 0)
    {
        r = r->next;
        removeBeginning(l);
    }

    r = l->rearDec;

    while (r && r->data == 0)
    {
        r = r->previous;
        removeEndDec(l);
    }

    return l;
}

// Changes implemented till here for new updated data structure...
// Changes below are yet to be implemented...

Number justMultiply(Number num1, Number num2, short isNegative)
{
    long long int carry = 0;
    int count = 0;
    int nodesAfterDecimalInAnswer = lenDec(num1) + lenDec(num2);
    Node *p, *q;

    // Connecting both the lists together to multiply if it is present...
    if (num1->frontDec)
    {
        num1->rear->next = num1->frontDec;
        num1->frontDec->previous = num1->rear;
        p = num1->rearDec;
    }
    else
    {
        p = num1->rear;
    }

    if (num2->frontDec)
    {
        num2->rear->next = num2->frontDec;
        num2->frontDec->previous = num2->rear;
        q = num2->rearDec;
    }
    else
    {
        q = num2->rear;
    }

    List *l = (List *)malloc(sizeof(List));
    init(l);

    List *temp = (List *)malloc(sizeof(List));
    init(temp);

    while (q)
    {
        if (num1->frontDec)
            p = num1->rearDec;
        else
            p = num1->rear;

        while (p)
        {
            int qData = q->data;

            unsigned long long int t = (unsigned long long int)p->data * qData + carry;
            insertAtBeginning(temp, t % MAX);
            carry = t / MAX;
            p = p->previous;
        }
        if (carry != 0)
            insertAtBeginning(temp, carry);

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

    if (isNegative)
        l->isNegative = 1;

    if (nodesAfterDecimalInAnswer)
    {
        l->rearDec = l->rear;

        Node *p = l->rear;

        for (int i = 0; i < nodesAfterDecimalInAnswer - 1; i++)
        {
            p = p->previous;
        }

        l->frontDec = p;
        l->rear = p->previous;

        l->frontDec->previous = NULL;
        l->rear->next = NULL;

        // Resolving the side effects caused above to the num1 and num2...

        num1->rear->next = NULL;
        if (num1->frontDec)
            num1->frontDec->previous = NULL;

        num2->rear->next = NULL;
        if (num2->frontDec)
            num2->frontDec->previous = NULL;

        Node *r = l->rearDec;

        while (r && r->data == 0)
        {
            r = r->previous;
            removeEndDec(l);
        }
    }

    return l;
}

Number justDivide(Number num1, Number num2, short int isNegative) // gives num1/num2
{
    List *quotient = (List *)malloc(sizeof(List));
    init(quotient);

    Number p = num1, q, multFactor = (List *)malloc(sizeof(List));
    init(multFactor);
    append(multFactor, 0);
    int len2 = len(num2);
    int lct =  len(num1) - len(num2) + 3;
    while (!greater(num2, p))
    {
        long long int t = (long long int)p->front->data / num2->front->data;
        int toAddForSub = 0;
        if (t == 0)
        {
            t = (unsigned long long int)(p->front->data * MAX + p->front->next->data) / num2->front->data;
            toAddForSub += 1;
        }
        multFactor->front->data = t;
        q = multiply(num2, multFactor);
        int lct = 0;
        while (!greater(p, q))
        {
            t--;
            q = subtract(q, num2);
        }
        int len1 = len(p);
        append(quotient, t);
        for (int i = len2 + toAddForSub; i < len1; i++)
        {
            append(q, 0); // adding zeros to get equal size of q and p so we don't get issues in subraction
        }

        p = subtract(p, q);
        lct -= 1;
        if (lct < -1)
        {
            printf("stopping the loop\n");
            display(q);
            display(p);
            display(multFactor);
            break;
        }
    }

    if (isNegative)
        quotient->isNegative = 1;

    return quotient;
}

Number power(Number num1, Number num2)
{
    if (len(num2) > 1)
    {
        printf("Warning: Exponent too long!\n");
        return toNumber("1");
    }

    if (lenDec(num2) != 0)
    {
        printf("Warning: Ignoring the decimal part!\n");
    }

    unsigned long long int t = num2->front->data;

    return powerHelper(num1, t);
}

Number powerHelper(Number num1, unsigned long long int num2)
{
    if (num2 == 0)
    {
        return toNumber("1");
    }
    else if (num2 == 1)
    {
        return num1;
    }

    Number temp = multiply(powerHelper(num1, num2 / 2), powerHelper(num1, num2 / 2));

    if (num2 % 2 == 0)
        return temp;
    else
        return multiply(temp, num1);
}

Number bitwiseLeftShift(Number num1, Number num2)
{
    if (len(num2) > 1)
    {
        printf("Warning: Shifting Number too long!\n");
        return toNumber("1");
    }

    return multiply(num1, power(toNumber("2"), num2));
}

Number bitwiseRightShift(Number num1, Number num2)
{
    if (len(num2) > 1)
    {
        printf("Warning: Shifting Number too long!\n");
        return toNumber("1");
    }

    return divide(num1, power(toNumber("2"), num2));
}

Number mod(Number num1, Number num2)
{

    Number multFactor = (List *)malloc(sizeof(List));
    append(multFactor, 0);
    int noOfZeros = len(num1);
    Number p = num1;
    display(num2);
    int lct = len(num1) - len(num2) + 3;
    while (greater(p, num2))
    {
        long long int t = (long long int)p->front->data / num2->front->data;
        if (t == 0)
        {
            if (p->front->next == NULL)
            {
                break;
            }
            t = (unsigned long long int)(p->front->data * MAX + p->front->next->data) / num2->front->data;
            noOfZeros -= 1;
        }

        multFactor->front->data = t;
        Number q = multiply(num2, multFactor);
        while (!greater(p, q) && q->isNegative == p->isNegative)
        {
            q = subtract(q, num2);
            t--;
        }
        int len2 = len(q);
        if (len2>len(num2))
        {
            noOfZeros += 1;   
        }
        
        
        for (; len2 < noOfZeros; len2++)
        {
            append(q, 0);
        }
        printf("p:");
        display(p);
        printf("q:");
        display(q);
        p = subtract(p, q);
        noOfZeros = len(p);
        // display(p);
        if (lct < -1)
        {
            printf("stopping the loop\n");
            printf("q:");
            display(q);
            printf("p:");
            display(p);
            printf("multFactor:");
            display(multFactor);
            break;

        }
        lct -= 1;
    }
    if (p->isNegative)
    {
        p = add(p, num2);
    }
    return p;
}