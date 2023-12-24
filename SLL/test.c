#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"number.c"

int main(int argc, char const *argv[])
{
    char* str="-12343543234";
    char* str1="12322321";
    
    Number* num1=toNumber(str);
    // displayNum(*num);
    displayNum(*num1);
    return 0;
}
