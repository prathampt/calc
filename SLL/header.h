typedef struct node
{
    int data;
    struct node * next;
}Node;
typedef Node * List;
typedef struct number{
    List head;// what i need to do is simply just store the where head will point to lsb
    short isNegative;
}Number;

void init(List *l);
void display(List l);
void append(List *l, int data);
void insertAtBeginning(List *l, int data);
int removeEnd(List *l);
int removeBeginning(List *l);
int removeNode(List *l, Node *n);
void addNodeAtPosition(List *l, int data, int position);
int length(List l);
void swapNodes(List * l, Node * n1, Node * n2);
void fill(List *l, int number);
void reverseEven(List *l);
int isPalindrome(List l);
void removeDuplicates(List *l);
void destroy(List *l);
void removeAndInsert(List *l, Node *n, int index);


void init_Number(Number* num);
Number *toNumber(char * str);
void displayNum(Number num);
Number Add(Number num1, Number num2);
Number Sub(Number num1, Number num2);
int absCompare(Number num1, Number num2); // 0 if equal, 1 if num2 is greater than num1 else -1
Number mult(Number num1, Number num2);