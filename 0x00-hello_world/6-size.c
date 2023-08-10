#include <stdio.h>
/**
 * main - A program that print the sieze of various computer types
 * Return: 0 (Success)
 */
int main(void)
{       
        char a;
        int b;
        long int c;
        long long int e;
        float f;
        
printf("Size of a char: %lu byte(s)\n", (unsigned long)size(a));
printf("Size of a int: %lu byte(s)\n", (unsigned long)size(b));
printf("Size of a long int: %lu byte(s)\n", (unsigned long)size(c));
printf("Size of a long long int: %lu byte(s)\n", (unsigned long)size(e));
printf("Size of a float: %lu byte(s)\n", (unsigned long)size(f));
return (0);
}
