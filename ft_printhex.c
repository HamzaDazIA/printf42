/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdazia <hdazia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:50:21 by hdazia            #+#    #+#             */
/*   Updated: 2024/11/22 12:36:19 by hdazia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printhex(unsigned int nb, char c)
{
    char *hex;
    int how_mprintf;

    how_mprintf = 0;
    if (c == 'X')
        hex = "0123456789ABCDEF";
    else
        hex = "0123456789abcdef";
    
    if (nb >= 16)
        how_mprintf += ft_printhex(nb / 16, c);
    how_mprintf += ft_putchar(hex[nb % 16]);
    return (how_mprintf);
}
