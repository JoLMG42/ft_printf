/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:52:38 by jtaravel          #+#    #+#             */
/*   Updated: 2021/12/06 15:52:41 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_unsigned_putnbr_exa_count(unsigned int num, char c, int i)
{
	unsigned int	nb;
	char			*hex;

	nb = num;
	if (c == 'X')
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (nb >= 16)
	{
		i = ft_unsigned_putnbr_exa_count(nb / 16, c, i);
		i += ft_putchar_count(hex[nb % 16]);
	}
	else
		i += ft_putchar_count(hex[nb]);
	return (i);
}

int	ft_unsigned_putnbr_exa_len(unsigned int num, char c, int i)
{
	unsigned int	nb;
	char			*hex;

	nb = num;
	if (c == 'X')
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (nb >= 16)
	{
		i = ft_unsigned_putnbr_exa_len(nb / 16, c, i);
		i++;
	}
	else
		i++;
	return (i);
}
