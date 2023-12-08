typedef struct node {
    short data; // Using short int to decrease the memory usuage...
    struct node *next, *previous;
} Node;

typedef struct list {
    short isNegative; // This will only take values 1 (if the number is negative) and 0 (otherwise)...
    Node * front, * rear;
} List;

typedef List * Number;

void init(List *l);

void append(List *l, short data);
void insertAtBeginning(List *l, short data);

void display(Number num);

Number toNumber(char * str);