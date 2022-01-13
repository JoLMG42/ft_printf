/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:17:51 by jtaravel          #+#    #+#             */
/*   Updated: 2022/01/13 14:32:16 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_flags	ft_parse_dot(char *s, int i, t_flags flags)
{
	int	pr;

	pr = 0;
	if (s[i] == '.')
	{
		flags.dot = '.';
		pr = 0;
		while (s[i + 1] >= '0' && s[i + 1] <= '9')
		{
			pr = pr * 10 + s[i + 1] - '0';
			flags.preci = pr;
			i++;
			flags.numbers += 1;
		}
	}
	return (flags);
}

t_flags	ft_parse_width(char *s, int i, t_flags flags)
{
	int	nb;

	nb = 0;
	if (s[i] >= '1' && s[i] <= '9')
	{
		while (s[i] >= '0' && s[i] <= '9')
		{
			nb = nb * 10 + (s[i] - '0');
			flags.width = nb;
			i++;
			flags.numbers += 1;
		}
		flags.numbers += -1;
	}
	return (flags);
}

t_flags	ft_parse2(char c, t_flags flags)
{
	if (c == '0')
		flags.zero = '0';
	else if (c == '-')
		flags.justify = '-';
	else if (c == '#')
		flags.sharp = '#';
	else if (c == ' ')
		flags.space = ' ';
	else if (c == '+')
		flags.plus = '+';
	return (flags);
}

t_flags	ft_parse(char *s, t_flags flags, int i)
{
	flags.numbers = 1;
	while (ft_strchr("cspdiuxX%", s[i]) == NULL)
	{
		if (ft_strchr("0-# +", s[i]))
			flags = ft_parse2(s[i], flags);
		else if (s[i] == '.')
		{
			flags = ft_parse_dot(s, i, flags);
			while (s[i + 1] >= '0' && s[i + 1] <= '9')
				i++;
		}
		else if (s[i] >= '1' && s[i] <= '9' && flags.width == 0)
		{
			flags = ft_parse_width(s, i, flags);
			while (s[i] >= '0' && s[i] <= '9')
				i++;
			i--;
		}
		i++;
		flags.numbers += 1;
	}
	flags.conv = s[i];
	flags.numbers += 1;
	return (flags);
}
