#include "logic.c"
#include "../infixToPostfix/logic.c"
#include "../fileHandling/input.c"
int main(int argc, char const *argv[])
{
    FILE *history = fopen("history.txt", "a");
    char *str = input(history);
    int len = strlen(str);

    char *postfixStr = infixToPostfix(str, len);
    printf("%s \n", postfixStr);
    Number answer = posfixSolver(postfixStr);
    display(answer);
    return 0;
}
