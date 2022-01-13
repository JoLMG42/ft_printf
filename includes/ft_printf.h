/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:54:04 by jtaravel          #+#    #+#             */
/*   Updated: 2021/12/06 15:54:06 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

/* -- Flags Struct -- */

typedef struct n_list
{
	char	conv;
	int		width;
	char	plus;
	char	justify;
	char	space;
	char	zero;
	char	sharp;
	char	dot;
	int		preci;
	int		numbers;

}t_flags;
int		ft_printf(const char *format, ...);
t_flags	ft_parse(char *s, t_flags flags, int i);
t_flags	ft_parse2(char c, t_flags flags);
t_flags	ft_parse_width(char *s, int i, t_flags flags);
t_flags	ft_parse_dot(char *s, int i, t_flags flags);
t_flags	ft_parse_width(char *s, int i, t_flags flags);
t_flags	ft_parse_dot(char *s, int i, t_flags flags);

/* -- Checks -- */

int		ft_check_x(va_list argv, t_flags flags);
int		ft_check_di(va_list argv, t_flags flags);
int		ft_check_c(va_list argv, t_flags flags);
int		ft_check_p(va_list argv, t_flags flags);
int		ft_check_s(va_list argv, t_flags flags);
int		ft_check_u(va_list argv, t_flags flags);
int		ft_check_pr(va_list argv, t_flags flags);
int		str_check(va_list argv, char *s);
int		ft_print_width_c(char c, char j, int nb);
int		ft_fill_struct(va_list argv, t_flags flags, char *s);

/* -- Tools -- */

int		ft_conv(char c, va_list argv, t_flags flags);

int		ft_putnbr_count(long long int nb, int i);
int		ft_putchar_count(int c);
int		ft_putstr_count(char *s);

int		ft_unsigned_putnbr_count(unsigned int n, int i);
int		ft_unsigned_putnbr_len(unsigned int n, int i);

int		ft_unsigned_putnbr_exa_count(unsigned int num, char c, int i);
int		ft_unsigned_putnbr_exa_len(unsigned int num, char c, int i);

int		ft_print_addr_count(size_t num);
int		ft_len_addr(size_t num);

/* ---- Bonus Part ---- */

int		ft_print_width_c(char c, char j, int nb);
/* DI */
int		ft_flag_dot_di(int nb, t_flags flags, int len, int count);
int		ft_flag_dot_di2(t_flags flags, int nb, int len, int count);
int		ft_flag_dot_di_neg(int nb, t_flags flags, int len, int count);
int		ft_flag_plus_di(int nb, t_flags flags, int len, int count);
int		ft_flag_zero_di(int nb, t_flags flags, int len, int count);
int		ft_flag_width_di(int nb, t_flags flags, int len, int count);
/* S */
int		ft_flag_dot_s(char *s, t_flags flags, int count);
int		ft_flag_width_s(char *s, t_flags flags, int count);
/* C */
/* U */
int		ft_flag_dot_u(unsigned int nb, t_flags flags, int len, int count);
int		ft_flag_width_u(unsigned int nb, t_flags flags, int len, int count);
/* x */
int		ft_flag_dot_x(unsigned int nb, t_flags flags, int len, int count);
int		ft_flag_zero_x(unsigned int nb, t_flags flags, int len, int count);
int		ft_flag_width_x(unsigned int nb, t_flags flags, int len, int count);
int		ft_flag_sharp_x(unsigned int nb, t_flags flags, int len, int count);

t_flags	ft_parse(char *s, t_flags flags, int i);
t_flags	ft_parse2(char c, t_flags flags);
t_flags	ft_parse_width(char *s, int i, t_flags flags);
t_flags	ft_parse_dot(char *s, int i, t_flags flags);
t_flags	ft_parse_width(char *s, int i, t_flags flags);
t_flags	ft_parse_dot(char *s, int i, t_flags flags);
#endif
