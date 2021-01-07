/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsanz-sz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 16:02:20 by gsanz-sz          #+#    #+#             */
/*   Updated: 2020/02/03 16:32:15 by gsanz-sz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*dst;
	unsigned int	i;

	dst = (unsigned char*)malloc(count * size);
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		dst[i] = 0;
		i++;
	}
	return (dst);
}
