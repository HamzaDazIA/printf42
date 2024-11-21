/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdazia <hdazia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:41:59 by hdazia            #+#    #+#             */
/*   Updated: 2024/11/21 14:29:50 by hdazia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
    int  how_mprint;

    how_mprint = 0;
    if (c == 'c')
        how_mprint += ft_putchar(va_arg(p,int));
    else if (c == 's')
        how_mprint += ft_putstr(va_arg(p,char *));
    else if (c == 'd')
        how_mprint += ft_putnbr(va_arg(p,int));
        printf(" \n%d \n", how_mprint);
    
    return (how_mprint);
}

int ft_printf(const char * counst, ...)
{
    va_list p;
    int  i;
    int  how_mprint;
    
    how_mprint = 0;
    i = 0;
    va_start(p,counst);
    while(counst[i] != '\0')
    {
        if (counst[i] == '%')
        {
            how_mprint += ft_check_conversions(counst[i + 1],p);
            i++;
        }
        else
        {
            how_mprint += ft_putchar(counst[i]);
        }
        va_end(p);
        i++;
    }
    return (how_mprint);
}

int main()
{
    int r = ft_printf("%d ",1000);
    //printf(" \n%d ", r);
}   
