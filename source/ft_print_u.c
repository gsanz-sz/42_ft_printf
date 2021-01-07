/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsanz-sz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:07:24 by gsanz-sz          #+#    #+#             */
/*   Updated: 2021/01/07 13:06:50 by gsanz-sz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_width_u(char *str, t_flags flags)
{
	int		count;

	count = 0;
	if (flags.dot >= 0)
		count += ft_print_width(flags.dot - 1, ft_strlen(str) - 1, 1);
	count += ft_putlstr(str, ft_strlen(str));
	return (count);
}

static int	ft_print_flags_u(char *str, t_flags flags)
{
	int		count;

	count = 0;
	if (flags.minus == 1)
		count += ft_width_u(str, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		count += ft_print_width(flags.width, 0, 0);
	}
	else
		count += ft_print_width(flags.width, ft_strlen(str), flags.zero);
	if (flags.minus == 0)
		count += ft_width_u(str, flags);
	return (count);
}

int			print_u(unsigned int num, t_flags flags)
{
	int		count;
	char	*str;

	count = 0;
	num = (unsigned int)(4294967295 + 1 + num);
	if (flags.dot == 0 && num == 0)
	{
		count += ft_print_width(flags.width, 0, 0);
		return (count);
	}
	str = ft_itoa_u(num);
	count = ft_print_flags_u(str, flags);
	free(str);
	return (count);
}
