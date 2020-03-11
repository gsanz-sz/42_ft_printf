/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsanz-sz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:34:57 by gsanz-sz          #+#    #+#             */
/*   Updated: 2020/03/10 22:05:14 by gsanz-sz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	tratamento_conversao(int arg, va_list ap)
{
	int val;

	val = 0;
	if (arg == 'c')
		val = print_c(va_arg(ap, int));
	else if (arg == 's')
		val = print_s(va_arg(ap, char*));
	else if (arg == 'p')
		val = print_p(va_arg(ap, void*));
	else if (arg == 'd' || arg == 'i')
		val = print_d(va_arg(ap, int));
	else if (arg == 'u')
		val = print_u(va_arg(ap, unsigned int));
	else if (arg == 'x')
		val = print_x(va_arg(ap, unsigned int),'x');
	else if (arg == 'X')
		val = print_x(va_arg(ap, unsigned int),'X');
	else if (arg == '%')
		val = print_percentage(arg);
	return (val);
}

int		ft_printf(const char *format, ...)
{
	va_list ap;
	int	val;
	int soma;

	val = 0;
	soma = 0;
	va_start(ap, format);
	while (format[val])
	{
		if (format[val] != '%' && format[val])
			write(1, &(format[val]), 1);
		else if (format[val] == '%' && format[val + 1])
			soma += tratamento_conversao(format[val + 1], ap);
		val++;
	}
	va_end(ap);
	return (val + soma);
}
