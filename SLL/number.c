#include "logic.c"
#include <string.h>
#define MAXNODEVAL 1000000000
void init_Number(Number *num)
{
    num->head = NULL;
    num->isNegative = 0;
}
Number *toNumber(char *str)
{
    int len = strlen(str);

    Number *num = malloc(sizeof(Number));
    init_Number(num);
    if (str[0] == '-')
    {
        num->isNegative = 1;
        // str[0] = '0';
    }
    char *nineLen = (char *)malloc(sizeof(char) * 9);
    while (len > 9)
    {
        for (int i = len - 1; i > len - 10; i--)
        {
            nineLen[i - len + 9] = str[i];
            // str[i]='\0';//equating it with null character to reduce str's length //this gives seg fault i don't know why pls let me know
        }
        const int n = atoi(nineLen);

        append(&num->head, n);
        len = len - 9;
    }
    char *finalStr = (char *)malloc(sizeof(char) * 8);
    int j = 0;
    for (int i = 0; i < len; i++)
    {
        if (num->isNegative && !i)
            i++;
        finalStr[j] = str[i];
        j++;
    }
    for (int i = len; i < 9; i++)
    {
        finalStr[i] = '\0';
    }
    int n = atoi(finalStr);
    append(&num->head, n);
    return num;
}
void displayNum(Number num)
{
    List revList = reverse(num.head);
    if (num.isNegative)
    {
        printf("-");
    }
    printf("%d", revList->data);
    revList = revList->next;
    while (revList)
    {
        printf("%09d", revList->data);
        revList = revList->next;
    }
    printf("\n");
    
    return;
}
Number Add(Number num1, Number num2)
{
    if (num1.isNegative ^ num2.isNegative) // if signs are different
    {
        num2.isNegative = num1.isNegative;
        Number sub = Sub(num1, num2);
        return sub;
    }

    unsigned int sum;
    int carry = 0;
    Node *p = num1.head, *q = num2.head;
    Number *ans = (Number *)malloc(sizeof(Number));

    ans->isNegative = 0;
    if (num1.isNegative)
        ans->isNegative = 1;

    while (p && q)
    {
        sum = (p->data + q->data + carry);
        carry = sum / MAXNODEVAL;
        sum %= MAXNODEVAL;
        append(&ans->head, sum);
        p = p->next;
        q = q->next;
    }
    while (p)
    {
        sum = p->data + carry;
        carry = sum / MAXNODEVAL;
        sum %= MAXNODEVAL;
        append(&ans->head, sum);
        p = p->next;
    }
    while (q)
    {
        sum = q->data + carry;
        carry = sum / MAXNODEVAL;
        sum %= MAXNODEVAL;
        append(&ans->head, sum);
        q = q->next;
    }
    if (carry)
        append(&ans->head, carry);
    return *ans;
}

Number Sub(Number num1, Number num2)
{
    // displayNum(num1);
    if (num1.isNegative ^ num2.isNegative)
    {
        num2.isNegative = num1.isNegative;
        Number add = Add(num1, num2);
        return add;
    }
    Number *ans = (Number *)malloc(sizeof(Number));
    if (absCompare(num1, num2) == 0)
    {
        append(&ans->head, 0);
        return *ans;
    }
    ans->isNegative = 0;
    int borrow = 0;
    // kon greater hai abs mai?
    if (absCompare(num1, num2) == 1) // num2 > num1
    {
        long long subNodeVal;
        Node *small = num1.head;
        Node *big = num2.head;
        while (small && big)
        {
            subNodeVal = big->data - small->data + borrow;
            borrow = subNodeVal / MAXNODEVAL;
            subNodeVal %= MAXNODEVAL;
            append(&ans->head, subNodeVal + borrow);
            big = big->next;
            small = small->next;
        }
        while (big)
        {
            subNodeVal = big->data + borrow;
            subNodeVal %= MAXNODEVAL;
            borrow = subNodeVal / MAXNODEVAL;
            append(&ans->head, subNodeVal + borrow);
            big = big->next;
        }
        if (!num2.isNegative)
        {
            ans->isNegative = 1;
        }
    }
    else
    {
        long long subNodeVal;
        Node *big = num1.head;
        Node *small = num2.head;
        while (small && big)
        {
            subNodeVal = big->data - small->data + borrow;
            subNodeVal %= MAXNODEVAL;
            borrow = subNodeVal / MAXNODEVAL;
            append(&ans->head, subNodeVal);
            big = big->next;
            small = small->next;
        }
        while (big)
        {
            subNodeVal = big->data + borrow;
            borrow = subNodeVal / MAXNODEVAL;
            subNodeVal %= MAXNODEVAL;
            append(&ans->head, subNodeVal + borrow);
            big = big->next;
        }
        if (num1.isNegative)
        {
            ans->isNegative = 1;
        }
    }
    if (borrow)
        append(&ans->head, borrow);
    return *ans;
}
int absCompare(Number num1, Number num2) // 0 if equal, 1 if num2 is greater than num1 else -1
{
    int len1 = length(num1.head), len2 = length(num2.head);
    if (len1 < len2)
        return 1;
    if (len1 > len2)
        return -1;

    List revList1 = reverse(num1.head), revList2 = reverse(num2.head);
    while (revList1->data == revList2->data)
    {
        revList1 = revList1->next;
        revList2 = revList2->next;
    }
    if (revList1->data < revList2->data)
    {
        return 1;
    }
    if (revList1->data > revList2->data)
    {
        return -1;
    }
    return 0;
}



