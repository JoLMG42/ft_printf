/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:52:51 by jtaravel          #+#    #+#             */
/*   Updated: 2021/12/06 15:52:53 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_len_addr(size_t num)
{
	char	str[255];
	int		i;
	int		count;

	if ((void *)num == NULL)
		return (3);
	i = 0;
	count = 0;
	while (num > 0)
	{
		str[i] = ("0123456789abcdef"[num % 16]);
		num = num / 16;
		i++;
		count++;
	}
	str[i] = 0;
	return (count + 2);
}

int	ft_print_addr_count(size_t num)
{
	char	str[255];
	int		i;
	int		count;

	if ((void *)num == NULL)
		return (ft_putstr_count("0x0"));
	i = 0;
	count = 0;
	while (num > 0)
	{
		str[i] = ("0123456789abcdef"[num % 16]);
		num = num / 16;
		i++;
		count++;
	}
	str[i] = 0;
	write(1, "0x", 2);
	while (--i >= 0)
	{
		write(1, &str[i], 1);
	}
	return (count + 2);
}
