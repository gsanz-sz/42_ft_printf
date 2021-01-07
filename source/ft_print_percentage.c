/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percentage.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsanz-sz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:21:37 by gsanz-sz          #+#    #+#             */
/*   Updated: 2021/01/07 12:38:26 by gsanz-sz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_percentage(t_flags flags)
{
	int	count;

	count = 0;
	if (flags.minus == 1)
		count += ft_putlstr("%", 1);
	count += ft_print_width(flags.width, 1, flags.zero);
	if (flags.minus == 0)
		count += ft_putlstr("%", 1);
	return (count);
}
