/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   by: gsanz-sz </var/mail/gsanz-sz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2020/09/12 22:57:49 by gsanz-sz          #+#    #+#             */
/*   Updated: 2021/01/07 03:34:12 by gsanz-sz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_flags			width_flags(va_list ap, t_flags flags)
{
	flags.star = 1;
	flags.width = va_arg(ap, int);
	while (flags.width < 0)
	{
		flags.minus = 1;
		flags.width *= -1;
		flags.zero = 0;
	}
	return (flags);
}

int				dot_flags(const char *str, int start, va_list ap,
		t_flags *flags)
{
	int		i;

	i = start;
	i++;
	if (str[i] == '*')
	{
		flags->dot = va_arg(ap, int);
		i++;
	}
	else
	{
		flags->dot = 0;
		while (ft_isdigit(str[i]))
		{
			flags->dot = ((flags->dot * 10) + (str[i] - '0'));
			i++;
		}
	}
	return (i);
}

t_flags			minus_flags(t_flags flags)
{
	flags.minus = 1;
	flags.zero = 0;
	return (flags);
}

t_flags			isdigit_flags(char c, t_flags flags)
{
	if (flags.star == 1)
		flags.width = 0;
	flags.width = ((flags.width * 10) + (c - '0'));

}
