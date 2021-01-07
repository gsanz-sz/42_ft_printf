/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsanz-sz <gsanz-sz@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 13:33:57 by gsanz-sz          #+#    #+#             */
/*   Updated: 2021/01/07 13:34:00 by gsanz-sz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putlstr(char *str, int len)
{
	int i;

	i = 0;
	while (str[i] != '\0' && i < len)
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}
