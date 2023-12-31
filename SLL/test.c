#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"number.c"

int main(int argc, char const *argv[])
{
    char* str="12343543234";
    char* str1="12322321";
    
    Number* num1=toNumber(str);
    Number* num2=toNumber(str1);

    Number mul=mult(*num1, *num2);
    displayNum(*num1);             
    displayNum(*num2);         
    displayNum(mul);

    return 0;
}
