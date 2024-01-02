#include "characterStackUsingSLL.c"
#include <ctype.h>

int operatorPrecedence(char c){
    switch (c){
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

char * infixToPostfix(char * str, int n){
    Stack s;
    SLL_init(&s);

    int i = 0, j = 0, operator = 0;
    char c;
    char * answer = (char *)malloc(2 * n * sizeof(char));

    while ((c = str[i]) != '\0'){
        if (c == ' '){
            i++;
            continue;
        }

        if (c == '('){
            push(&s, c);
            i++;
            operator = 1;
            continue;
        }

        if (c == ')'){
            while (peek(s) != '('){
                answer[j++] = pop(&s);
                answer[j++] = ' ';
            }
            operator = 0;
            i++;
            pop(&s);
            continue;
        }

        if (isOperator(c)){

            if (operator){
                if (c == '-'){
                    answer[j++] = c;
                    i++;
                    continue;
                }
                else if (c == '+'){
                    i++;
                    continue;
                }
                else return "error";
            }
            
            while (!isEmpty(s) && (operatorPrecedence(peek(s)) >= operatorPrecedence(c))){
                answer[j++] = pop(&s);
                answer[j++] = ' ';
            }

            push(&s, c);
            operator = 1;
            i++;
            continue;
        }

        answer[j++] = c;
        operator = 0;
        if (!isalnum(str[++i]) && str[i] != '.') answer[j++] = ' ';
    }

    while (!isEmpty(s)){
        answer[j++] = pop(&s);
        answer[j++] = ' ';
    }    
       
    return answer;
}