#include <stdio.h>
int main()
{
    char name[20];
    printf("What is your name?\n");
    scanf("%s", name);
    printf("hello, %s\n", name);
    return 0;
}