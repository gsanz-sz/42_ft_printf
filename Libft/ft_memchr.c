/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsanz-sz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 01:23:59 by gsanz-sz          #+#    #+#             */
/*   Updated: 2020/01/31 01:28:33 by gsanz-sz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*res;
	unsigned char	x;

	i = 0;
	res = (unsigned char*)s;
	x = (unsigned char)c;
	while (i < n)
	{
		if (res[i] == x)
			return (&res[i]);
		i++;
	}
	return (NULL);
}
