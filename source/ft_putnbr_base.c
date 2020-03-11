/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsanz-sz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 06:58:51 by gsanz-sz          #+#    #+#             */
/*   Updated: 2020/03/10 21:19:44 by gsanz-sz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdint.h>

int	count_base(char *base)
{
	int cont;

	cont = 0;
	while (base[cont])
		cont++;
	return (cont);
}

int	t_base(intmax_t nbr, char *base, unsigned int cont)
{
	uintmax_t	n;
	uintmax_t	mod;

	if (nbr < 0)
	{
		write(1, "-", 1);
		n = nbr * (-1);
	}
	else
		n = nbr;
	if (n >= cont)
		return (t_base(n / cont, base, cont) + write(1, &base[n % cont], 1));
	mod = n % cont;
	return (write(1, &base[mod], 1));
}

int	ver_base(char *base)
{
	int	cont;
	int	i;

	cont = 0;
	while (base[cont])
	{
		i = 0;
		if (base[cont] == '-' || base[cont] == '+')
			while (base[i])
			{
				if (base[cont] == base[i])
					return (0);
				i++;
			}
		cont++;
	}
	if (cont <= 1)
		return (0);
	return (1);
}

int	ft_putnbr_base(intmax_t nbr, char *base)
{
	int				len;
	unsigned int	cont;

	len = 0;
	if (ver_base(base))
	{
		cont = count_base(base);
		len = t_base(nbr, base, cont);
	}
	return (len);
}
