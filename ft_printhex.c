/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdazia <hdazia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:50:21 by hdazia            #+#    #+#             */
/*   Updated: 2024/11/21 20:16:23 by hdazia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printhex(int n, char c)
{
	long	nb;
    int  how_mprint;
    
    how_mprint = 0;
	nb = n;
	if (nb >= 16)
	{
		how_mprint += ft_printhex((nb / 16),c);
		how_mprint += ft_printhex((nb % 16),c);
	}
	else if (nb >= 9)
    {
        if (c == 'x')
		    how_mprint += ft_putchar((nb - 10) + 'a');
        else
            how_mprint += ft_putchar((nb - 10) + 'A');
    }
    else
    {
        how_mprint += ft_putchar(nb + '0');
    }
    return (how_mprint);
}
