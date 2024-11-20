#include <stdio.h>
#include <stdarg.h>

int sum(int count, ...)
{
    va_list args;
    int sum = 0;

    va_start(args,count);
    int i = 0;
    while(i < count)
    {
        sum += va_arg(args,int);
        i++;
    }
    return (sum);
}

int main()
{
    printf("tha sum if the variadic %d", sum(3, 22,11,2));
    return 0; 
}