/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:52:59 by jtaravel          #+#    #+#             */
/*   Updated: 2022/01/05 18:40:37 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putnbr_count(long long int n, int i)
{
	unsigned int	nb;

	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		i++;
		nb = n * -1;
	}
	else
		nb = n;
	if (nb > 9)
	{
		i = ft_putnbr_count(nb / 10, i);
		i = ft_putnbr_count(nb % 10, i);
	}
	else
		i += ft_putchar_count(nb + '0');
	return (i);
}

int	ft_putchar_count(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_putstr_count(char *s)
{
	if (!s)
		return (ft_putstr_count("(null)"));
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}

int	ft_unsigned_putnbr_len(unsigned int n, int i)
{
	if (n > 9)
	{
		i = ft_unsigned_putnbr_len(n / 10, i);
		i = ft_unsigned_putnbr_len(n % 10, i);
	}
	else
		i++;
	return (i);
}

int	ft_unsigned_putnbr_count(unsigned int n, int i)
{
	if (n > 9)
	{
		i = ft_unsigned_putnbr_count(n / 10, i);
		i = ft_unsigned_putnbr_count(n % 10, i);
	}
	else
		i += ft_putchar_count(n + '0');
	return (i);
}
