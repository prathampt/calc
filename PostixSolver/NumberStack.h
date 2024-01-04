#include"../number/number.c"

typedef struct SLL_NodeNum{
    Number num;
    struct SLL_NodeNum * next;
}SLL_NodeNum;

typedef struct StackNum{
    SLL_NodeNum *top;
}StackNum;

void SLL_initNum(StackNum *s);
int isEmptyNum(StackNum s);
void pushNum(StackNum *s, Number data);
Number popNum(StackNum *s);
Number peekNum(StackNum s);
void SLL_displayNum(StackNum s);