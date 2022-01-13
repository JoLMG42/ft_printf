/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:27:54 by jtaravel          #+#    #+#             */
/*   Updated: 2022/01/13 14:31:33 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_check_s(va_list argv, t_flags flags)
{
	int		count;
	char	*str;

	count = 0;
	str = va_arg(argv, char *);
	if (!str)
		str = "(null)";
	if (flags.dot)
		count += ft_flag_dot_s(str, flags, count);
	else if (flags.width)
		count = ft_flag_width_s(str, flags, count);
	else
		count = ft_putstr_count(str);
	return (count);
}

int	ft_check_c(va_list argv, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.width)
		count = ft_print_width_c(va_arg(argv, int), flags.justify, flags.width);
	else
		count = ft_putchar_count(va_arg(argv, int));
	return (count);
}

int	ft_print_width_c(char c, char j, int nb)
{
	int	count;
	int	i;

	count = 0;
	i = -1;
	if (j != 0)
	{
		count = ft_putchar_count(c);
		while (++i < nb - 1)
			count += ft_putchar_count(' ');
	}
	else
	{
		while (++i < nb - 1)
			count += ft_putchar_count(' ');
		count += ft_putchar_count(c);
	}
	return (count);
}
