#include "postfixSolver/logic.c"
#include "infixToPostfix/logic.c"
#include "fileHandling/input.c"

int main(int argc, char const *argv[])
{
    FILE *history = fopen("history.txt", "a");

    printf("Binary Calculator made by Pratham and Bhavya...\n\n\n");

    while (1)
    {
        char *str = input(history);

        if (strcmp(str, "quit") == 0) break;

        int len = strlen(str);

        char *postfixStr = infixToPostfix(str, len);
        printf(">>> ");
        Number answer = posfixSolver(postfixStr);
        display(answer);
    }
    

    return 0;
}
