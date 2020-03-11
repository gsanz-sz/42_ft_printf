/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsanz-sz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:06:42 by gsanz-sz          #+#    #+#             */
/*   Updated: 2020/03/10 21:38:27 by gsanz-sz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int print_d(int num)
{
	unsigned int	nbr;
	int				len;

	len = 0;
	ft_putnbr_fd(num, STDOUT_FILENO);
	if (num < 0)
	{
		len = 1;
		nbr = num * (-1);
	}
	else
		nbr = num;
	while (nbr > 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}
