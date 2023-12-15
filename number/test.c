#include <stdio.h>
#include <limits.h>
#include "number.c"

int main(){
    
    Number x = toNumber("100000000000000000000001000000000000000000000000000000000000000000000000000000000");
    Number y = toNumber("8345028734052873498572098347259874398257394872098734598273401987328742560934879");

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