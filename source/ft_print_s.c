/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsanz-sz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:00:52 by gsanz-sz          #+#    #+#             */
/*   Updated: 2021/01/07 12:38:34 by gsanz-sz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_width_s(char *c, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.dot >= 0)
	{
		count += ft_print_width(flags.dot, ft_strlen(c), 0);
		count += ft_putlstr(c, flags.dot);
	}
	else
		count += ft_putlstr(c, ft_strlen(c));
	return (count);
}

int			print_s(char *c, t_flags flags)
{
	int	count;

	count = 0;
	if (!c)
		c = ("(null)");
	if (flags.dot >= 0 && (size_t)flags.dot > ft_strlen(c))
		flags.dot = ft_strlen(c);
	if (flags.minus == 1)
		count += ft_width_s(c, flags);
	if (flags.dot >= 0)
		count += ft_print_width(flags.width, flags.dot, 0);
	else
		count += ft_print_width(flags.width, ft_strlen(c), flags.zero);
	if (flags.minus == 0)
		count += ft_width_s(c, flags);
	return (count);
}
