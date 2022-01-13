/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_px.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:31:18 by jtaravel          #+#    #+#             */
/*   Updated: 2022/01/13 14:31:56 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_width_p(void *p, t_flags flags)
{
	int	count;
	int	i;

	i = -1;
	count = 0;
	if (!flags.justify)
	{
		while (++i < flags.width - (int)ft_len_addr((size_t)p))
			count += ft_putchar_count(' ');
		count += ft_print_addr_count((size_t)p);
	}
	else
	{
		count += ft_print_addr_count((size_t)p);
		while (++i < flags.width - (int)ft_len_addr((size_t)p))
			count += ft_putchar_count(' ');
	}
	return (count);
}

int	ft_check_p(va_list argv, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.width)
		count = ft_print_width_p(va_arg(argv, void *), flags);
	else
		count += ft_print_addr_count((size_t)va_arg(argv, void *));
	return (count);
}

int	ft_check_x(va_list argv, t_flags flags)
{
	int	count;
	int	nb;
	int	len;

	nb = va_arg(argv, int);
	len = ft_unsigned_putnbr_exa_len(nb, flags.conv, 0);
	count = 0;
	if (flags.dot)
		count += ft_flag_dot_x(nb, flags, len, count);
	else if (flags.zero)
		count += ft_flag_zero_x(nb, flags, len, count);
	else if (flags.width)
		count += ft_flag_width_x(nb, flags, len, count);
	else if (flags.sharp)
		count += ft_flag_sharp_x(nb, flags, len, count);
	else
		count += ft_unsigned_putnbr_exa_count(nb, flags.conv, 0);
	return (count);
}
