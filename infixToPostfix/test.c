#include "logic.c"
int main()
{
    char *string = "1.01*203.4+94-47*--4";

    int len = 0, i = 0;
    char c;
    while ((c = string[len]) != '\0')
    {
        len++;
    }

    char *answer = infixToPostfix(string, len);

    while ((c = answer[i]) != '\0')
    {
        printf("%c", c);
        i++;
    }

    printf("\n");

    return 0;
}