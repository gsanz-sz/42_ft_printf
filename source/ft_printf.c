/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsanz-sz <gsanz-sz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:34:57 by gsanz-sz          #+#    #+#             */
/*   Updated: 2021/01/07 13:22:43 by gsanz-sz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static t_flags	initiate_flags(void)
{
	t_flags	flags;

	flags.minus = 0;
	flags.zero = 0;
	flags.dot = -1;
	flags.star = 0;
	flags.type = 0;
	flags.width = 0;
	return (flags);
}

int				conversor_parse(int c, va_list ap, t_flags flags)
{
	int count;

	count = 0;
	if (c == 'c')
		count += print_c(va_arg(ap, int), flags);
	else if (c == 's')
		count += print_s(va_arg(ap, char *), flags);
	else if (c == 'p')
		count += print_p(va_arg(ap, size_t), flags);
	else if (c == 'd' || c == 'i')
		count += print_d(va_arg(ap, int), flags);
	else if (c == 'u')
		count += print_u(va_arg(ap, unsigned int), flags);
	else if (c == 'x')
		count += print_x(va_arg(ap, unsigned int), 1, flags);
	else if (c == 'X')
		count += print_x(va_arg(ap, unsigned int), 0, flags);
	else if (c == '%')
		count += print_percentage(flags);
	return (count);
}

static int		check_print(const char *str, int i, t_flags *flags,
		va_list ap)
{
	while (str[i])
	{
		if (!ft_isconversion(str[i]) && !ft_isflag(str[i])
				&& !ft_isdigit(str[i]))
			break ;
		if (str[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (str[i] == '*')
			*flags = width_flags(ap, *flags);
		if (str[i] == '.')
			i = dot_flags(str, i, ap, flags);
		if (str[i] == '-')
			*flags = minus_flags(*flags);
		if (ft_isdigit(str[i]))
			*flags = isdigit_flags(str[i], *flags);
		if (ft_isconversion(str[i]))
		{
			flags->type = str[i];
			break ;
		}
		i++;
	}
	return (i);
}

int				pick_args(char *str, va_list ap)
{
	t_flags	flags;
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != '%')
			count += ft_putchar(str[i]);
		else if (str[i] == '%' && str[i + 1])
		{
			flags = initiate_flags();
			i = check_print(str, ++i, &flags, ap);
			if (ft_isconversion(str[i]))
				count += conversor_parse((char)flags.type, ap, flags);
			else if (str[i])
				count += ft_putchar(str[i]);
		}
		i++;
	}
	return (count);
}

int				ft_printf(const char *format, ...)
{
	va_list	ap;
	int		val;
	char	*str;

	val = 0;
	if (!(str = ft_strdup(format)))
		return (0);
	va_start(ap, format);
	val += pick_args(str, ap);
	va_end(ap);
	free((char *)str);
	return (val);
}
