/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsanz-sz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 17:59:05 by gsanz-sz          #+#    #+#             */
/*   Updated: 2021/01/07 12:38:10 by gsanz-sz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		print_c(char c, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.width == 1)
		ft_putchar(c);
	else if (flags.minus == 1)
	{
		ft_putchar(c);
		count = ft_print_width(flags.width, 1, 0);
	}
	else if (flags.minus == 0)
	{
		count = ft_print_width(flags.width, 1, 0);
		ft_putchar(c);
	}
	count++;
	return (count);
}
