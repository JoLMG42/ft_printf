/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:53:51 by jtaravel          #+#    #+#             */
/*   Updated: 2021/12/06 15:53:52 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_flag_dot_x2(t_flags flags, int len, int count)
{
	int	i;

	i = -1;
	if (flags.preci <= len)
		flags.preci = 0;
	else
		len = 0;
	while (++i < flags.width - len - flags.preci)
		count += ft_putchar_count(' ');
	return (count);
}

int	ft_flag_dot_x(unsigned int nb, t_flags flags, int len, int count)
{
	int		i;
	char	*str;

	if (nb == 0 && (!flags.preci || flags.preci == 0))
		len = 0;
	str = "0X";
	if (flags.conv == 'x')
		str = "0x";
	i = -1;
	if (flags.width && !flags.justify)
		count += ft_flag_dot_x2(flags, len, 0);
	if (flags.sharp)
		count += ft_putstr_count(str);
	while (++i < flags.preci - len && flags.preci)
		count += ft_putchar_count('0');
	if (nb == 0 && (!flags.preci || flags.preci == 0))
		count += 0;
	else
		count += ft_unsigned_putnbr_exa_count(nb, flags.conv, 0);
	if (flags.justify && flags.width)
		count += ft_flag_dot_x2(flags, len, 0);
	return (count);
}

int	ft_flag_zero_x(unsigned int nb, t_flags flags, int len, int count)
{
	int		i;
	char	*str;

	str = "0X";
	if (flags.conv == 'x')
		str = "0x";
	i = -1;
	if (flags.sharp)
		count += ft_putstr_count(str);
	if (!flags.justify && flags.width)
		while (++i < flags.width - len)
			count += ft_putchar_count('0');
	count += ft_unsigned_putnbr_exa_count(nb, flags.conv, 0);
	if (flags.justify && flags.width)
		while (++i < flags.width - len)
			count += ft_putchar_count(' ');
	return (count);
}

int	ft_flag_width_x(unsigned int nb, t_flags flags, int len, int count)
{
	int		i;
	char	*str;

	str = "0X";
	if (flags.conv == 'x')
		str = "0x";
	i = -1;
	if (!flags.justify && flags.width)
		while (++i < flags.width - len)
			count += ft_putchar_count(' ');
	if (flags.sharp)
		count += ft_putstr_count(str);
	count += ft_unsigned_putnbr_exa_count(nb, flags.conv, 0);
	if (flags.justify && flags.width)
		while (++i < flags.width - len)
			count += ft_putchar_count(' ');
	return (count);
}

int	ft_flag_sharp_x(unsigned int nb, t_flags flags, int len, int count)
{
	char	*str;

	(void)len;
	str = "0X";
	if (flags.conv == 'x')
		str = "0x";
	if (nb != 0)
		count += ft_putstr_count(str);
	count += ft_unsigned_putnbr_exa_count(nb, flags.conv, 0);
	return (count);
}
