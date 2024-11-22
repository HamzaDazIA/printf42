Gather ’round, fellow code explorers, for I shall spin you a tale of the wondrous journey undertaken by brave souls in the hallowed halls of 1337. Behold, the epic saga of “The Fantastical Formatting Frenzy”!

Picture a realm where code rules and imagination runs wild. Our valiant heroes had triumphed over their first challenge, crafting the mystical “libft” library. But now, they faced an even mightier quest: crafting the formidable “ft_printf” spell, a spell to make text dance and numbers shimmer!

The printf function in C is used for formatted output. It’s part of the Standard Input/Output Library (stdio.h) and is responsible for printing data to the standard output (typically the console) in a specified format. It’s an essential tool for displaying information to users and debugging programs.

The Format String:
At the core of printf is the format string. This string contains both text and format specifiers, which are placeholders for the values you want to print. Format specifiers start with a ‘%’ character, followed by a character that indicates the type of data to be printed (e.g., %d for integers, %s for strings).

char *name = "Azouine";
printf("I am %s .", name);
In this example, "I am %s ." is the format string, and %s is the format specifier. The %s specifier tells printf to expect an String value, which is provided as name. The printf function processes the format string, replacing format specifiers with the actual values you provide as arguments.

Argument Handling:
One of the unique features of printf is its ability to accept a variable number of arguments. This is accomplished using variadic functions in C. The printf function, like many other standard C library functions, is declared with the stdarg.h header to enable this functionality.

Here’s a simplified explanation of how it works:

printf first encounters the format string and parses it to identify format specifiers (e.g., %d, %s).
For each format specifier, printf expects an argument of the corresponding type. For %d, it expects an int, for %s, it expects a char*, and so on.
The number of format specifiers determines the number of arguments printf needs to process.
You pass these arguments to printf after the format string.
int sc = 1337;
char name[] = "Azouine";
printf("Name: %s, school: %d", name, sc);
In this example, printf processes two format specifiers (%s and %d) and requires two corresponding arguments (name and sc).

Variadic Functions:

To handle this variable number of arguments, printf uses the stdarg.h library, which provides macros like va_list, va_start, and va_arg. These macros allow printf to access its arguments sequentially, even though it doesn’t know the number or types of arguments at compile-time.

Processing Format Specifiers:
Format specifiers in printf are placeholders that tell the function how to format and print data. They start with a ‘%’ character and are followed by a character that specifies the data type to be printed.

%d: Format as a signed decimal integer.

%u: Format as an unsigned decimal integer.

%i: Prints an integer in base 10.

%s: Format as a null-terminated string.

%c: Format as a character.

%x: Format as a hexadecimal number, lowercase.

%X: Format as a hexadecimal number, uppercase.

%p: The void * pointer argument has to be printed in hexadecimal format

%%: Prints a percent sign.

Authorized functions and macros :
write (man 2 write)
malloc (man 3 malloc)
free (man 3 free)
va_start (man 3 va_start)
va_end (man 3 va_end)
va_copy (man 3 va_copy)
va_arg (man 3 va_arg)

print
The ft_printf function prints formatted output to the standard output according to the format specifier in the input string str. It supports several format specifiers.

First, I will create helper functions that I can use to organize my code.

#include "ft_printf.h"

int ft_check(va_list args, char c)
{
 int re;

 re = 0;
 if (c == 'd' || c == 'i')
    re = ft_putnbr(va_arg(args, int));
 else if (c == 'c')
    re = ft_putchar(va_arg(args, int));
 else if (c == 's')
    re = ft_putstr(va_arg(args, char *));
 else if (c == 'x')
    re = ft_puthex(va_arg(args, unsigned int));
 else if (c == 'X')
    re = ft_puthex_m(va_arg(args, unsigned int));
 else if (c == 'p')
 {
    re = ft_putstr("0x");
    re += ft_putadress(va_arg(args, unsigned long long));
 }
 else if (c == 'u')
    re = ft_putunbr(va_arg(args, unsigned int));
 else if (c == '%')
    return (ft_putchar('%'));
 return (re);
}

