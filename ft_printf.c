/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdazia <hdazia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:41:59 by hdazia            #+#    #+#             */
/*   Updated: 2024/11/21 13:40:48 by hdazia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
    return (1);
}

int ft_putstr(char *s)
{
	unsigned int	i;
    
	i = 0;
    if (!s)
    {
        ft_putstr("(null)");
        return (6);
    }
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
    return (i);
}

int ft_check_conversions(const char c,va_list p)
{
    size_t  how_mprint;

    how_mprint = 0;
    if (c == 'c')
        how_mprint += ft_putchar(va_arg(p,int));
    if (c == 's')
        how_mprint += ft_putstr(va_arg(p,char *));
    return (how_mprint);
}

int ft_printf(const char * counst, ...)
{
    va_list p;
    size_t  i;
    size_t  how_mprint;
    
    how_mprint = 0;
    i = 0;
    va_start(p,counst);
    while(counst[i] != '\0')
    {
        if (counst[i] == '%')
        {
            how_mprint += ft_check_conversions(counst[i + 1],p);
        }
        i++;
    }
    return (how_mprint);
}

int main()
{
    int r = ft_printf("%s",NULL);
    printf("%d", r);
}   
