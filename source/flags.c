/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   by: gsanz-sz </var/mail/gsanz-sz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2020/09/12 22:57:49 by gsanz-sz          #+#    #+#             */
/*   Updated: 2020/09/13 01:11:49 by gsanz-sz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_flag	initiate_flags(void)
{   
	    flag.minus = 0;
		flag.zero = 0;
		flag.dot = 0;
		flag.width = 0;

		return (t_flag);
}

void	is_flag(char *str, int i, t_flag *flag, va_args ap)
{
	while (str[i])
	{
		if (ft_strchr("0-.*123456789",str[i]))
			break;
		if (str[i] == '-')
		{
			flag->minus = 1;
		}
		if (str[i] == '0' && flag->minus == 0)
		{
			flag->zero = 1;
		}
		if (str[i] == '.')
		{
			dot_flag();
		}
		if (str[i] == '*')
		{
			star_flag();
		}
		i++;
	}
}
