/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsanz-sz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:34:57 by gsanz-sz          #+#    #+#             */
/*   Updated: 2020/03/03 21:20:48 by gsanz-sz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	tratamento_conversao(int arg, va_list ap)
{
	int val;

	if (arg == 'c')
		val = print_c(va_args(ap, int));
	else if (arg == 's')
		val = print_s(va_args(ap, char*));
	else if (arg == 'p')
		val = print_p(va_args(ap, void*)); //uintptr_t #include <stdint.h>
	else if (arg == 'd' || line == 'i')
		val = print_d(va_args(ap, int));
	else if (arg == 'u')
		val = print_u(va_args(ap, unsigned int));
	else if (arg == 'x')
		val = print_x(va_args(ap, unsigned int),'x'); //ft_itoahexa(); PRINTAR UNSIGNED HEXA INT - MUDAR VARIAVEL
	else if (arg == 'X')
		val = print_x(va_args(ap, unsigned int),'X'); //ft_strupcase(ft_itoahexa()); PRINTAR UNSIGNED HEXA INT - MUDAR VARIAVEL
	return (val);
}

int		ft_printf(const char *format, ...)
{
	va_list ap;
	int	val;
	int soma;

	val = 0;
	va_start(ap, format);
	while (format[val])
	{
		if (format[val] != '%' && format[val])
			write(1, format[val], 1);
		else if (format[val] == '%' && format[val + 1])
			soma = tratamento_conversao(format[val + 1], ap);
		val++;
	}
	va_end(ap);
	return (val + soma)
}
