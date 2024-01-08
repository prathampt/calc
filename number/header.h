typedef struct node
{
    unsigned long long int data; // Changing the implementation of the data storage...
    struct node *next, *previous;
} Node;

typedef struct list
{
    short isNegative; // This will only take values 1 (if the number is negative) and 0 (otherwise)...
    Node *front, *rear;
    Node *frontDec, *rearDec;
} List;

typedef List *Number;

/*
    Implementing Number as an abstract data type...
*/

void init(List *l);

void append(List *l, unsigned long long int data);
void insertAtBeginning(List *l, unsigned long long int data);
int removeBeginning(List *l);
void destroy(List *l); // destory the integer part

void appendDec(List *l, unsigned long long int data);
void insertAtBeginningDec(List *l, unsigned long long int data);
int removeEndDec(List *l);
void destroyDec(List *l); // destory the decimal part

void display(Number num); // displays number
short len(Number num);
short greater(Number num1, Number num2); // this will return 1 if first number is greater than second number or 0 otherwise...

Number toNumber(char *str);

/*
    Arithmatic Functions on Numbers...
*/

Number add(Number num1, Number num2);
Number subtract(Number num1, Number num2);
Number multiply(Number num1, Number num2);
Number divide(Number num1, Number num2);
Number power(Number num1, Number num2);
Number bitwiseLeftShift(Number num1, Number num2);

Number justAdd(Number num1, Number num2, short isNegative);
Number justSubtract(Number num1, Number num2);
Number justMultiply(Number num1, Number num2, short isNegative);
Number justDivide(Number num1, Number num2);
Number powerHelper(Number num1, unsigned long long int num2);