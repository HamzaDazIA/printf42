#include "libftprintf.h"
#include <stdio.h>

int main()
{
    fclose(stdout);
    int r = printf("ahmza is great main in live and the fevorite character is  , %x", 2004);
    fprintf(stderr, " \n%d \n",r);
    int result = ft_printf("ahmza is great main in live and the fevorite character is  , %x",2004);
    fprintf(stderr, " \n%d ", result);
}   