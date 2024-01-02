#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "NumberStack.h"

void SLL_init(Stack *s){
    s->top = NULL;
    return;
}

int isEmpty(Stack s){
    if (s.top == NULL) return 1;

    return 0;
}

void push(Stack *s, Number data){
    SLL_Node * nn = (SLL_Node *) malloc(sizeof(SLL_Node));

    if (!nn) return;

    nn->num = data;
    nn->next = NULL;

    if (isEmpty(*s))    
    {
        s->top = nn;
        return;
    }
    else
    {
        nn->next=s->top;
        s->top = nn;
    }
    
    return;
}

Number pop(Stack *s){
    if (isEmpty(*s)) return LLONG_MIN;

    SLL_Node *p = s->top;
    Number data = p->num;
    s->top = p->next;
    free(p);
    return data;
}

Number peek(Stack s){
    if (isEmpty(s)) return CHAR_MIN;

    return s.top->num;
}

void SLL_display(Stack s){
    if (isEmpty(s)) return;

    printf("Displaying the Stack: ");

    for (SLL_Node * p = s.top; p != NULL; p = p->next)
    {
        display(p->num);
    }
    
    printf("\b\b   \n");
    return;
}