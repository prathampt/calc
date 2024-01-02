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

    // Number a = toNumber("-9384759283475298475298475829.2874827409857298485729847");
    // display(a);
    // printf("\n");
    // Number b = toNumber("0.287458927435782487726487629438756094752987648270179872709169287645827405872947");
    // display(b);
    // printf("\n");
    // Number c = toNumber("298745872649827648772948756287456274657264");
    // display(c);
    // printf("\n");
    // Number d = toNumber("20984750287459284035872049587029492847670956729847.2847650827927401768769839470227846297452034856924756208475");
    // display(d);
    // printf("\n");
    // Number e = add(b, c);
    // display(e);
    // printf("\n");


    // Number a = toNumber("1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890.987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210987654321");
    // display(a);
    // printf("\n");
    // Number b = toNumber("9876543210987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210.123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789");
    // display(b);
    // printf("\n");
    // Number c = add(a, b);
    // display(c);
    // printf("\n");

    // Number a = toNumber("2987745823475829745982459082985092012091638765423745735063827725112987502406196398472984657283749827458.02987468274098726589720487268765217837023958729834767634509823478");
    // display(a);
    // printf("\n");
    // Number b = toNumber("2908437697532872146039857023485237452834750293485287462761019379273654837798234671653817.18723t7841349813274817329487615236490241769376542384570283476591752348712340598713457815293746");
    // display(b);
    // printf("\n");
    // Number c = subtract(a, b);
    // display(c);
    // printf("\n");
    // Number d = subtract(b, a);
    // display(d);
    // printf("\n");

    Number a = toNumber("-97665.04701");
    display(a);
    printf(" * ");
    Number b = toNumber("9860.568210");
    display(b);
    printf(" = ");

    Number d = multiply(a, b);
    display(d);
    printf(" * ");
    Number c = toNumber("-989007233.8");
    display(c);
    printf(" == ");

    Number e = multiply(d, c);    
    display(e);
    printf("                    \n");

    return 0;
}