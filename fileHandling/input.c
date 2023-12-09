#include <stdio.h>
#include <stdlib.h>
#define SIZE 50
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
            size += 10;
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