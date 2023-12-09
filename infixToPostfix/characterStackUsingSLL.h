typedef struct SLL_node{
    char data;
    struct SLL_node * next;
}SLL_Node;

typedef struct stack{
    SLL_Node *top;
}Stack;

void SLL_init(Stack *s);
int isEmpty(Stack s);
void push(Stack *s, char data);
char pop(Stack *s);
char peek(Stack s);
void SLL_display(Stack s);