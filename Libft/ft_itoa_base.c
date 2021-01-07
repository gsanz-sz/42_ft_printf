/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsanz-sz </var/mail/gsanz-sz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 02:29:43 by gsanz-sz          #+#    #+#             */
/*   Updated: 2021/01/07 02:36:29 by gsanz-sz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_base(size_t nbr, int base, int count, char *str)
{
	while (nbr != 0)
	{
		if ((nbr % base) < 10)
			str[count - 1] = (nbr % base) + 48;
		else
			str[count - 1] = (nbr % base) + 55;
		nbr /= base;
		count--;
	}
	return (str);
}

char		*ft_itoa_base(size_t nbr, int base)
{
	size_t	tmp;
	int		count;
	char	*str;

	tmp = nbr;
	count = 0;
	str = 0;
	if (nbr == 0)
		return (ft_strdup("0"));
	while (nbr != 0)
	{
		nbr /= base;
		count++;
	}
	if (!(str = malloc(count + 1)))
		return (0);
	str[count] = '\0';
	str = ft_base(tmp, base, count, str);
	return (str);
}
