/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsanz-sz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 19:06:33 by gsanz-sz          #+#    #+#             */
/*   Updated: 2020/01/31 01:55:25 by gsanz-sz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	lensrc;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	lensrc = ft_strlen(src);
	while (dst[i] && i < dstsize)
		i++;
	j = i;
	while (src[i - j] && (i + 1) < dstsize)
	{
		dst[i] = src[i - j];
		i++;
	}
	if (j < dstsize)
		dst[i] = '\0';
	return (j + lensrc);
}
