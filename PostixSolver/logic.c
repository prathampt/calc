#include"NumberStack.c"
int isOperator(char c){
    switch (c){
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
Number posfixSolver(char* postStr){
    Number answer;
    Stack operandStack;
    SLL_init(&operandStack);
    answer=(List *)malloc(sizeof(List));
    init(answer);
    int i=0, j=0, operatorCheck = 0;
    int len =strlen(postStr);
    for (int i = 0; i < len; i++)
    {
        int size = 50;
        char* numStr = (char* )malloc(sizeof(char)*size);
        if (isdigit(postStr[i]) || str[i]=='.')
        {
            if (j==size)
            {
                size += 25;
                numStr = realloc(numStr, size);
            }
            numStr[j++] = postStr[i];
        }
        else if (isOperator(postStr[i]))
        {
            if (isEmpty(operandStack))
            {
                printf("This is error");
                return init(answer);
            }
            Number op1 = pop(&operandStack);
            Number op2 = toNumber(numStr);
            answer=PerfromOperation();
            operatorCheck=1;
            
        }
        else if(postStr[i]==' '){
            if(operatorCheck){
                continue;
            }
            Number toPush=toNumber(numStr);
            push(&operandStack, toPush);
        }



        

        
    }
    
    return answer;
}