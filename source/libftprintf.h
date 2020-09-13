/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsanz-sz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 21:32:11 by gsanz-sz          #+#    #+#             */
/*   Updated: 2020/09/12 23:54:24 by gsanz-sz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <unistd.h>
#include <stdint.h>
#include <stdarg.h>
#include "../Libft/libft.h"

typedef struct  s_flags
{
	int minus = 0;
	int zero = 0;
	int dot = 0;
	int width = 0;
}t_flags;
void	initiate_flags(t_flag *flag);
int	ft_printf(const char *format, ...);
int print_c(char c);
int print_d(int num);
int	print_p(void *p);
int	print_percentage(int c);
int print_s(char *str);
int print_u(unsigned int num);
int print_x(unsigned int num, char type);
int	ft_putnbr_base(intmax_t nbr, char *base);

#endif
