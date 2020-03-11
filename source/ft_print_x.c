/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsanz-sz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:07:56 by gsanz-sz          #+#    #+#             */
/*   Updated: 2020/03/10 21:40:11 by gsanz-sz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libftprintf.h"

int print_x(unsigned int num, char type)
{
	int cont;

	cont = 0;
	if (type == 'X')
		cont += ft_putnbr_base(num, "0123456789ABCDEF");
	else if (type == 'x')
		cont += ft_putnbr_base(num, "0123456789abcdef");
	return (cont);
}
