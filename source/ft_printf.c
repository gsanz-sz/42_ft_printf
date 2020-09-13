/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsanz-sz <gsanz-sz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:34:57 by gsanz-sz          #+#    #+#             */
/*   Updated: 2020/09/12 23:14:56 by gsanz-sz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

int	conversor_parse(int arg, va_list ap)
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
	return (val);}

int	pick_args(char *str, va_list ap)
{
	t_flags	flag;
	int	i;
	int soma;
	
	i = 0;
	soma = 0;
	while (str[i])
	{
		if (str[i] != '%' && str[i])
		{
			write(1, &(str[i]), 1);
			soma += 1;
		}
		else if (str[i] == '%')
		{
			flag = initiate_flags();
			i++;
			while (ft_strchr("0-*."str[i]))
			{
				is_flag(str, i, flag, ap);	
				i++;
			}
			if (ft_strchr("cspdiuxX%", str[i]))
				soma += conversor_parse(str[i], ap);
			i++;
		}
		i++;
	}
	return (soma);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		val;
	char 	*str;
	if (!(str = ft_strdup(format)))
		return (0);
	va_start(ap, format);
	val = pick_args(str, ap);
	va_end(ap);
	free((char*)str);
	return (val);
}
