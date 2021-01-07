/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsanz-sz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 18:14:29 by gsanz-sz          #+#    #+#             */
/*   Updated: 2020/01/31 01:56:39 by gsanz-sz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *pointer;

	pointer = NULL;
	while (*s)
	{
		if (*s == c)
			pointer = (char*)s;
		s++;
	}
	if (c == '\0')
		return ((char*)s);
	return (pointer);
}
