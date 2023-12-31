#include <stdio.h>
#include <limits.h>
#include "number.c"

int main(){
    
    Number x = toNumber("10000000000000000000");
    Number y = toNumber("283749999999999999999999999999999999999999");
    Number z = toNumber("0");

    Number q = add(x, y);
    Number a = subtract(y, x);
    Number p = subtract(y, y);
    q = add(q, z);
    a = subtract(a, z);

    display(x);
    printf("\n");
    display(y);
    printf("\n");
    display(q);
    printf("\n");
    display(a);
    printf("\n");
    display(p);
    printf("\n");


    return 0;
}