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
    for (int i = 0; i < strlen(postfixStr); i++)
    {
        printf("%c",postfixStr[i]);
    }
    printf("\n");
    
    fclose(history);


}

