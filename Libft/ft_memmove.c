/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsanz-sz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 00:38:01 by gsanz-sz          #+#    #+#             */
/*   Updated: 2020/01/31 01:23:48 by gsanz-sz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	i;
	unsigned char	*dstc;
	unsigned char	*srcc;

	dstc = (unsigned char*)dst;
	srcc = (unsigned char*)src;
	i = 1;
	if (dstc > srcc)
		while (i <= len && dstc != srcc)
		{
			dstc[len - i] = srcc[len - i];
			i++;
		}
	else
		ft_memcpy(dst, src, len);
	return (dstc);
}
