/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsanz-sz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 00:11:05 by gsanz-sz          #+#    #+#             */
/*   Updated: 2020/01/31 00:37:34 by gsanz-sz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*dstc;
	unsigned char	*srcc;
	unsigned char	cc;

	if (!dst && !src)
		return (NULL);
	i = 0;
	dstc = (unsigned char*)dst;
	srcc = (unsigned char*)src;
	cc = (unsigned char)c;
	while (i < n)
	{
		dstc[i] = srcc[i];
		if (srcc[i] == cc)
			return (&(dstc[i + 1]));
		i++;
	}
	return (NULL);
}
