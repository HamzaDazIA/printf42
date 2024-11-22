/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdazia <hdazia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:31:49 by hdazia            #+#    #+#             */
/*   Updated: 2024/11/22 17:32:14 by hdazia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

int	ft_printf(const char *counst, ...);
int	ft_putnbr(int n);
int	ft_putchar(char c);
int	ft_putnbr_unsignd(unsigned int n);
int	ft_printhex(unsigned int nb, char c);
int	fail_check(int i);
int	ft_putstr(char *s);
int	ft_printp(void *p);

#endif
