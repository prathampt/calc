#include <stdio.h>
#include <limits.h>
#include "number.c"

int main(){
    
    Number x = toNumber("100000000000000000000001000000000000000000000000000000000000000000000000000000000");
    Number y = toNumber("1000000000000000000000000000000");

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