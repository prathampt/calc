typedef struct node {
    unsigned long long int data; // Changing the implementation of the data storage...
    struct node *next, *previous;
} Node;

// In this branch we will be implementing the numbers using SLL...

typedef struct list {
    short isNegative; // This will only take values 1 (if the number is negative) and 0 (otherwise)...
    Node * front, * rear;
} List;

typedef List * Number;

/*
    Implementing Number as an abstract data type...
*/

void init(List *l);

void append(List *l, unsigned long long int data);
void insertAtBeginning(List *l, unsigned long long int data);
int removeBeginning(List *l);

void display(Number num);
short len(Number num);
short greater(Number num1, Number num2); // this will return 1 if first number is greater than second number or 0 otherwise...

Number toNumber(char * str);

/*
    Arithmatic Functions on Numbers...
*/

Number add(Number num1, Number num2);
Number subtract(Number num1, Number num2);
Number multiply(Number num1, Number num2);
Number divide(Number num1, Number num2);

Number justAdd(Number num1, Number num2, short isNegative);
Number justSubtract(Number num1, Number num2);
Number justMultiply(Number num1, Number num2, short isNegative);
Number justDivide(Number num1, Number num2, short isNegative);
