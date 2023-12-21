#include "logic.c"
#include <string.h>
void init_Number(Number* num)
{
    num->head = NULL;
    num->isNegative=0;
}
Number *toNumber(char * str)
{
    int len = strlen(str);

    Number *num = malloc(sizeof(Number));
    init_Number(num);
    if (str[0] == '-')
    {
        num->isNegative = 1;
        str[0] = '0';
    }
    char *nineLen = (char *)malloc(sizeof(char) * 9);
    while (len > 9)
    {
        for (int i = len - 1; i > len - 10; i--)
        {
            nineLen[i - len + 9] = str[i];
            // str[i]='\0';//equating it with null character to reduce str's length //this gives seg fault i don't know why pls let me know
        }
        int n=atoi(nineLen);

        append(&num->head,n);
        len = len - 9;
    }
    for(int i=0;i<len;i++){
        nineLen[i]=str[i];
    }
    int n=atoi(nineLen);
    append(&num->head,n);
    return num;
}
void displayNum(Number num)
{
    List revList=reverse(num.head);
    if (num.isNegative)
    {
        printf("-");
    }
    while (revList)
    {
        printf("%d",revList->data);
        revList=revList->next;
    }
    printf("\n");
    destroy(&revList);
    return;
}