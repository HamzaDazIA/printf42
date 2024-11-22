/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdazia <hdazia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 08:07:17 by hdazia            #+#    #+#             */
/*   Updated: 2024/11/22 17:33:30 by hdazia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex_p(unsigned long long nb)
{
	char	*hex;
	int		how_mprintf;

	how_mprintf = 0;
	hex = "0123456789abcdef";
	if (nb >= 16)
		how_mprintf += ft_printhex_p(nb / 16);
	how_mprintf += ft_putchar(hex[nb % 16]);
	return (how_mprintf);
}

int	ft_printp(void *p)
{
	int	how_mprint;

	how_mprint = 0;
	how_mprint += ft_putstr("0x");
	how_mprint += ft_printhex_p((unsigned long long)p);
	return (how_mprint);
}
