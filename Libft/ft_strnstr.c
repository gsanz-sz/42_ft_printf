/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsanz-sz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 20:26:02 by gsanz-sz          #+#    #+#             */
/*   Updated: 2020/02/05 23:21:56 by gsanz-sz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char			*p;
	unsigned int	i;
	unsigned int	j;

	p = (char*)haystack;
	if (*needle == '\0')
		return (p);
	i = 0;
	while (i < len && p[i] != '\0')
	{
		j = 0;
		while (p[i + j] != '\0' && p[i + j] == needle[j] && (i + j) < len)
		{
			if (needle[j + 1] == '\0')
				return (&(p[i]));
			j++;
		}
		i++;
	}
	return (0);
}
