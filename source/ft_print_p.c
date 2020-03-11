/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsanz-sz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:06:12 by gsanz-sz          #+#    #+#             */
/*   Updated: 2020/03/10 21:38:36 by gsanz-sz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <unistd.h>
#include "libftprintf.h"

int	print_p(void *p)
{
	int cont;

	cont = 0;
	cont += write(1, "0x", 2);
	cont += ft_putnbr_base((intmax_t)p,"0123456789abcdef");
	return (cont);
}
