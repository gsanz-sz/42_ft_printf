/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsanz-sz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:23:23 by gsanz-sz          #+#    #+#             */
/*   Updated: 2020/02/07 00:20:36 by gsanz-sz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordlen(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static size_t	ft_countwords(char const *s, char c)
{
	int		res;
	int		i;

	i = 0;
	res = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		while (s[i] && s[i] != c)
			i++;
		res++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (res);
}

static char		*next_word(char const *s, char c)
{
	while (*s && *s == c)
		s++;
	return ((char*)s);
}

char			**ft_split(char const *s, char c)
{
	char	**split;
	size_t	cur;
	size_t	words;

	if (s != NULL)
	{
		words = ft_countwords(s, c);
		split = (char**)malloc(sizeof(char*) * (words + 1));
		if (!split)
			return (NULL);
		cur = 0;
		while (cur < words)
		{
			s = next_word(s, c);
			split[cur] = ft_substr(s, 0, ft_wordlen(s, c));
			if (!split[cur])
				return (NULL);
			cur++;
			s += ft_wordlen(s, c);
		}
		split[words] = NULL;
		return (split);
	}
	return (NULL);
}
