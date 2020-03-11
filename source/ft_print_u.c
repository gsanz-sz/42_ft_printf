/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsanz-sz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:07:24 by gsanz-sz          #+#    #+#             */
/*   Updated: 2020/03/10 21:39:54 by gsanz-sz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int print_u(unsigned int num)
{
	int	len;

	len = 0;
	ft_putnbr_fd(num, STDOUT_FILENO);
	while (num > 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}
