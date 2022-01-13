/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:49:41 by jtaravel          #+#    #+#             */
/*   Updated: 2022/01/13 14:32:25 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_flags	ft_init_flags_struct(void)
{
	t_flags	flags;

	flags.conv = 0;
	flags.width = 0;
	flags.plus = 0;
	flags.justify = 0;
	flags.space = 0;
	flags.zero = 0;
	flags.sharp = 0;
	flags.dot = 0;
	flags.preci = 0;
	flags.numbers = 0;
	return (flags);
}

int	ft_fill_struct(va_list argv, t_flags flags, char *s)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == '%')
		{
			flags = ft_init_flags_struct();
			flags = ft_parse(s, flags, i + 1);
			count += ft_conv(flags.conv, argv, flags);
			i += flags.numbers;
		}
		else
		{
			count += ft_putchar_count(s[i]);
			i++;
		}
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		return_len;
	va_list	argv;
	t_flags	flags;

	flags = ft_init_flags_struct();
	va_start(argv, format);
	return_len = ft_fill_struct(argv, flags, (char *)format);
	va_end(argv);
	return (return_len);
}
