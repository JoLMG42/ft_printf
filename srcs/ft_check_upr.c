/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_upr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:32:34 by jtaravel          #+#    #+#             */
/*   Updated: 2022/01/13 14:32:06 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_check_u(va_list argv, t_flags flags)
{
	int					count;
	int					len;
	unsigned int		nb;

	nb = va_arg(argv, int);
	len = ft_unsigned_putnbr_len(nb, 0);
	count = 0;
	if (flags.dot)
		count += ft_flag_dot_u(nb, flags, len, count);
	else if (flags.width)
		count += ft_flag_width_u(nb, flags, len, count);
	else
		count += ft_unsigned_putnbr_count(nb, 0);
	return (count);
}

int	ft_check_pr(va_list argv, t_flags flags)
{
	int	count;

	(void)argv;
	count = 0;
	if (flags.conv == '%')
		count += ft_putchar_count('%');
	return (count);
}
