/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsanz-sz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:06:42 by gsanz-sz          #+#    #+#             */
/*   Updated: 2021/01/07 13:09:52 by gsanz-sz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_width_di(char *str, int num, t_flags flags)
{
	int		count;

	count = 0;
	if (flags.dot >= 0 && num < 0 && num != -2147483648)
		ft_putchar('-');
	if (flags.dot >= 0)
		count += ft_print_width(flags.dot - 1, ft_strlen(str) - 1, 1);
	count += ft_putlstr(str, ft_strlen(str));
	return (count);
}

static int	ft_print_int(char *str, int num, t_flags flags)
{
	int		count;

	count = 0;
	if (flags.minus == 1)
		count += ft_width_di(str, num, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		count += ft_print_width(flags.width, 0, 0);
	}
	else if (flags.zero == 1)
		count += ft_print_width(flags.width, ft_strlen(str), 1);
	else
		count += ft_print_width(flags.width, ft_strlen(str), 0);
	if (flags.minus == 0)
		count += ft_width_di(str, num, flags);
	return (count);
}

int			print_d(int i, t_flags flags)
{
	int		count;
	char	*str;
	int		num;

	count = 0;
	num = i;
	if (flags.dot == 0 && i == 0)
	{
		count = ft_print_width(flags.width, 0, 0);
		return (count);
	}
	if (i < 0 && (flags.dot >= 0 || flags.zero == 1) && num != -2147483648)
	{
		if (flags.dot < 0 && flags.zero == 1)
			ft_putlstr("-", 1);
		i *= -1;
		flags.zero = 1;
		flags.width--;
		count++;
	}
	str = ft_itoa(i);
	count += ft_print_int(str, num, flags);
	free(str);
	return (count);
}
