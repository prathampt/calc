#include "characterStackUsingSLL.c"
#include<stdlib.h>
#include <ctype.h>

int operatorPrecedence(char c)
{
    switch (c)
    {
    case '(':
        return INT_MIN;
    case '-':
    case '+':
        return 0;
    case '*':
    case '/':
    case '%':
        return 1;
    case '^':
        return 2;
    }
}

int isOperator(char c)
{
    switch (c)
    {
    case '-':
    case '+':
    case '*':
    case '/':
    case '^':
    case '%':
        return 1;
    default:
        return 0;
    }
}
int isDot(char c){
    if(c == '.') return 1;
    return 0;
}

char *infixToPostfix(char *str, int n)
{
    Stack s;
    SLL_init(&s);

    int i = 0, j = 0;
    char c;
    char *answer = (char *)malloc(n * sizeof(char));

    while ((c = str[i]) != '\0')
    {
        if (c == ' ')
        {
            i++;
            continue;
        }

        if (str[i] == '-' && i == 0)
        {
            answer[j++] = str[i++];
            continue;
        }
        else if (isOperator(str[i] && i == 0))
        {
            continue;
        }
        if (c == '.')
        {
            answer[j++]=str[i++];
            continue;
        }

        if (c == '(')
        {
            push(&s, c);
            i++;
            continue;
        }

        if (c == ')')
        {
            while (peek(s) != '(')
            {
                answer[j++] = pop(&s);
                answer[j++] = ' ';
            }
            i++;
            pop(&s);
            continue;
        }

        if (isOperator(c))
        {

            while (!isEmpty(s) && (operatorPrecedence(peek(s)) >= operatorPrecedence(c)))
            {
                answer[j++] = pop(&s);
                answer[j++] = ' ';
            }
            answer[j++] = ' ';
            push(&s, c);
            i++;
            continue;
        }

        answer[j++] = c;
        if (!isalnum(str[i]) || isDot(str[i]) )
            answer[j++] = ' ';
            i++;
        if (j>=n)
        {
            answer=(char* )realloc(answer, n*2);
        }
        
    }

    while (!isEmpty(s))
    {
        if (j >= n)
        {
            answer=(char* )realloc(answer, n + 10);
            n+=10;
        }
        
        answer[j++] = pop(&s);
        answer[j++] = ' ';
    }

    return answer;
}

