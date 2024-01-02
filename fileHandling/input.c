#include <stdio.h>
#include <stdlib.h>

#define SIZE 50 // Do something so that you don't need to store this size initially...

char *input(FILE *file)
{
    char *str;
    int count = 0, c;
    int size = SIZE;
    str = (char *)malloc(sizeof(char) * size);
    if (str == NULL)
        return NULL;

    while ((c = getchar()) != '\n')
    {
        if (count >= SIZE)
        {
            size *= 2;
            str=(char* )realloc(str, size);
            if (str==NULL)
            {
                return NULL;
            }
            
        }
        fprintf(file, "%c", c);
        str[count]=(char)c;   
        count++;
    }
    fprintf(file,"\n");
    return str;
}