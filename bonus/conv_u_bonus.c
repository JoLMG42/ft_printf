/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_u_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:53:44 by jtaravel          #+#    #+#             */
/*   Updated: 2021/12/06 15:53:45 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_flag_dot_u2(t_flags flags, int len, int count)
{
	int	i;

	i = -1;
	if (flags.preci <= len)
		flags.preci = 0;
	else
		len = 0;
	while (++i < flags.width - flags.preci - len)
		count += ft_putchar_count(' ');
	return (count);
}

int	ft_flag_dot_u(unsigned int nb, t_flags flags, int len, int count)
{
	int	i;

	i = -1;
	if (nb == 0 && (flags.preci == 0 || !flags.preci))
		len = 0;
	if (flags.width && !flags.justify)
		count += ft_flag_dot_u2(flags, len, 0);
	i = -1;
	if (flags.preci)
		while (++i < flags.preci - len)
			count += ft_putchar_count('0');
	if (nb == 0 && (flags.preci == 0 || !flags.preci))
		count += 0;
	else
		count += ft_unsigned_putnbr_count(nb, 0);
	i = -1;
	if (flags.justify && flags.width)
		count += ft_flag_dot_u2(flags, len, 0);
	return (count);
}

int	ft_flag_width_u(unsigned int nb, t_flags flags, int len, int count)
{
	int		i;
	char	c;

	c = ' ';
	i = -1;
	if (flags.zero)
		c = '0';
	if (!flags.justify)
	{
		while (++i < flags.width - len)
			count += ft_putchar_count(c);
	}
	count += ft_unsigned_putnbr_count(nb, 0);
	if (flags.justify)
	{
		while (++i < flags.width - len)
			count += ft_putchar_count(' ');
	}
	return (count);
}
