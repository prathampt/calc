#include <stdio.h>
#include <limits.h>
#include "number.c"

int main(){
    
    // Number x = toNumber("10000000000000000000");
    // Number y = toNumber("283749999999999999999999999999999999999999");
    // Number z = toNumber("0");

    // Number q = add(x, y);
    // Number a = subtract(y, x);
    // Number p = subtract(y, y);
    // q = add(q, z);
    // a = subtract(a, z);

    // display(x);
    // printf("\n");
    // display(y);
    // printf("\n");
    // display(q);
    // printf("\n");
    // display(a);
    // printf("\n");
    // display(p);
    // printf("\n");


    // Number a = toNumber("-9766504701");
    // Number b = toNumber("9860568210");
    // Number c = toNumber("-9890072338");

    // Number d = multiply(a, b);
    // Number e = multiply(d, c);

    // display(a);
    // printf("\n");
    // display(b);
    // printf("\n");
    // display(c);
    // printf("\n");
    // display(d);
    // printf("\n");
    // display(e);
    // printf("\n");

    Number a = toNumber("-9384759283475298475298475829.2874827409857298485729847");
    display(a);
    printf("\n");
    Number b = toNumber("0.287458927435782487726487629438756094752987648270179872709169287645827405872947");
    display(b);
    printf("\n");
    Number c = toNumber("298745872649827648772948756287456274657264");
    display(c);
    printf("\n");
    Number d = toNumber("20984750287459284035872049587029492847670956729847.2847650827927401768769839470227846297452034856924756208475");
    display(d);
    printf("\n");

    return 0;
}