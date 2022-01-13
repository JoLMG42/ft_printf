/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:52:27 by jtaravel          #+#    #+#             */
/*   Updated: 2021/12/06 15:52:30 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_conv(char c, va_list argv, t_flags flags)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_check_c(argv, flags);
	if (c == 's')
		count = ft_check_s(argv, flags);
	if (c == 'd' || c == 'i')
		count = ft_check_di(argv, flags);
	if (c == 'p')
		count = ft_check_p(argv, flags);
	if (c == 'u')
		count = ft_check_u(argv, flags);
	if (c == 'x' || c == 'X')
		count = ft_check_x(argv, flags);
	if (c == '%')
		count = ft_check_pr(argv, flags);
	return (count);
}
