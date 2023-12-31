#include <stdio.h>
#include <limits.h>
#include "number.c"

int main(){
    
    Number x = toNumber("1");
    Number y = toNumber("283749999999999999999999999999999999999999");

    Number z = add(x, y);
    // Number a = subtract(x, y);

    display(x);
    printf("\n");
    display(y);
    printf("\n");
    display(z);
    printf("\n");
    // display(a);

    return 0;
}