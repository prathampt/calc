typedef struct node {
    unsigned int data; // Using unsigned int to increase the range of the integers we can store in one node...
    struct node *next, *previous;
} Node;

typedef struct list {
    short int isNegative; // This will only take values 1 (if the number is negative) and 0 (otherwise)...
    Node * front, * rear;
} List;

typedef List * Number;

void init(List *l);

void insertAtBeginning(List *l, unsigned int data);

void display(List l);

Number toNumber(char * str);