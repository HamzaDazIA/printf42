/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdazia <hdazia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:41:52 by hdazia            #+#    #+#             */
/*   Updated: 2024/11/21 20:16:38 by hdazia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int ft_printf(const char * counst, ...);
int	ft_putnbr(int n);
int	ft_putchar(char c);
int	ft_putnbr_unsignd(unsigned int n);
int	ft_printhex(int n, char c);

#endif