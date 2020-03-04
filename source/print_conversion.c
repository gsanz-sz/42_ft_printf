/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsanz-sz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 20:54:38 by gsanz-sz          #+#    #+#             */
/*   Updated: 2020/03/03 21:21:01 by gsanz-sz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	print_c(char c)
{
	ft_putchr(c);
	return (1);
}

int	print_s(char *str);
{
	ft_putstr(str);
	return(ft_strlen(str));
}

int print_p()
{
}

int	print_d(int num)
{
}

int	print_u(unsigned int num)
{
}

int print_x(unsigned int num,char type)
{
}
