#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"number.c"

int main(int argc, char const *argv[])
{
    char* str="1234234567754323456788654345678653456789";
    Number* num=toNumber(str);
    displayNum(*num);
    return 0;
}
