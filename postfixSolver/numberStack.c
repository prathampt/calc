#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#include "numberStack.h"

void SLL_initNum(StackNum *s)
{
    s->top = NULL;
    return;
}

int isEmptyNum(StackNum s)
{
    if (s.top == NULL)
        return 1;

    return 0;
}

void pushNum(StackNum *s, Number data)
{
    SLL_NodeNum *nn = (SLL_NodeNum *)malloc(sizeof(SLL_NodeNum));

    if (!nn)
        return;

    nn->num = data;
    nn->next = NULL;

    if (isEmptyNum(*s))
    {
        s->top = nn;
        return;
    }
    else
    {
        nn->next = s->top;
        s->top = nn;
    }

    return;
}

Number popNum(StackNum *s)
{
    if (isEmptyNum(*s))
        return NULL;

    SLL_NodeNum *p = s->top;
    Number data = p->num;
    s->top = p->next;
    free(p);
    return data;
}

Number peekNum(StackNum s)
{
    if (isEmptyNum(s))
        return NULL;

    return s.top->num;
}

void SLL_displayNum(StackNum s)
{
    if (isEmptyNum(s))
        return;

    printf("Displaying the StackNum: ");

    for (SLL_NodeNum *p = s.top; p != NULL; p = p->next)
    {
        display(p->num);
        printf("   ");
    }

    printf("\b\b   \n");
    return;
}