int ft_printf(const char *str, ...)
{
 int  i;
 va_list args;
 int  re;

 va_start(args, str);
 re = 0;
 i = 0;
 while (str[i])
 {
  if (str[i] == '%')
  {
   if (str[i + 1] != '\0')
      re += ft_check(args, str[++i]);
  }
  else
      re += ft_putchar(str[i]);
 i++;
 }
 va_end(args);
 return (re);
}
ft_puchar
The ft_putchar function takes a character ‘c’ as its parameter and writes it to the standard output (usually the console or terminal). It achieves this by calling the ft_putchar_fd function with the character ‘c’ and file descriptor 1 (which corresponds to the standard output stream). The result is that the character is displayed on the screen

#include "ft_printf.h"

int ft_putchar(char c)
{
    return (write(1, &c, 1));
}
ft_pustr
The ft_putstr function takes a null-terminated string ‘s’ as its parameter and writes it to the standard output (usually the console or terminal). It achieves this by calling the ft_putstr_fd function with the string ‘s’ and file descriptor 1 (which corresponds to the standard output stream). The result is that the string is displayed on the screen.

#include "ft_printf.h"

int ft_putstr(char *str)
{
 int i;

 if (str == NULL)
    return (write(1, "(null)", 6));
 i = 0;
 while (str[i])
 {
    ft_putchar(str[i]);
    i++;
 }
 return (i);
}
ft_putnbr:
ft_putnbr_fd function takes an integer ’n’ as its parameters. It converts the integer ’n’ to its decimal representation and writes the result to the specified file descriptor 1 in output_std.

#include "ft_printf.h"

int ft_putnbr(int nb)
{
 int r;

 r = 0;
 if (nb == -2147483648)
    return (write(1, "-2147483648", 11));
 if (nb < 0)
 {
  r += write(1, "-", 1);
  nb *= -1;
 }
 if (nb > 9)
 {
    r += ft_putnbr(nb / 10);
    r += ft_putnbr(nb % 10);
 }
 else
    r += ft_putchar(nb + 48);
 return (r);
}
ft_putunbr:
The ft_putunbrfunction recursively prints the input unsigned integer n in the specified base using the provided character set base. so, it recursively divides n by the base length and calls itself for the quotient and the remainder.

#include "ft_printf.h"

int ft_putunbr(unsigned int nb)
{
 unsigned int re;

 re = 0;
 if (nb > 9)
 {
    re += ft_putunbr(nb / 10);
    re += ft_putunbr(nb % 10);
 }
 else
    re += ft_putchar(nb + 48);
 return (re);
}
ft_puthexadecimal_lowercase:
the function uses the For lowercase format, it uses the base “0123456789abcdef”. The base return length nb

#include "ft_printf.h"

int ft_puthexadecimal_lowercase(unsigned int nb)
{
 int  re;
 char *base;

 re = 0;
 base = "0123456789abcdef";
 if (nb >= 16)
 {
    re += ft_puthexadecimal_lowercase(nb / 16);
    re += ft_puthexadecimal_lowercase(nb % 16);
 }
 else
    re += ft_putchar(base[nb % 16]);
 return (re);
}
ft_puthexadecimal_uppercase:
this function uses for convert number to hexadecimal uppercase base “0123456789ABCDEF” return length nb :

#include "ft_printf.h"

int ft_puthexadecimal_uppercase(unsigned int nb)
{
 int  re;
 char *base;

 re = 0;
 base = "0123456789ABCDEF";
 if (nb >= 16)
 {
    re += ft_puthexadecimal_uppercase(nb / 16);
    re += ft_puthexadecimal_uppercase(nb % 16);
 }
 else
    re += ft_putchar(base[nb % 16]);
 return (re);
}
ft_putadress:
this function uses for printf adress on varaible nb return length adress


#include "ft_printf.h"

int ft_putadress(unsigned long nb)
{
 int   re;
 char  *base;

 re = 0;
 base = "0123456789abcdef";
 if (nb >= 16)
 {
    re += ft_putadress(nb / 16);
    re += ft_putadress(nb % 16);
 }
 else
    re += ft_putchar(base[nb % 16]);
 return (re);
}
