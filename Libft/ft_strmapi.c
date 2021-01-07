/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsanz-sz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 16:59:33 by gsanz-sz          #+#    #+#             */
/*   Updated: 2020/02/12 14:42:37 by gsanz-sz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*cpystring(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	*allocmemory(size_t size)
{
	void	*res;

	if (!(res = malloc(size)))
		return (NULL);
	ft_bzero(res, size);
	return (res);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	if (s != NULL)
	{
		i = 0;
		str = allocmemory(ft_strlen(s) + 1);
		if (!str)
			return (NULL);
		cpystring(str, s);
		while (str[i])
		{
			str[i] = (*f)(i, str[i]);
			i++;
		}
		return (str);
	}
	return (NULL);
}
