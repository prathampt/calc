#include "NumberStack.c"
int isOperatorNum(char c)
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
Number PerfromOperation(Number num1, Number num2, char op)
{
    switch (op)
    {
    case '+':
        return add(num1, num2);
    case '-':
        return subtract(num1, num2);
    case '*':
        return multiply(num1, num2);
    default:
        return NULL;
    }
}
Number posfixSolver(char *postStr)
{
    Number answer = (List* )malloc(sizeof(List));
    StackNum operandStack;
    SLL_initNum(&operandStack);
    init(answer);
    int i = 0, j = 0, operatorCheck = 0;
    int len = strlen(postStr);
    int size = 50;
    char *numStr = (char *)malloc(sizeof(char) * size);
    for (int i = 0; i < len; i++)
    {
        if (isdigit(postStr[i]) || postStr[i] == '.')
        {
            if (j == size)
            {
                size += 25;
                numStr = realloc(numStr, size);
            }
            numStr[j++] = postStr[i];
            operatorCheck=0;
        }
        else if (isOperatorNum(postStr[i]))
        {
            if (isEmptyNum(operandStack))
            {
                printf("This is error");
                return NULL;
            }
            Number op1,op2; 
            if (!operatorCheck)
            {
                op1 = popNum(&operandStack);
                op2 = toNumber(numStr);
                operatorCheck = 1;
            }
            else
            {
                op2 = popNum(&operandStack);
                op1 = popNum(&operandStack);
                if (!op1)
                {
                    printf("Error");
                    return NULL;
                }
            }
            Number prevAns = answer;
            answer = PerfromOperation(op1, op2, postStr[i]);
            destroy(prevAns);
            pushNum(&operandStack, answer);
            // SLL_displayNum(operandStack);
        }
        else if (postStr[i] == ' ')
        {
            if (isOperatorNum(postStr[i+1]) || operatorCheck)
            {
                j=0;
                continue;
            }
            numStr[j++]='\0';
            j=0;
            // printf("%s ",numStr);
            Number topushNum = toNumber(numStr);
            pushNum(&operandStack, topushNum);
            // SLL_displayNum(operandStack);
        }
    }

    return answer;
}
#include"../infixToPostfix/logic.c"
#include"../fileHandling/input.c"
int main(int argc, char const *argv[])
{
    FILE *history=fopen("history.txt","a");
    char* str=input(history);
    int len = strlen(str);
    char* postfixStr = infixToPostfix(str, len);
    Number answer = posfixSolver(postfixStr);
    display(answer);
    return 0;
}
