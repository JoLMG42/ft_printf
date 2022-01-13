/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_di_bonus2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:58:42 by jtaravel          #+#    #+#             */
/*   Updated: 2021/12/06 15:23:49 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_flag_dot_di2(t_flags flags, int nb, int len, int count)
{
	int	i;
	int	pone;
	int	len0;

	i = -1;
	len0 = 0;
	pone = 0;
	if (nb < 0 && flags.preci >= len)
		len0 = 1;
	if (flags.plus || flags.space)
		pone = 1;
	if (flags.preci <= len)
		flags.preci = 0;
	else
		len = 0;
	while (++i < flags.width - flags.preci - pone - len - len0)
		count += ft_putchar_count(' ');
	return (count);
}	

int	ft_flag_dot_di_neg(int nb, t_flags flags, int len, int count)
{
	int	i;

	i = -1;
	if (flags.width && !flags.justify)
		count += ft_flag_dot_di2(flags, nb, len, 0);
	count += ft_putchar_count('-');
	while (++i < flags.preci - len + 1)
		count += ft_putchar_count('0');
	count += ft_putnbr_count((long long int)nb * -1, 0);
	if (flags.width && flags.justify)
		count += ft_flag_dot_di2(flags, nb, len, 0);
	return (count);
}
