#include"fileHandling/input.c"
#include"infixToPostfix/logic.c"
#include"number/number.c"
#include<string.h>
int main()
{
    FILE* history=fopen("history.txt", "a");
    char*str=input(history);
    int len=strlen(str);
    char *postfixStr=infixToPostfix(str,len);
    fclose(history);
    for (int i = 0; postfixStr[i]!='\0'; i++)
    {
        printf("%c",postfixStr[i]);
    }
    return 0;
}

