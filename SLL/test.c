#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"number.c"

int main(int argc, char const *argv[])
{
    char* str="-12343543234";
    char* str1="-12322321";
    
    Number* num1=toNumber(str);
    Number* num2=toNumber(str1);
    Number sum=Add(*num1, *num2);  //    12343543234
    // displayNum(*num1);             // +     12322321
    // displayNum(*num2);             //________________
    // displayNum(sum);               //    12355865555

    Number sub=Sub(*num1, *num2);
    displayNum(sub);
    return 0;
}
