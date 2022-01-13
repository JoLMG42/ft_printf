/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:30:29 by jtaravel          #+#    #+#             */
/*   Updated: 2022/01/13 14:31:48 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_width_di(int d, t_flags flags)
{
	int		count;
	char	*str;

	count = 0;
	str = ft_itoa(d);
	if (flags.dot && d >= 0)
		count += ft_flag_dot_di(d, flags, (int)ft_strlen(str), count);
	else if (flags.dot && d < 0)
		count += ft_flag_dot_di_neg(d, flags, (int)ft_strlen(str), count);
	else if (flags.plus && d >= 0)
		count += ft_flag_plus_di(d, flags, (int)ft_strlen(str), count);
	else if (flags.zero && !flags.justify)
		count += ft_flag_zero_di(d, flags, (int)ft_strlen(str), count);
	else
		count += ft_flag_width_di(d, flags, (int)ft_strlen(str), count);
	free(str);
	return (count);
}

int	ft_check_di(va_list argv, t_flags flags)
{
	int	count;
	int	nb;

	nb = va_arg(argv, int);
	count = 0;
	if (flags.width || flags.dot)
		count += ft_print_width_di(nb, flags);
	else if (flags.plus && nb >= 0)
	{
		count += ft_putchar_count('+');
		count += ft_putnbr_count(nb, 0);
	}
	else if (flags.space && nb >= 0)
	{
		count += ft_putchar_count(' ');
		count += ft_putnbr_count(nb, 0);
	}
	else
		count += ft_putnbr_count(nb, 0);
	return (count);
}
