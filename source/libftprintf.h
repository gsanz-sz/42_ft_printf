/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsanz-sz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 21:32:11 by gsanz-sz          #+#    #+#             */
/*   Updated: 2021/01/07 03:41:27 by gsanz-sz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>
# include "../Libft/libft.h"

typedef struct  s_flags
{
	int minus;
	int zero;
	int dot;
	int	star;
	int	type;
	int width;
}t_flags;
t_flags			width_flags(va_list ap, t_flags flags);
int				dot_flags(const char *str, int start, va_list ap, t_flags *flags);
t_flags			minus_flags(t_flags flags);
t_flags			isdigit_flags(char c, t_flags flags);
int				print_c(char c, t_flags flags);
int				print_d(int i, t_flags flags);
int				print_p(size_t num, t_flags flags);
int				print_percentage(t_flags flags);
int				print_s(char *c, t_flags flags);
int				print_u(unsigned int num, t_flags flags);
int				ft_print_width(int width, int minus, int zero);
int				print_x(unsigned int num, int lowcase, t_flags flags);
int				ft_putnbr_base(intmax_t nbr, char *base);
int				conversor_parse(int c, va_list ap, t_flags flags);
int				pick_args(char *str, va_list ap);
int				ft_printf(const char *format, ...);
int				ft_isconversion(int c);
int				ft_isflag(int c);

#endif
